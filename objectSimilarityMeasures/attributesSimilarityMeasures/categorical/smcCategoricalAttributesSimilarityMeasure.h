#ifndef CLASSICALAHCALGORITHM_SMCCATEGORICALATTRIBUTESSIMILARITYMEASURE_H
#define CLASSICALAHCALGORITHM_SMCCATEGORICALATTRIBUTESSIMILARITYMEASURE_H

#include "../attributesSimilarityMeasure.h"

class smcCategoricalAttributesSimilarityMeasure : public attributesSimilarityMeasure
{
  public:

    double countAttributesSimilarity(string firstAttributeValue, string secondAttributeValue);
};


#endif //CLASSICALAHCALGORITHM_SMCCATEGORICALATTRIBUTESSIMILARITYMEASURE_H
