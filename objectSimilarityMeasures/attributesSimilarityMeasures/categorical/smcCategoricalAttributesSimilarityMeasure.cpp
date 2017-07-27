#include "smcCategoricalAttributesSimilarityMeasure.h"

double smcCategoricalAttributesSimilarityMeasure::countAttributesSimilarity(string firstAttributeValue,
                                                                            string secondAttributeValue)
{
  return firstAttributeValue == secondAttributeValue ? 1 : 0;
}
