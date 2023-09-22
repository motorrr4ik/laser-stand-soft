#include "Utils.hpp"
#include "Filters.hpp"

char letter = 'q';

int generatorValueADCRawValue = 0;
int generatortFilteredADCValue = 0;
double generatorPrevVoltageValue = 0.0;
double generatorVoltageValue = 0.0;
int generatorFilterCounter = 0;
int generatorFilterSum = 0;

int diodeADCSignalRawValue = 0;
int diodeADCFilteredSignalValue = 0;
int diodeFilterCounter = 0;
int diodeFilterSum = 0;

int generatorValues[READ_CYCLE_AMOUNT] = {0};
int diodeValues[READ_CYCLE_AMOUNT] = {0};

void setup() {

  pinMode(DIODE_ADC_SIGNAL, INPUT);
  pinMode(GENERATOR_SIGNAL_INPUT, INPUT);

  Serial.begin(115200);
  while(!Serial);

  Serial.println("Hello!");
  Serial.println("Press S to start");

}

void loop() {
  
    if(Serial.available() > 0){
      letter = Serial.read();
      if(letter == 's') Serial.println("Experiment started");
    }

    if (generatortFilteredADCValue < MAXIMUM_GENERATOR_VOLTAGE_VALUE)
    {
      generatorValueADCRawValue = analogRead(GENERATOR_SIGNAL_INPUT);
      generatortFilteredADCValue = Filters::signalMovingAverageFilter(generatorValues, generatorFilterCounter, generatorFilterSum, generatorValueADCRawValue);

      diodeADCSignalRawValue = analogRead(DIODE_ADC_SIGNAL);
      diodeADCFilteredSignalValue = Filters::signalMovingAverageFilter(diodeValues, diodeFilterCounter, diodeFilterSum, diodeADCSignalRawValue);
      
      // generatorVoltageValue = Utils::fromADCToVoltage(generatortFilteredADCValue);

      if(generatortFilteredADCValue - generatorPrevVoltageValue > ADC_GENERATOR_DELTA_STEP){
        Serial.print(generatortFilteredADCValue);
        Serial.print(',');
        Serial.print('\t');
        Serial.println(diodeADCFilteredSignalValue);
        generatorPrevVoltageValue = generatortFilteredADCValue;
      }
    }
}