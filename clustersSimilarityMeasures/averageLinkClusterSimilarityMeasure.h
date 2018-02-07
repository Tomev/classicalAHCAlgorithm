#ifndef CLASSICALAHCALGORITHM_AVERAGELINKCLUSTERSIMILARITYMEASURE_H
#define CLASSICALAHCALGORITHM_AVERAGELINKCLUSTERSIMILARITYMEASURE_H

#include "clustersSimilarityMeasure.h"

class averageLinkClusterSimilarityMeasure  : public clustersSimilarityMeasure
{
public:
  averageLinkClusterSimilarityMeasure(objectsSimilarityMeasure *oSimMeasure);
  double countClustersSimilarity(cluster* c1, cluster* c2);

protected:
  bool isSimilarityValueCorrect(double value);
};

#endif //CLASSICALAHCALGORITHM_AVERAGELINKCLUSTERSIMILARITYMEASURE_H
