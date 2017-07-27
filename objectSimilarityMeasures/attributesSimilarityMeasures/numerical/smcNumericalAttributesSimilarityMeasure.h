#ifndef CLASSICALAHCALGORITHM_SMCNUMERICALATTRIBUTESSIMILARITYMEASURE_H
#define CLASSICALAHCALGORITHM_SMCNUMERICALATTRIBUTESSIMILARITYMEASURE_H

#include "../attributesSimilarityMeasure.h"

class smcNumericalAttributesSimilarityMeasure : public attributesSimilarityMeasure
{
  public:

    double countAttributesSimilarity(string firstAttributeValue, string secondAttributeValue);

};


#endif //CLASSICALAHCALGORITHM_SMCNUMERICALATTRIBUTESSIMILARITYMEASURE_H
