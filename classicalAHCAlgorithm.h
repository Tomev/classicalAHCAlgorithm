#ifndef CLASSICALAHCALGORITHM_CLASSICALAHCALGORITHM_H
#define CLASSICALAHCALGORITHM_CLASSICALAHCALGORITHM_H

#include "groupingAlgorithm/similarityBasedGroupingAlgorithm.h"

class classicalAHCAlgorithm : public similarityBasedGroupingAlgorithm
{
  public:

    classicalAHCAlgorithm();
    void groupObjects(vector<sample*>* samples, vector<cluster>* target);

  protected:

    int numberOfClusters = 1;

    vector<cluster> clusters;

    bool isClusteringPossible(vector<sample*>* samples);
    void clusterSamples(vector<sample*>* samples);

};


#endif //CLASSICALAHCALGORITHM_CLASSICALAHCALGORITHM_H
