#ifndef CLASSICALAHCALGORITHM_SINGLELINKCLUSTERSIMILARITYMEASURE_H
#define CLASSICALAHCALGORITHM_SINGLELINKCLUSTERSIMILARITYMEASURE_H

#include "clustersSimilarityMeasure.h"

class singleLinkClusterSimilarityMeasure : public clustersSimilarityMeasure
{
  public:
    singleLinkClusterSimilarityMeasure(objectsSimilarityMeasure *oSimMeasure);
    double countClustersSimilarity(cluster* c1, cluster* c2);

  protected:
    bool isSimilarityValueCorrect(double value);
};


#endif //CLASSICALAHCALGORITHM_SINGLELINKCLUSTERSIMILARITYMEASURE_H
