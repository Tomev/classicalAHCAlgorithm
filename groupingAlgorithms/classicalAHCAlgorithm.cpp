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
    updateSimilarityMatrix(c1, c2);
    cout << clusters.size() << endl;
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

        if(1 - maxSimilarity <= 1e-5)
        {
          lastMaximalSimilarity = maxSimilarity;
          return;
        }

        if(maxSimilarity == lastMaximalSimilarity) return;
      }
    }
  }

  lastMaximalSimilarity = maxSimilarity;
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

int classicalAHCAlgorithm::updateSimilarityMatrix(int c1Idx, int c2Idx)
{
  // Delete joined clusters data from similarity matrix.
  deleteClusterSimilarityValues(c1Idx);
  deleteClusterSimilarityValues(c2Idx);

  // Add data of created cluster to similarity matrix.
  addClusterSimilarityValues(c2Idx);

  return 0;
}

int classicalAHCAlgorithm::deleteClusterSimilarityValues(int cIdx)
{
  // Delete row.
  similarityMatrix.erase(similarityMatrix.begin() + cIdx);

  // Delete column.
  for(int rowIdx = cIdx; rowIdx < similarityMatrix.size(); ++rowIdx)
    similarityMatrix.at(rowIdx).erase(similarityMatrix.at(rowIdx).begin() + cIdx);

  return 0;
}

int classicalAHCAlgorithm::addClusterSimilarityValues(int cIdx)
{
  // Add new row to similarity matrix at proper index.
  similarityMatrix.insert(similarityMatrix.begin() + cIdx, vector<double>());

  // Add row data (into vector).
  for(int clusterIndex = 0; clusterIndex < cIdx; ++clusterIndex)
    similarityMatrix.at(cIdx).push_back(cSimMeasure->countClustersSimilarity(&clusters.at(cIdx),
                                                                             &clusters.at(clusterIndex)));

  // Don't count clusters similarity to itself. Push 1 to the back.
  similarityMatrix.at(cIdx).push_back(1);

  // Insert column with similarity data.
  for(int clusterIndex = cIdx + 1; clusterIndex < similarityMatrix.size(); ++clusterIndex)
    similarityMatrix.at(clusterIndex).insert(similarityMatrix.at(clusterIndex).begin() + cIdx,
                                             cSimMeasure->countClustersSimilarity(&clusters.at(cIdx),
                                                                                  &clusters.at(clusterIndex)));
  return 0;
}

void classicalAHCAlgorithm::printSimilarityMatrix()
{
  for(int i = 0; i < similarityMatrix.size(); ++i)
  {
    for(int j = 0; j < similarityMatrix.at(i).size(); ++j)
    {
      cout << similarityMatrix.at(i).at(j) << ", ";
    }

    cout << endl;
  }
}



