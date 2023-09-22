#include "Utils.hpp"
#include "Filters.hpp"

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
}

void loop() {
  
    if(Serial.available() > 0){
      diodeADCSignalRawValue = analogRead(DIODE_ADC_SIGNAL);
      diodeADCFilteredSignalValue = Filters::signalMovingAverageFilter(diodeValues, diodeFilterCounter, diodeFilterSum, diodeADCSignalRawValue);
      Serial.println(diodeADCFilteredSignalValue);
      Serial.read();
    }

}