/* component hit detection */

#ifndef MIDIFUCHS_HITDETECTION_H_
#define MIDIFUCHS_HITDETECTION_H_

#if defined(__cplusplus)
extern "C" {
#endif

#define MIDIFUCHS_HITDETECTION_DETECTION_THRESHOLD     (250) /* mV */
#define MIDIFUCHS_HITDETECTION_DETECTION_TIME_INTERVAL (100) /* mS */
#define MIDIFUCHS_HITDETECTION_DETECTION_SAMPLING_TIME (1500) /* uS */
#define MIDIFUCHS_HITDETECTION_BLOCK_NUM_SAMPLES       (MIDIFUCHS_HITDETECTION_DETECTION_TIME_INTERVAL * 1000.0 / MIDIFUCHS_HITDETECTION_DETECTION_SAMPLING_TIME)
#define MIDIFUCHS_HITDETECTION_SIGNAL_BUFFER_SIZE      (500) /* num of elems */
#define MIDIFUCHS_HITDETECTION_QUALIFICATION_THRESHOLD (4) /* num samples */

int Midifuchs_HitDetection_initialize();

/* The process function takes as an input the voltage of the sensor
   and returns 1 if the signal has been detected as a note or 0 if not. */
int Midifuchs_HitDetection_process(unsigned int i_analogValue);

#if defined(__cplusplus)
}
#endif

#endif

