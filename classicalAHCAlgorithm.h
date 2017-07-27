#ifndef CLASSICALAHCALGORITHM_CLASSICALAHCALGORITHM_H
#define CLASSICALAHCALGORITHM_CLASSICALAHCALGORITHM_H

#include "groupingAlgorithm/similarityBasedGroupingAlgorithm.h"
#include "clustersSimilarityMeasures/clustersSimilarityMeasure.h"

class classicalAHCAlgorithm : public similarityBasedGroupingAlgorithm
{
  public:

    classicalAHCAlgorithm(int numberOfClusters, clustersSimilarityMeasure *cSimMeasure);
    void groupObjects(vector<sample*>* samples, vector<cluster>* target);

  protected:

    int numberOfClusters = 1;
    clustersSimilarityMeasure *cSimMeasure;

    vector<cluster> clusters;
    vector<vector<double>> similarityMatrix;

    bool isClusteringPossible(vector<sample*>* samples);
    void clusterSamples(vector<sample*>* samples);
    void fillSimilarityMatrix();

};


#endif //CLASSICALAHCALGORITHM_CLASSICALAHCALGORITHM_H
