#ifndef CLASSICALAHCALGORITHM_OBJECTSSIMILARITYMEASURE_H
#define CLASSICALAHCALGORITHM_OBJECTSSIMILARITYMEASURE_H

#include "../groupingAlgorithm/sample.h"

class objectsSimilarityMeasure
{
  public:

    virtual double countObjectsSimilarity(sample* o1, sample* o2) = 0;

};

#endif //CLASSICALAHCALGORITHM_OBJECTSSIMILARITYMEASURE_H
