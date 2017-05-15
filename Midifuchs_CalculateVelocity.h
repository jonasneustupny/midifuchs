/*
 * Diese Methode nimmt einen Float-Wert entgegen (zwischen 0.00 - 5.00) und
 * berechnet eine MIDI-Velocity (0 = off; 127 = max).
 * Der berechnete Wert wird zurückgeliefert.
 * 
 * Autor: Jonas Neustupny
 * Datum: 06.05.2017
 */

/*
 * unsigned int voltageValue: wird ein Wert zwischen 0 (0V) - 1023 (5V) sein
 */
#ifndef MIDIFUCHS_CALCULATEVELOCITY_H_
#define MIDIFUCHS_CALCULATEVELOCITY_H_

#if defined(__cplusplus)
extern "C" {
#endif

#define MF_CALCULATEVELOCITY_OFFSET_SHIFT (51)
#define MF_CALCULATEVELOCITY_ADC_BIT      (10)
#define MF_CALCULATEVELOCITY_ADC_MAX      ((1 << MF_CALCULATEVELOCITY_ADC_BIT) - 1)

unsigned int Midifuchs_CalculateVelocity_calculate(unsigned int voltageValue);

#if defined(__cplusplus)
}
#endif

#endif /* MIDIFUCHS_CALCULATEVELOCITY_H_ */
