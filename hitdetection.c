/* component hit detection */

#include <string.h>
#include "hitdetection.h"

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

int hitDetection_initialize() {
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
    hitDetection_instance.rPoint = hitDetection_instance.wPoint - 1;

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

