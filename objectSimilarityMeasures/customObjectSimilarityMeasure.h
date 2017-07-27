#ifndef CLASSICALAHCALGORITHM_CUSTOMOBJECTSIMILARITYMEASURE_H
#define CLASSICALAHCALGORITHM_CUSTOMOBJECTSIMILARITYMEASURE_H

#include <vector>
#include "objectsSimilarityMeasure.h"
#include "../attributesData/attributeData.h"
#include "attributesSimilarityMeasures/attributesSimilarityMeasure.h"

class customObjectSimilarityMeasure : public objectsSimilarityMeasure
{
  public:
    customObjectSimilarityMeasure(unordered_map<string, attributeData*> *attributesData, attributesSimilarityMeasure* nAttrSimMeasure,
                                  attributesSimilarityMeasure* cAttrSimMeasure);
    double countObjectsSimilarity(sample* o1, sample* o2);

  protected:
    unordered_map<string, attributeData*> *attributesData;
    attributesSimilarityMeasure* nAttributeSimilarityMeasure;
    attributesSimilarityMeasure* cAttributeSimilarityMeasure;

    vector<string> commonAttributes;

    void findCommonAttributes(sample *sample1, sample *sample2);
};

#endif //CLASSICALAHCALGORITHM_CUSTOMOBJECTSIMILARITYMEASURE_H
