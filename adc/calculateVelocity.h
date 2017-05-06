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
const int offsetShift = 51;

int calculateVelocity(unsigned int voltageValue) {
  return (127*voltageValue-(127*offsetShift)/(1023-offsetShift));
}
