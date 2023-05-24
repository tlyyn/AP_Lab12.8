#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_Lab12.8/Source.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char* first = "Lviv";
			char* second = "Frankivsk";

			bool t = compareStrings(first, second);

			Assert::AreEqual(t, false);
		}
	};
}
