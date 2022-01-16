#include "pch.h"
#include "CppUnitTest.h"
#include "../DoublyLinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ApiTests
{
	TEST_CLASS(ApiTests)
	{
	public:
		
		TEST_METHOD(TestClassCreate)
		{
			const auto result = new List;
			Assert::IsNotNull(result);
		}

		TEST_METHOD(TestSize0AfterCreation)
		{
			const auto result = new List;
			size_t expected = 0;
			Assert::AreEqual(expected, result->getCount());
		}
		TEST_METHOD(TestAddElementHeadSizeIncrease)
		{
			const auto result = new List;
			result->addElementHead(1);
			size_t expected = 1;
			Assert::AreEqual(expected, result->getCount());
		}
		TEST_METHOD(TestAddElementHead1Element)
		{
			const auto result = new List;
			result->addElementHead(1);
			std::string expected = "1";
			Assert::AreEqual(expected, result->getElements());
		}
		TEST_METHOD(TestAddElementHeadPosition)
		{
			const auto result = new List;
			result->addElementHead(1);
			result->addElementHead(2);
			result->addElementHead(3);
			std::string expected = "3, 2, 1";
			Assert::AreEqual(expected, result->getElements());
		}
		TEST_METHOD(TestAddElementTailSizeIncrease)
		{
			const auto result = new List;
			result->addElementTail(1);
			size_t expected = 1;
			Assert::AreEqual(expected, result->getCount());
		}
		TEST_METHOD(TestAddElementTail1Element)
		{
			const auto result = new List;
			result->addElementTail(1);
			std::string expected = "1";
			Assert::AreEqual(expected, result->getElements());
		}
		TEST_METHOD(TestAddElementTailPosition)
		{
			const auto result = new List;
			result->addElementTail(1);
			result->addElementTail(2);
			result->addElementTail(3);
			std::string expected = "1, 2, 3";
			Assert::AreEqual(expected, result->getElements());
		}
		TEST_METHOD(TestAddElementSizeIncrease)
		{
			const auto result = new List;
			result->addElement(1, 0);
			std::size_t expected = 1;
			Assert::AreEqual(expected, result->getCount());
		}
		TEST_METHOD(TestAddElement1Element0)
		{
			const auto result = new List;
			result->addElementHead(1);
			result->addElementTail(3);
			result->addElement(2, 0);
			std::string expected = "2, 1, 3";
			Assert::AreEqual(expected, result->getElements());
		}
		TEST_METHOD(TestAddElement1Element1)
		{
			const auto result = new List;
			result->addElementHead(1);
			result->addElementTail(3);
			result->addElement(2, 1);
			std::string expected = "1, 2, 3";
			Assert::AreEqual(expected, result->getElements());
		}
		TEST_METHOD(TestAddElementPosition2)
		{
			const auto result = new List;
			result->addElementTail(1);
			result->addElementTail(2);
			result->addElement(77, 1);
			std::string expected = "1, 77, 2";
			Assert::AreEqual(expected, result->getElements());
		}
		TEST_METHOD(TestAddElementError)
		{
			const auto result = new List;
			result->addElementTail(1);
			result->addElementTail(2);
			Assert::ExpectException<std::out_of_range>([&]
			{
				result->addElement(77, -3);
			});
		}
		TEST_METHOD(TestChangeElement0)
		{
			const auto result = new List;
			result->addElementTail(1);
			result->addElementTail(2);
			result->addElementTail(3);
			result->changeElement(0, 25);
			std::string expected = "25, 2, 3";
			Assert::AreEqual(expected, result->getElements());
		}
		TEST_METHOD(TestChangeElement1)
		{
			const auto result = new List;
			result->addElementTail(1);
			result->addElementTail(2);
			result->addElementTail(3);
			result->changeElement(1, 25);
			std::string expected = "1, 25, 3";
			Assert::AreEqual(expected, result->getElements());
		}
		TEST_METHOD(TestChangeElementErrorNumberLess0)
		{
			const auto result = new List;
			result->addElementTail(1);
			result->addElementTail(2);
			result->addElementTail(3);
			Assert::ExpectException<std::out_of_range>([&]
			{
				result->changeElement(77, -3);
			});
		}
		TEST_METHOD(TestChangeElementErrorNumberMoreCount)
		{
			const auto result = new List;
			result->addElementTail(1);
			result->addElementTail(2);
			result->addElementTail(3);
			Assert::ExpectException<std::out_of_range>([&]
			{
				result->changeElement(77, 5);
			});
		}
		TEST_METHOD(TestDeleteElement0)
		{
			const auto result = new List;
			result->addElementTail(1);
			result->addElementTail(2);
			result->addElementTail(3);
			result->deleteElement(0);
			std::string expected = "2, 3";
			Assert::AreEqual(expected, result->getElements());
		}
		TEST_METHOD(TestDeleteElement1)
		{
			const auto result = new List;
			result->addElementTail(1);
			result->addElementTail(2);
			result->addElementTail(3);
			result->deleteElement(1);
			std::string expected = "1, 3";
			Assert::AreEqual(expected, result->getElements());
		}
		TEST_METHOD(TestDeleteElementErrorPosLess0)
		{
			const auto result = new List;
			result->addElementTail(1);
			result->addElementTail(2);
			result->addElementTail(3);
			Assert::ExpectException<std::out_of_range>([&]
			{
				result->deleteElement(-1);
			});
		}
		TEST_METHOD(TestDeleteElementErrorPosMoreCount)
		{
			const auto result = new List;
			result->addElementTail(1);
			result->addElementTail(2);
			result->addElementTail(3);
			Assert::ExpectException<std::out_of_range>([&]
			{
				result->deleteElement(4);
			});
		}
		TEST_METHOD(TestGetCount0)
		{
			const auto result = new List;
			size_t expected = 0;
			Assert::AreEqual(expected, result->getCount());
		}
		TEST_METHOD(TestGetCount1)
		{
			const auto result = new List;
			result->addElementHead(2);
			size_t expected = 1;
			Assert::AreEqual(expected, result->getCount());
		}
		TEST_METHOD(TestGetElements0)
		{
			const auto result = new List;
			std::string expected = "";
			Assert::AreEqual(expected, result->getElements());
		}
	};
}
