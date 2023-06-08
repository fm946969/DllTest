#include "pch.h"
#include "Test.h"

size_t Convert(std::vector<float> input, std::vector<ProcessedData>& output)
{
	size_t count = input.size();
	output = std::vector<ProcessedData>(count);
	size_t i = 0;
	while (i < count)
	{
		output[i] = ProcessedData(input[i]);
		i++;
	}
	return count;
}