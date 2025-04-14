#pragma once
#include <iostream>

namespace VECTOR
{
	class Vector
	{
	public:
		enum Mode { RECT, POL };
	private:
		double x;
		double y;
		double module;
		double angle;
		Mode mode;
		void setx();
		void sety();
		void setModule();
		void setAngle();
	public:
		Vector();
		Vector(const double param1, const double param2,
			const Mode mode = RECT);
		double getx() const;
		double gety() const;
		double getModule() const;
		double getAngle() const;
		Mode getMode() const;
		void setRectMode();
		void setPolMode();

		Vector operator+(const Vector& other) const;
		Vector operator-(const Vector& other) const;
		Vector operator-() const;
		Vector operator*(const double coef) const;

		friend Vector operator*(const double coef,
			const Vector& other);
		friend std::ostream& operator<<(std::ostream& os,
			const Vector& other);
	};
}
