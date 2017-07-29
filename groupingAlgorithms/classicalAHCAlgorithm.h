#ifndef CLASSICALAHCALGORITHM_CLASSICALAHCALGORITHM_H
#define CLASSICALAHCALGORITHM_CLASSICALAHCALGORITHM_H

#include "similarityBasedGroupingAlgorithm.h"
#include "../clustersSimilarityMeasures/clustersSimilarityMeasure.h"

class classicalAHCAlgorithm : public similarityBasedGroupingAlgorithm
{
  public:

    classicalAHCAlgorithm(int numberOfClusters, clustersSimilarityMeasure *cSimMeasure);
    void groupObjects(vector<sample*>* samples, vector<cluster>* target);

  protected:

    int numberOfClusters = 1,
        newClusterIndex = 0;
    clustersSimilarityMeasure *cSimMeasure;

    double lastMaximalSimilarity;

    vector<cluster> clusters;
    vector<vector<double>> similarityMatrix;

    bool isClusteringPossible(vector<sample*>* samples);
    void clusterSamples(vector<sample*>* samples);
    void fillSimilarityMatrix();
    void findMostSimilarClusters(int& c1, int& c2);
    void joinClusters(int c1Idx, int c2Idx);
    int updateSimilarityMatrix(int c1Idx, int c2Idx);
      int deleteClusterSimilarityValues(int cIdx);
      int addClusterSimilarityValues(int cIdx);

    void printSimilarityMatrix();

};


#endif //CLASSICALAHCALGORITHM_CLASSICALAHCALGORITHM_H
