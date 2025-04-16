#include <stdlib.h>
#include <math.h>
#include "utils.h"
float sigmoid(float x) 
{
    return 1.0f/(1.0f+expf(-x));
}
float dsigmoid(float y) {
    return y*(1.0f-y);
}
float random_weight() {
    return ((float)rand()/RAND_MAX)*2.0f-1.0f;
}