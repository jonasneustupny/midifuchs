/*
 * Diese Methode nimmt einen Float-Wert entgegen (zwischen 0.00 - 5.00) und
 * berechnet eine MIDI-Velocity (0 = off; 127 = max).
 * Der berechnete Wert wird zurückgeliefert.
 * 
 * Autor: Jonas Neustupny
 * Datum: 06.05.2017
 */
#include "Midifuchs_CalculateVelocity.h"

unsigned int Midifuchs_CalculateVelocity_calculate(unsigned int voltageValue) {
	unsigned int ret = 0;

	/* limit output to range 0..127 */
	if(voltageValue < MF_CALCULATEVELOCITY_OFFSET_SHIFT) {
		ret = 0;
	} else if (voltageValue < MF_CALCULATEVELOCITY_ADC_MAX) {
		ret = 127 * (voltageValue - MF_CALCULATEVELOCITY_OFFSET_SHIFT);
		ret /= (MF_CALCULATEVELOCITY_ADC_MAX - MF_CALCULATEVELOCITY_OFFSET_SHIFT);
	} else {
		ret = 127;
	}

    return (unsigned int)ret;
}
