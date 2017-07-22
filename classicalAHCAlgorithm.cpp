#include <iostream>
#include "classicalAHCAlgorithm.h"

classicalAHCAlgorithm::classicalAHCAlgorithm()
{

}

void classicalAHCAlgorithm::groupObjects(vector<sample *> *samples, vector<cluster> *target)
{
  if(!isClusteringPossible(samples)) return;
  clusterSamples(samples);

  *target = clusters;
}

bool classicalAHCAlgorithm::isClusteringPossible(vector<sample *>* samples)
{
  if(numberOfClusters <= 0)
  {
    cout << "Number of clusters is lower or equal to 0" << endl;
    return false;
  }

  if(samples == nullptr)
  {
    cout << "Samples points to null." << endl;
    return false;
  }

  if(numberOfClusters > samples->size())
  {
    cout << "Number of clusters is greater than samples size." << endl;
    return false;
  }

  return true;
}

void classicalAHCAlgorithm::clusterSamples(vector<sample *> *samples)
{
  for(int clusterIndex = 0; clusterIndex < samples->size(); ++clusterIndex)
    clusters.push_back(cluster(clusterIndex, samples->at(clusterIndex)));
}
