#include "smcNumericalAttributesSimilarityMeasure.h"

double smcNumericalAttributesSimilarityMeasure::countAttributesSimilarity(string firstAttributeValue,
                                                                            string secondAttributeValue)
{
  return firstAttributeValue == secondAttributeValue ? 1 : 0;
}