#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101C
{
	TEST_CLASS(UnitTest101C)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			t = false;
			Assert::AreEqual(t, 0);

		}
	};
}
