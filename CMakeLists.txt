cmake_minimum_required(VERSION 3.8)
project(classicalAHCAlgorithm)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES    main.cpp classicalAHCAlgorithm.cpp classicalAHCAlgorithm.h dataReaders/textDataReader.cpp
                    dataParsers/textDataParser.cpp dataSamples/textDataSample.cpp groupingAlgorithm/cluster.cpp
                    groupingAlgorithm/similarityBasedGroupingAlgorithm.h groupingAlgorithm/groupingAlgorithm.h
                    groupingAlgorithm/sample.h attributeData.h categoricalAttributeData.cpp
                    dataParser.h dataReader.h numericalAttributeData.cpp numericalAttributeData.h clustersSimilarityMeasure.h clustersSimilarityMeasures/singleLinkClusterSimilarityMeasure.cpp clustersSimilarityMeasures/singleLinkClusterSimilarityMeasure.h objectSimilarityMeasures/objectsSimilarityMeasure.h objectSimilarityMeasures/customObjectSimilarityMeasure.cpp objectSimilarityMeasures/customObjectSimilarityMeasure.h objectSimilarityMeasures/attributesSimilarityMeasures/attributesSimilarityMeasure.h objectSimilarityMeasures/attributesSimilarityMeasures/categorical/smcCategoricalAttributesSimilarityMeasure.cpp objectSimilarityMeasures/attributesSimilarityMeasures/categorical/smcCategoricalAttributesSimilarityMeasure.h objectSimilarityMeasures/attributesSimilarityMeasures/numerical/smcNumericalAttributesSimilarityMeasure.cpp objectSimilarityMeasures/attributesSimilarityMeasures/numerical/smcNumericalAttributesSimilarityMeasure.h)
add_executable(classicalAHCAlgorithm ${SOURCE_FILES})