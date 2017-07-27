#ifndef CLASSICALAHCALGORITHM_SINGLELINKCLUSTERSIMILARITYMEASURE_H
#define CLASSICALAHCALGORITHM_SINGLELINKCLUSTERSIMILARITYMEASURE_H

#include "../clustersSimilarityMeasure.h"

class singleLinkClusterSimilarityMeasure : public clustersSimilarityMeasure
{
  public:
    double countClustersSimilarity(cluster* c1, cluster* c2);
};


#endif //CLASSICALAHCALGORITHM_SINGLELINKCLUSTERSIMILARITYMEASURE_H
