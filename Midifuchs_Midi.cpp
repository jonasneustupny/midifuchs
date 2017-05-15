/* Midifuchs_Midi.c */

#include <Arduino.h>
#include "Midifuchs_Midi.h"

#if defined(__cplusplus)
extern "C" {
#endif

void Midifuchs_Midi_NoteOn(Midifuchs_Midi_Note_t i_midiNote, Midifuchs_Midi_Velocity_t i_midiVelocity) {
    Midifuchs_Midi_Command_t midiCommand = MIDIFUCHS_MIDI_COMMAND_NOTE_ON | MIDIFUCHS_MIDI_ACTIVE_CHANNEL;
    Serial.println("0x" + String(midiCommand, HEX) + ' ' + String(i_midiNote, DEC) + ' ' + String(i_midiVelocity, DEC) + " (NoteOn)");
}

void Midifuchs_Midi_NoteOff(Midifuchs_Midi_Note_t i_midiNote, Midifuchs_Midi_Velocity_t i_midiVelocity) {
    Midifuchs_Midi_Command_t midiCommand = MIDIFUCHS_MIDI_COMMAND_NOTE_OFF | MIDIFUCHS_MIDI_ACTIVE_CHANNEL;
    Serial.println("0x" + String(midiCommand, HEX) + ' ' + String(i_midiNote, DEC) + ' ' + String(i_midiVelocity, DEC) + "  (NoteOff)");
}

#if defined(__cplusplus)
}
#endif