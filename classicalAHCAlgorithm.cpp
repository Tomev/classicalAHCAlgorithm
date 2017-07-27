#include <iostream>
#include "classicalAHCAlgorithm.h"

classicalAHCAlgorithm::classicalAHCAlgorithm(int numberOfClusters, clustersSimilarityMeasure *cSimMeasure) :
  numberOfClusters(numberOfClusters), cSimMeasure(cSimMeasure)
{}

void classicalAHCAlgorithm::groupObjects(vector<sample *> *samples, vector<cluster> *target)
{
  if(!isClusteringPossible(samples)) return;
  clusterSamples(samples);
  fillSimilarityMatrix();

  while(clusters.size() != numberOfClusters)
  {

  }

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

void classicalAHCAlgorithm::fillSimilarityMatrix()
{
  similarityMatrix.clear();

  double simValue;

  for(int i = 0; i < clusters.size(); ++i)
  {
    similarityMatrix.push_back(vector<double>());

    for(int j = 0; j <= i; ++j)
    {
      simValue = cSimMeasure->countClustersSimilarity(&clusters.at(i), &clusters.at(j));
      similarityMatrix.at(i).push_back(simValue);
      // We want to create square matrix, so that we can use .at(i).at(j) and .at(j).at(i) mindlessly.
      // It can be changed to triangle matrix for space-saving purposes by commenting out line below.
      if(j != i) similarityMatrix.at(j).push_back(simValue);
    }
  }
}
