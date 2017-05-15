/* component hit detection */

#include <string.h>
#include "Midifuchs_HitDetection.h"

typedef struct {
    unsigned int signal[MIDIFUCHS_HITDETECTION_SIGNAL_BUFFER_SIZE];
    unsigned int wPoint;
    unsigned int rPoint;
    unsigned int hitDetected;
    unsigned int hitPoint;
             int qualificationCounter;
} hitDetection_t;

static hitDetection_t hitDetection;
static int hitDetection_pointerDistance(unsigned int small, unsigned int big, unsigned int wrap);

int Midifuchs_HitDetection_initialize() {
    memset(&hitDetection, 0, sizeof(hitDetection_t));
    return 0;
}

int Midifuchs_HitDetection_process(unsigned int i_analogValue)
{
    int ret = 0;

    hitDetection_t* this = &hitDetection;
  
    this->signal[this->wPoint] = i_analogValue;
    this->wPoint = (this->wPoint + 1);
    if(this->wPoint >= MIDIFUCHS_HITDETECTION_SIGNAL_BUFFER_SIZE) {
        this->wPoint = 0;
    }
    this->rPoint = this->wPoint - 1;

    if(1 == this->hitDetected) {
        if(hitDetection_pointerDistance(this->hitPoint, this->rPoint, MIDIFUCHS_HITDETECTION_SIGNAL_BUFFER_SIZE) >= MIDIFUCHS_HITDETECTION_BLOCK_NUM_SAMPLES) {
            this->hitDetected = 0;
        }
        ret = 0;
    } else {
        if(i_analogValue >= MIDIFUCHS_HITDETECTION_DETECTION_THRESHOLD) {
            (this->qualificationCounter)++;
            if(this->qualificationCounter > MIDIFUCHS_HITDETECTION_QUALIFICATION_THRESHOLD) {
                this->qualificationCounter = MIDIFUCHS_HITDETECTION_QUALIFICATION_THRESHOLD;
                this->hitDetected = 1;
                this->hitPoint = this->rPoint;
                ret = 1;
            } else {
              ret = 0;
            }
        } else {
            (this->qualificationCounter)--;
            if(this->qualificationCounter < 0) {
                this->qualificationCounter = 0;
            }
            this->hitDetected = 0;
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

