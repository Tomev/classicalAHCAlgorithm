#ifndef CLASSICALAHCALGORITHM_ATTRIBUTESSIMILARITYMEASURE_H
#define CLASSICALAHCALGORITHM_ATTRIBUTESSIMILARITYMEASURE_H

#include <string>

using namespace std;

class attributesSimilarityMeasure
{
  public:

    void setCurrentAttributeName(string attributeName) { this->currentAttributeName = attributeName; }

    virtual double countAttributesSimilarity(string firstAttributeValue, string secondAttributeValue) = 0;

  protected:

    string currentAttributeName;
};

#endif //CLASSICALAHCALGORITHM_ATTRIBUTESSIMILARITYMEASURE_H
