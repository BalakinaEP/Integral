#include "CppUnitTest.h"
#include "../Solver/Vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorTests
{
	TEST_CLASS(VectorTests)
	{
	public:

		TEST_METHOD(addVectorDect_ValidData_Success)
		{
			//arrange
			const double x = 1.2;
			const double y = 0.5;
			const VECTOR::Vector::Mode mode
				= VECTOR::Vector::RECT;
			VECTOR::Vector v(x, y, mode);
			//act & assert
			Assert::AreEqual(v.getx(), x);
			Assert::AreEqual(v.gety(), y);
		}

		TEST_METHOD(addNullVectorDect_ValidData_Success)
		{
			//arrange
			const double x = 0;
			const double y = 0;
			const VECTOR::Vector::Mode mode
				= VECTOR::Vector::RECT;
			VECTOR::Vector v;
			//act & assert
			Assert::AreEqual(v.getx(), x);
			Assert::AreEqual(v.gety(), y);
		}

		TEST_METHOD(addVectorPolar_ValidData_Success)
		{
			//arrange
			const double module = 5.3;
			const double angle = 1.0;
			const VECTOR::Vector::Mode mode
				= VECTOR::Vector::POL;
			VECTOR::Vector v(module, angle, mode);
			//act & assert
			Assert::AreEqual(v.getModule(), module);
			Assert::AreEqual(v.getAngle(), angle);
		}

		TEST_METHOD(SetDecartMode_ValidData_Success)
		{
			//arrange
			const double module = 3.0;
			const double angle = 0.0;
			const VECTOR::Vector::Mode mode
				= VECTOR::Vector::POL;
			VECTOR::Vector v(module, angle, mode);
			//act 
			v.setRectMode();
			// assert
			Assert::AreEqual((int)v.getMode(), (int)VECTOR::Vector::RECT);
		}
		
		TEST_METHOD(SetPolarMode_ValidData_Success)
		{
			//arrange
			const double module = 3.0;
			const double angle = 0.0;
			const VECTOR::Vector::Mode mode
				= VECTOR::Vector::RECT;
			VECTOR::Vector v(module, angle, mode);
			//act 
			v.setPolMode();
			// assert
			Assert::AreEqual((int)v.getMode(), (int)VECTOR::Vector::POL);
		}

		TEST_METHOD(SumVectors_ValidData_Success)
		{
			//arrange
			VECTOR::Vector v1(0.0, 2.0);
			VECTOR::Vector v2(2.0, 0.0);
			//act 
			VECTOR::Vector result = v1 + v2;
			// assert
			Assert::AreEqual(result.getx(), 2.0);
			Assert::AreEqual(result.gety(), 2.0);
		}

		TEST_METHOD(SubVectors_ValidData_Success)
		{
			//arrange
			VECTOR::Vector v1(0.0, 2.0);
			VECTOR::Vector v2(2.0, 0.0);
			//act 
			VECTOR::Vector result = v1 - v2;
			// assert
			Assert::AreEqual(result.getx(), -2.0);
			Assert::AreEqual(result.gety(), 2.0);
		}

		TEST_METHOD(MulVectorToConst_ValidData_Success)
		{
			//arrange
			VECTOR::Vector v1(0.0, 2.0);
			const double k = 5;
			//act 
			VECTOR::Vector result = v1 * k;
			// assert
			Assert::AreEqual(result.getx(), 0.0);
			Assert::AreEqual(result.gety(), 10.0);
		}
	};
}
