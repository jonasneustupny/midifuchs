/* component hit detection */

#include <string.h>

#define HITDETECTION_DETECTION_THRESHOLD     (250) /* mV */
#define HITDETECTION_DETECTION_TIME_INTERVAL (100) /* mS */
#define HITDETECTION_DETECTION_SAMPLING_TIME (1000) /* uS */
#define HITDETECTION_BLOCK_NUM_SAMPLES       (1000.0 * HITDETECTION_DETECTION_SAMPLING_TIME / HITDETECTION_DETECTION_SAMPLING_TIME)
#define HITDETECTION_SIGNAL_BUFFER_SIZE      (500) /* num of elems */
#define HITDETECTION_QUALIFICATION_THRESHOLD (4) /* num samples */

int hitDetection_initialize(void);

/* The process function takes as an input the voltage of the sensor
   and returns 1 if the signal has been detected as a note or 0 if not. */
int hitDetection_process(unsigned int i_analogValue);

typedef struct {
  unsigned int signal[HITDETECTION_SIGNAL_BUFFER_SIZE];
  unsigned int wPoint;
  unsigned int rPoint;
  unsigned int hitDetected;
  unsigned int hitPoint;
  unsigned int qualificationCounter;
} hitDetection_t;

static hitDetection_t hitDetection_instance;
static int hitDetection_pointerDistance(unsigned int small, unsigned int big, unsigned int wrap);

int hitDetection_initialize(void) {
    memset(&hitDetection_instance, 0, sizeof(hitDetection_t));
    return 0;
}

int hitDetection_process(unsigned int i_analogValue) {
  int ret = 0;

  hitDetection_instance.signal[hitDetection_instance.wPoint] = i_analogValue;
    hitDetection_instance.wPoint = (hitDetection_instance.wPoint + 1);
    if(hitDetection_instance.wPoint >= HITDETECTION_SIGNAL_BUFFER_SIZE) {
      hitDetection_instance.wPoint = 0;
    }
    hitDetection_instance.rPoint = hitDetection_instance.wPoint;

    if(1 == hitDetection_instance.hitDetected) {
      if(hitDetection_pointerDistance(hitDetection_instance.hitPoint, hitDetection_instance.rPoint, HITDETECTION_SIGNAL_BUFFER_SIZE) >= HITDETECTION_BLOCK_NUM_SAMPLES) {
            hitDetection_instance.hitDetected = 0;
      }
      ret = 0;
    } else {
      if(hitDetection_instance.signal[hitDetection_instance.rPoint] >= HITDETECTION_DETECTION_THRESHOLD) {
        (hitDetection_instance.qualificationCounter)++;
        if(hitDetection_instance.qualificationCounter >= HITDETECTION_QUALIFICATION_THRESHOLD) {
                hitDetection_instance.hitDetected = 1;
                hitDetection_instance.hitPoint = hitDetection_instance.rPoint;
                ret = 1;
        } else {
          ret = 0;
        }
        } else {
        (hitDetection_instance.qualificationCounter)--;
        if(hitDetection_instance.qualificationCounter < HITDETECTION_QUALIFICATION_THRESHOLD) {
          hitDetection_instance.hitDetected = 0;
        }
          ret = 0;
        }
    }

  return ret;
}

static int hitDetection_pointerDistance(unsigned int small, unsigned int big, unsigned int wrap) {
    if(big >= small) {
      return big - small;
    } else {
      int i = 0;
      while(small > i * wrap + big) {
        i++;
      }
      return i*wrap + big - small;
    }
}

