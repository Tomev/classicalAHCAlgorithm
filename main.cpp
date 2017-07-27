#include <iostream>
#include <ctime>
#include <fstream>

#include "groupingAlgorithm/cluster.h"
#include "attributesData/attributeData.h"
#include "dataReaders/textDataReader.h"
#include "dataParsers/textDataParser.h"
#include "classicalAHCAlgorithm.h"
#include "objectSimilarityMeasures/customObjectSimilarityMeasure.h"
#include "objectSimilarityMeasures/attributesSimilarityMeasures/numerical/smcNumericalAttributesSimilarityMeasure.h"
#include "objectSimilarityMeasures/attributesSimilarityMeasures/categorical/smcCategoricalAttributesSimilarityMeasure.h"
#include "clustersSimilarityMeasures/singleLinkClusterSimilarityMeasure.h"


int main()
{
  // Initialize time-dependent random seed
  srand (time(NULL));

  // Get source file
  ifstream sourceFile("D:\\Dysk Google\\Data Streams\\sensor.arff");

  // Initialize timer
  clock_t begin = clock();

  // Generate samples and gather attributes data
  unordered_map<string, attributeData*> attributesData;

  dataReader* dr = new textDataReader(&sourceFile);
  dataParser* dp = new textDataParser(&attributesData);

  dr->gatherAttributesData(&attributesData);
  dp->setAttributesOrder(dr->getAttributesOrder());

  vector<sample*> samples;
  vector<cluster> clusters;

  for(int i = 0; i < 10; ++i)
  {
    dr->getNextRawDatum(dp->buffer);
    dp->addDatumToContainer(&samples);
    dp->parseData(samples.back());
  }

  // Group objects
  int numberOfClusters = 10;

  attributesSimilarityMeasure* nAttrSimMeasure = new smcNumericalAttributesSimilarityMeasure();
  attributesSimilarityMeasure* cAttrSimMeasure = new smcCategoricalAttributesSimilarityMeasure();
  objectsSimilarityMeasure *oSimMeasure =
    new customObjectSimilarityMeasure(&attributesData, nAttrSimMeasure, cAttrSimMeasure);
  clustersSimilarityMeasure* cSimMeasure = new singleLinkClusterSimilarityMeasure(oSimMeasure);

  groupingAlgorithm* a = new classicalAHCAlgorithm(numberOfClusters, cSimMeasure);

  a->groupObjects(&samples, &clusters);


  clock_t end = clock();

  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

  cout << "Objects clustered in in " << elapsed_secs << " seconds.";

  return 0;
}