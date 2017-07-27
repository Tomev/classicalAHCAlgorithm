#include <iostream>
#include "singleLinkClusterSimilarityMeasure.h"

singleLinkClusterSimilarityMeasure::singleLinkClusterSimilarityMeasure(objectsSimilarityMeasure *oSimMeasure)
{
  this->samplesSimilarityMeasure = oSimMeasure;
}

double singleLinkClusterSimilarityMeasure::countClustersSimilarity(cluster *c1, cluster *c2)
{
  double maxSimilarity = 0, currentSimilarity;

  vector<sample*> c1Objects, c2Objects;
  c1->getObjects(&c1Objects);
  c2->getObjects(&c2Objects);

  for(sample* c1Object : c1Objects)
  {
    for(sample* c2Object: c2Objects)
    {
      currentSimilarity = samplesSimilarityMeasure->countObjectsSimilarity(c1Object, c2Object);

      if(!isSimilarityValueCorrect(currentSimilarity)) return -1;

      if(currentSimilarity > maxSimilarity) maxSimilarity = currentSimilarity;
    }
  }

  return maxSimilarity;
}

bool singleLinkClusterSimilarityMeasure::isSimilarityValueCorrect(double value)
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


