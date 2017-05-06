/* component hit detection */

#ifndef HITDETECTION_H_
#define HITDETECTION_H_

#define HITDETECTION_DETECTION_THRESHOLD     (250) /* mV */
#define HITDETECTION_DETECTION_TIME_INTERVAL (100) /* mS */
#define HITDETECTION_DETECTION_SAMPLING_TIME (1000) /* uS */
#define HITDECTION_BLOCK_NUM_SAMPLES         (1000.0 * HITDETECTION_DETECTION_SAMPLING_TIME / HITDETECTION_DETECTION_SAMPLING_TIME)
#define HITDETECTION_SIGNAL_BUFFER_SIZE      (500) /* num of elems */
#define HITDECTION_QUALIFICATION_THRESHOLD   (4) /* num samples */

int hitDetection_initialize(void);

/* The process function takes as an input the voltage of the sensor
   and returns 1 if the signal has been detected as a note or 0 if not. */
int hitDetection_process(unsigned int i_analogValue);

#endif

