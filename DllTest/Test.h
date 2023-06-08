#pragma once
#include <vector>

#ifdef TESTLIBRARY_EXPORTS
#define TESTLIBRARY_API __declspec(dllexport)
#else
#define TESTLIBRARY_API __declspec(dllimport)
#endif

typedef struct ProcessedData {
	float x;
	float sqaurex;
	double sinx;
	double cosx;

	ProcessedData()
	{
		this->x = 0;
		this->sqaurex = 0;
		this->sinx = 0;
		this->cosx = 0;
	}
	ProcessedData(float _x) {
		this->x = _x;
		this->sqaurex = this->x * this->x;
		this->sinx = sin(this->x);
		this->cosx= cos(this->x);
	}
}ProcessedData;

extern "C" TESTLIBRARY_API size_t Convert(std::vector<float> input, std::vector<ProcessedData>& output);