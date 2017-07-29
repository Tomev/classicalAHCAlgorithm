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

  int c1 = 0, c2 = 0;

  while(clusters.size() != numberOfClusters)
  {
    findMostSimilarClusters(c1, c2);
    joinClusters(c1, c2);
    //updateSimilarityMatrix();
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
  for(int clusterIndex = 0; clusterIndex < samples->size();)
    clusters.push_back(cluster(clusterIndex, samples->at(clusterIndex++)));
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
      // If we want to create square matrix, so that we can use .at(i).at(j) and .at(j).at(i) mindlessly
      // uncomment line below.

      //if(j != i) similarityMatrix.at(j).push_back(simValue);
    }
  }

  for(int i = 0; i < similarityMatrix.size(); ++i)
  {
    for(int j = 0; j < similarityMatrix.at(i).size(); ++j)
    {
      cout << similarityMatrix.at(i).at(j) << ", ";
    }

    cout << endl;
  }

}

void classicalAHCAlgorithm::findMostSimilarClusters(int &c1, int &c2)
{
  double maxSimilarity = 0;

  for(int i = 0; i < similarityMatrix.size(); ++i)
  {
    for(int j = 0; j < i; ++j)
    {
      if(i == j) continue;

      if(similarityMatrix.at(i).at(j) > maxSimilarity)
      {
        maxSimilarity = similarityMatrix.at(i).at(j);
        c1 = i;
        c2 = j;

        if(1 - maxSimilarity <= 1e-5) return;
      }
    }
  }
}

void classicalAHCAlgorithm::joinClusters(int c1Idx, int c2Idx)
{
  // Finding method works in such a way that c1Idx is greater than c2Idx

  cluster newCluster(++newClusterIndex);
  newCluster.addSubcluster(clusters.at(c1Idx));
  newCluster.addSubcluster(clusters.at(c2Idx));
  newCluster.findRepresentative();

  // Add newly created cluster in place of one at c2Idx.
  clusters.erase(clusters.begin() + c2Idx);
  clusters.insert(clusters.begin() + c2Idx, newCluster);

  clusters.erase(clusters.begin() + c1Idx);
}
