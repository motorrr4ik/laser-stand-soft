#include "Utils.hpp"
#include "Filters.hpp"
//--------diode interaction variables--------
int diodeADCSignalRawValue = 0;
int diodeADCFilteredSignalValue = 0;
int diodeFilterCounter = 0;
int diodeFilterSum = 0;
int diodeValues[READ_CYCLE_AMOUNT] = {0};
//--------diode interaction variables--------

void setup() {
  //--------setup pins and serial port--------
  pinMode(DIODE_ADC_SIGNAL, INPUT);
  Serial.begin(SERIAL_PORT_SPEED);
  while(!Serial);
}

void loop() {
    //--------wait signal from main PC, then send data value--------
    diodeADCSignalRawValue = analogRead(DIODE_ADC_SIGNAL);
    diodeADCFilteredSignalValue = Filters::signalMovingAverageFilter(diodeValues, diodeFilterCounter, diodeFilterSum, diodeADCSignalRawValue); //beguschee srednee filter
    if(Serial.available() > 0){
      Serial.println(diodeADCFilteredSignalValue);
      Serial.read();
    }

}