#include <EEPROM.h>
#include "hitdetection.h"
#include "hitdetection.c"
#include "calculateVelocity.h"

const int midiCommandNoteOn = 144;
const int noteC4 = 48; // Note C4
const int octave = 12; // 1 Oktave
const int MAX = 127;
const int MIDDLE = 80; // Wird bei Midi als "mittlere" Velocity genutzt.
const int OFF = 0;
const int note = noteC4;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  hitDetection_initialize();

  /* WICHTIG:
    Auf dem Leonardo-Board muss unbedingt "Serial1" genutzt werden, da "Serial" den USB-Port anspricht.
    Das Leonardo-Board besitzt nur einen Chip, auf dem beide Schnittstellen verwaltet werden
  */
  Serial1.begin(31250); // "31250" ist die Baudrate für MIDI!
  
  // Für das Logging!!
  Serial.begin(9600);
  while (!Serial) ; // while the serial stream is not open, do nothing:
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:

  if(hitDetection_process(sensorValue)) {
    noteOn(midiCommandNoteOn, note, calculateVelocity(sensorValue));        
    noteOn(midiCommandNoteOn, note, OFF);
    Serial.println("Sendet MIDI-Note: ");
  }

  Serial.println(sensorValue);
  delayMicroseconds(1000); // 1.5ms
}

void noteOn(int midiCommand, int midiNote, int midiVelocity) {
  //midiVelocity = (midiVelocity < MAX) ? midiVelocity : MAX; // Wenn Velocity über 127, dann auf 127 setzen, damit MIDI-Maxwert nicht überstiegen wird!
  Serial1.write(midiCommand);
  Serial1.write(midiNote);
  Serial1.write(midiVelocity);
}

