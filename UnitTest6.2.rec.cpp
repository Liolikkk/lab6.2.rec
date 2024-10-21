#include "pch.h"
#include "CppUnitTest.h"
#include "../lab.6.2.rec/lab.6.2.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62rec
{
	TEST_CLASS(UnitTest62rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int arr[] = { 2, 4, 6, 8 };
			Assert::AreEqual(SumOddIndices(arr, 4), 12);
		}
	};
}
