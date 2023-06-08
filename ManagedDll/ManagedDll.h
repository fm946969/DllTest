#pragma once
#include <vector>

using namespace System;
using namespace System::Runtime::InteropServices;

namespace ManagedDll {
	public value struct ProcessedData {
		float x;
		float sqaurex;
		double sinx;
		double cosx;


		ProcessedData(float x, float sqaurex, double sinx, double cosx)
			: x(x), sqaurex(sqaurex), sinx(sinx), cosx(cosx)
		{
		}
	};

	typedef struct ProcessedDataNative {
		float x;
		float sqaurex;
		double sinx;
		double cosx;

		ProcessedDataNative(ProcessedData% _dat);
	}ProcessedDataNative;
	public ref class ConvertWrapper
	{
	private:
		// TODO: Add your methods for this class here.
		[DllImport("DllTest.dll", EntryPoint = "Convert", CallingConvention = CallingConvention::Cdecl)]
		static size_t _Convert(std::vector<float> input, std::vector<ProcessedDataNative>& output);

	public:
		static size_t Convert(array<float>^ input, [Out] array<ProcessedData>^% output);
	};


}
