#include <iostream>
#include "averageLinkClusterSimilarityMeasure.h"

averageLinkClusterSimilarityMeasure::averageLinkClusterSimilarityMeasure(objectsSimilarityMeasure *oSimMeasure)
{
  this->samplesSimilarityMeasure = oSimMeasure;
}

double averageLinkClusterSimilarityMeasure::countClustersSimilarity(cluster *c1, cluster *c2)
{
  double averageSimilarity = 0.0, currentSimilarity;

  vector<sample*> c1Objects, c2Objects;
  c1->getObjects(&c1Objects);
  c2->getObjects(&c2Objects);

  for(sample* c1Object : c1Objects)
  {
    for(sample* c2Object: c2Objects)
    {
      currentSimilarity = samplesSimilarityMeasure->countObjectsSimilarity(c1Object, c2Object);

      if(!isSimilarityValueCorrect(currentSimilarity)) return -1;

      averageSimilarity += currentSimilarity;
    }
  }

  averageSimilarity /= c1Objects.size() * c2Objects.size();

  if(!isSimilarityValueCorrect(averageSimilarity)) return -1;

  return averageSimilarity;
}

bool averageLinkClusterSimilarityMeasure::isSimilarityValueCorrect(double value)
{
  if(value > 1)
  {
    std::cout << "Similarity value is > 1.\n";
    return false;
  }

  if(value < 0)
  {
    std::cout << "Similarity value is < 0.\n";
    return false;
  }

  return true;
}