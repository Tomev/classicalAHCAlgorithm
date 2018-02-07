#ifndef CLASSICALAHCALGORITHM_COMPLETELINKCLUSTERSIMILARITYMEASURE_H
#define CLASSICALAHCALGORITHM_COMPLETELINKCLUSTERSIMILARITYMEASURE_H

#include "clustersSimilarityMeasure.h"

class completeLinkClusterSimilarityMeasure  : public clustersSimilarityMeasure
{
  public:
    completeLinkClusterSimilarityMeasure(objectsSimilarityMeasure *oSimMeasure);
    double countClustersSimilarity(cluster* c1, cluster* c2);

  protected:
    bool isSimilarityValueCorrect(double value);
};


#endif //CLASSICALAHCALGORITHM_COMPLETELINKCLUSTERSIMILARITYMEASURE_H
