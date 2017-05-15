/* midifuchs.ino */

#include "Midifuchs_CalculateVelocity.h"
#include "Midifuchs_Midi.h"
#include "Midifuchs_HitDetection.h"

//#define VERBOSE (0)

#define MIDIFUCHS_BAUDRATE_SERIAL (115200)
#define MIDIFUCHS_BAUDRATE_MIDI   (31250)

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  (void)Midifuchs_HitDetection_initialize();

  /* WICHTIG:
    Auf dem Leonardo-Board muss unbedingt "Serial1" genutzt werden, da "Serial" den USB-Port anspricht.
    Das Leonardo-Board besitzt nur einen Chip, auf dem beide Schnittstellen verwaltet werden
  */
  //Serial.begin(31250); // "31250" ist die Baudrate für MIDI!
  
  // Für das Logging!!
  Serial.begin(MIDIFUCHS_BAUDRATE_SERIAL);
  while (!Serial) ; // while the serial stream is not open, do nothing:
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  unsigned int sensorValue = (unsigned int)analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  // float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
#ifdef VERBOSE
  Serial.println("SensorValue " + String(sensorValue));
#endif
  if(1 == Midifuchs_HitDetection_process(sensorValue)) {

    Midifuchs_Midi_NoteOn( MIDIFUCHS_MIDI_NOTE_C4, Midifuchs_CalculateVelocity_calculate(sensorValue));        
    Midifuchs_Midi_NoteOff(MIDIFUCHS_MIDI_NOTE_C4, MIDIFUCHS_MIDI_VELOCITY_OFF);
  }
  delayMicroseconds(MIDIFUCHS_HITDETECTION_DETECTION_SAMPLING_TIME);
}
