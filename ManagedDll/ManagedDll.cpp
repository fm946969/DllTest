#include "pch.h"

#include "ManagedDll.h"

using namespace ManagedDll;


size_t ConvertWrapper::Convert(array<float>^ input, [Out] array<ProcessedData>^% output)
{
	int inputCount = input->Length;
	std::vector<float> inputVector(inputCount);
	Marshal::Copy(input, 0, IntPtr(inputVector.data()), inputCount);

	std::vector<ProcessedDataNative> outputVector;
	size_t outputCount = _Convert(inputVector, outputVector);
	
	output = gcnew array<ProcessedData>(outputCount);
	for (int i = 0; i < outputCount; i++)
	{
		output[i] = ProcessedData(outputVector[i].x, outputVector[i].sqaurex, outputVector[i].sinx, outputVector[i].cosx);
	}
	return outputCount;
}

ProcessedDataNative::ProcessedDataNative(ProcessedData% _dat)
{
	this->x = _dat.x;
	this->sqaurex = _dat.sqaurex;
	this->sinx = _dat.sinx;
	this->cosx = _dat.cosx;
}