#ifndef CLASSICALAHCALGORITHM_CLUSTERSSIMILARITYMEASURE_H
#define CLASSICALAHCALGORITHM_CLUSTERSSIMILARITYMEASURE_H

#include "groupingAlgorithm/cluster.h"
#include "objectSimilarityMeasures/objectsSimilarityMeasure.h"

class clustersSimilarityMeasure
{
  public:
    virtual double conutClustersSimilarity(cluster* c1, cluster* c2) = 0;

  protected:
    objectsSimilarityMeasure* samplesSimilarityMeasure;
};

#endif //CLASSICALAHCALGORITHM_CLUSTERSSIMILARITYMEASURE_H
