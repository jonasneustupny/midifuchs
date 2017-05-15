#ifndef MIDIFUCHS_MIDI_H_
#define MIDIFUCHS_MIDI_H_

#if defined(__cplusplus)
extern "C" {
#endif

typedef unsigned int Midifuchs_Midi_Velocity_t;

#define MIDIFUCHS_MIDI_VELOCITY_OFF (0U)
#define MIDIFUCHS_MIDI_VELOCITY_MID (80U)
#define MIDIFUCHS_MIDI_VELOCITY_MAX (127U)

typedef int Midifuchs_Midi_Command_t;

#define MIDIFUCHS_MIDI_COMMAND_NOTE_OFF (128U)
#define MIDIFUCHS_MIDI_COMMAND_NOTE_ON  (144U)

typedef int Midifuchs_Midi_Channel_t;

#define MIDIFUCHS_MIDI_CHANNEL_1  (0x0000)
#define MIDIFUCHS_MIDI_CHANNEL_2  (0x0001)
#define MIDIFUCHS_MIDI_CHANNEL_3  (0x0002)
#define MIDIFUCHS_MIDI_CHANNEL_4  (0x0003)
#define MIDIFUCHS_MIDI_CHANNEL_5  (0x0004)
#define MIDIFUCHS_MIDI_CHANNEL_6  (0x0005)
#define MIDIFUCHS_MIDI_CHANNEL_7  (0x0006)
#define MIDIFUCHS_MIDI_CHANNEL_8  (0x0007)
#define MIDIFUCHS_MIDI_CHANNEL_9  (0x0008)
#define MIDIFUCHS_MIDI_CHANNEL_10 (0x0009)
#define MIDIFUCHS_MIDI_CHANNEL_11 (0x000A)
#define MIDIFUCHS_MIDI_CHANNEL_12 (0x000B)
#define MIDIFUCHS_MIDI_CHANNEL_13 (0x000C)
#define MIDIFUCHS_MIDI_CHANNEL_14 (0x000D)
#define MIDIFUCHS_MIDI_CHANNEL_15 (0x000E)
#define MIDIFUCHS_MIDI_CHANNEL_16 (0x000F)

#define MIDIFUCHS_MIDI_ACTIVE_CHANNEL MIDIFUCHS_MIDI_CHANNEL_1

typedef int Midifuchs_Midi_Note_t;

#define MIDIFUCHS_MIDI_NOTE_C4 (48)

void Midifuchs_Midi_NoteOn(Midifuchs_Midi_Note_t midiNote, Midifuchs_Midi_Velocity_t midiVelocity);
void Midifuchs_Midi_NoteOff(Midifuchs_Midi_Note_t midiNote, Midifuchs_Midi_Velocity_t midiVelocity);

#if defined(__cplusplus)
}
#endif

#endif /* MIDIFUCHS_MIDI_H_ */