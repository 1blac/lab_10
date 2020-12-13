#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_10.2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest102
{
	TEST_CLASS(UnitTest102)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a;
			a = Count_words();
			Assert::AreEqual(a, 0);
		}
	};
}
