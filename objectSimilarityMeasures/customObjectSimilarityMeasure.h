#ifndef CLASSICALAHCALGORITHM_CUSTOMOBJECTSIMILARITYMEASURE_H
#define CLASSICALAHCALGORITHM_CUSTOMOBJECTSIMILARITYMEASURE_H

#include <vector>
#include "objectsSimilarityMeasure.h"
#include "../attributesData/attributeData.h"

class customObjectSimilarityMeasure : public objectsSimilarityMeasure
{
  public:
    customObjectSimilarityMeasure(vector<attributeData> *attributesData);
    double countObjectsSimilarity(sample* o1, sample* o2);

  protected:
    vector<attributeData> *attributesData;

};

#endif //CLASSICALAHCALGORITHM_CUSTOMOBJECTSIMILARITYMEASURE_H
