cmake_minimum_required(VERSION 3.8)
project(classicalAHCAlgorithm)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES    main.cpp classicalAHCAlgorithm.cpp classicalAHCAlgorithm.h dataReaders/textDataReader.cpp
                    dataParsers/textDataParser.cpp dataSamples/textDataSample.cpp groupingAlgorithm/cluster.cpp
                    groupingAlgorithm/similarityBasedGroupingAlgorithm.h groupingAlgorithm/groupingAlgorithm.h
                    groupingAlgorithm/sample.h attributeData.h attributesDistanceMeasure.h categoricalAttributeData.cpp
                    dataParser.h dataReader.h numericalAttributeData.cpp numericalAttributeData.h)
add_executable(classicalAHCAlgorithm ${SOURCE_FILES})