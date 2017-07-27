#include "customObjectSimilarityMeasure.h"

#include <algorithm>

customObjectSimilarityMeasure::customObjectSimilarityMeasure(unordered_map<string, attributeData*> *attributesData,
                                                             attributesSimilarityMeasure *nAttrSimMeasure,
                                                             attributesSimilarityMeasure *cAttrSimMeasure) :
  attributesData(attributesData), nAttributeSimilarityMeasure(nAttrSimMeasure),
  cAttributeSimilarityMeasure(cAttrSimMeasure)
{}

double customObjectSimilarityMeasure::countObjectsSimilarity(sample *o1, sample *o2)
{
  double result = 0;

  findCommonAttributes(o1, o2);

  for(string attributeName : commonAttributes)
  {
    if(attributesData->at(attributeName)->getType() == "numerical")
      result += nAttributeSimilarityMeasure->countAttributesSimilarity(o1->attributesValues.at(attributeName),
                                                                       o2->attributesValues.at(attributeName));
    else
      result += cAttributeSimilarityMeasure->countAttributesSimilarity( o1->attributesValues.at(attributeName),
                                                                        o2->attributesValues.at(attributeName));
  }

  return result / commonAttributes.size();
}

void customObjectSimilarityMeasure::findCommonAttributes(sample *sample1, sample *sample2)
{
  commonAttributes.clear();

  vector<string> firstSampleAttributes, secondSampleAttributes;

  for(auto nameValue : sample1->attributesValues) firstSampleAttributes.push_back(nameValue.first);
  for(auto nameValue : sample2->attributesValues) secondSampleAttributes.push_back(nameValue.first);

  for(string attributeName : firstSampleAttributes)
  {
    if(find(secondSampleAttributes.begin(), secondSampleAttributes.end(), attributeName) != firstSampleAttributes.end())
    {
      // If both contains given attribute
      commonAttributes.push_back(attributeName);
    }
  }
}

