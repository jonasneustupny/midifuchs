/* component hit detection */

#ifndef HITDETECTION_H_
#define HITDETECTION_H_

#if defined(__cplusplus)
extern "C" {
#endif

#define HITDETECTION_DETECTION_THRESHOLD     (250) /* mV */
#define HITDETECTION_DETECTION_TIME_INTERVAL (100) /* mS */
#define HITDETECTION_DETECTION_SAMPLING_TIME (1000) /* uS */
#define HITDETECTION_BLOCK_NUM_SAMPLES       (HITDETECTION_DETECTION_TIME_INTERVAL * 1000.0 / HITDETECTION_DETECTION_SAMPLING_TIME)
#define HITDETECTION_SIGNAL_BUFFER_SIZE      (500) /* num of elems */
#define HITDETECTION_QUALIFICATION_THRESHOLD (4) /* num samples */

int hitDetection_initialize();

/* The process function takes as an input the voltage of the sensor
   and returns 1 if the signal has been detected as a note or 0 if not. */
int hitDetection_process(unsigned int i_analogValue);

#if defined(__cplusplus)
}
#endif

#endif

