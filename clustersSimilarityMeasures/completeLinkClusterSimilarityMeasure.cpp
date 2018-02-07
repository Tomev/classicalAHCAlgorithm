#include <iostream>
#include "completeLinkClusterSimilarityMeasure.h"

completeLinkClusterSimilarityMeasure::completeLinkClusterSimilarityMeasure(objectsSimilarityMeasure *oSimMeasure)
{
  this->samplesSimilarityMeasure = oSimMeasure;
}

double completeLinkClusterSimilarityMeasure::countClustersSimilarity(cluster *c1, cluster *c2)
{
  double minSimilarity = 1, currentSimilarity;

  vector<sample*> c1Objects, c2Objects;
  c1->getObjects(&c1Objects);
  c2->getObjects(&c2Objects);

  for(sample* c1Object : c1Objects)
  {
    for(sample* c2Object: c2Objects)
    {
      currentSimilarity = samplesSimilarityMeasure->countObjectsSimilarity(c1Object, c2Object);

      if(!isSimilarityValueCorrect(currentSimilarity)) return -1;

      if(currentSimilarity < minSimilarity) minSimilarity = currentSimilarity;
    }
  }

  return minSimilarity;
}

bool completeLinkClusterSimilarityMeasure::isSimilarityValueCorrect(double value)
{
  if(value > 1)
  {
    cout << "Similarity value is > 1.\n";
    return false;
  }

  if(value < 0)
  {
    cout << "Similarity value is < 0.\n";
    return false;
  }

  return true;
}


