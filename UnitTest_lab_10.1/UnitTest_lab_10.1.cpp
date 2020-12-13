#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_10.1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlab101
{
	TEST_CLASS(UnitTestlab101)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int z;
			z = Count_aa_bb_cc();
			Assert::AreEqual(z, 0);
		}
	};
}
