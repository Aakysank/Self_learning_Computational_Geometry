#pragma once
#include "Core.h"
#include <type_traits> 
#include<array>
#include<limits>

namespace jmk
{
#define DIM2 2
#define DIM3 3

#define X 0
#define Y 1
#define Z 2

	template<class coordinate_type, size_t dimension = DIM3>
	class Vector
	{
		static_assert(std::is_arithmetic<coordinate_type>::value, "Vector classes can only store integral or floating point values");
		static_assert(dimension >= DIM2, "Dimension of vector must be atleast 2D");

		std::array<coordinate_type, dimension> coords;

	public:
		Vector() {}
		Vector(std::array<coordinate_type, dimension> _coords) : coords(_coords) {}
		Vector(coordinate_type _x, coordinate_type _y, coordinate_type _z) :coords(_x, _y, _z) {}
		Vector(coordinate_type _x, coordinate_type _y) :coords(_x, _y) {}
		bool operator==(const Vector<coordinate_type, dimension>& other) const;
		bool operator!=(const Vector<coordinate_type, dimension>& other) const;
		Vector<coordinate_type,dimension> operator+(const Vector<coordinate_type, dimension>& other) const;
		Vector<coordinate_type, dimension> operator-(const Vector<coordinate_type, dimension>& other) const;
		bool operator <(const Vector<coordinate_type, dimension>& other);
		bool operator >(const Vector<coordinate_type, dimension>& other);
		coordinate_type operator[](int ) const;
		void assign(int dim, coordinate_type value);
		friend double dotproduct(const Vector<coordinate_type, dimension>& v1, const Vector<coordinate_type, dimension>& v2);
		coordinate_type magnitude() const;
		void normalize() const;
	};

	typedef Vector<double, DIM2> Vector2d;
	typedef Vector<double, DIM3> Vector3d;

	template<class coordinate_type, size_t dimension>
	bool Vector<coordinate_type, dimension>::operator==(const Vector<coordinate_type, dimension>& other) const
	{
		for (int i = 0; i < dimension; i++)
		{
			if (!isEqualD(this->coords[i], other.coords[i]))
				return false;
		}

		return true;
	}

	template<class coordinate_type, size_t dimension>
	bool Vector<coordinate_type, dimension>::operator!=(const Vector<coordinate_type, dimension>& other) const
	{
		return !(this == other);
	}

	template<class coordinate_type, size_t dimension>
	inline Vector<coordinate_type, dimension> Vector<coordinate_type, dimension>::operator+(const Vector<coordinate_type, dimension>& other) const
	{
		std::array<coordinate_type, dimension> sum;
		for (int i = 0; i < dimension; i++)
		{
			sum[i] = this->coords[i] + other.coords[i];
		}

		return Vector<coordinate_type, dimension>(sum);
	}

	template<class coordinate_type, size_t dimension>
	inline Vector<coordinate_type, dimension> Vector<coordinate_type, dimension>::operator-(const Vector<coordinate_type, dimension>& other) const
	{
		std::array<coordinate_type, dimension> diff;
		for (int i = 0; i < dimension; i++)
		{
			diff[i] = this->coords[i] - other.coords[i];
		}

		return Vector<coordinate_type, dimension>(diff);
	}

	template<class coordinate_type, size_t dimension>
	bool Vector<coordinate_type, dimension>::operator<(const Vector<coordinate_type, dimension>& other)
	{
		for (int i = 0; i < dimension; i++)
		{
			if (this->coords[i] < other.coords[i])
				return true;
			else if (this->coords[i] > other.coords[i])
				return false;
		}

		return false;
	}

	template<class coordinate_type, size_t dimension>
	bool Vector<coordinate_type, dimension>::operator>(const Vector<coordinate_type, dimension>& other)
	{
		if (this == other)
			return false;

		return !(this < other);
	}

	template<class coordinate_type, size_t dimension>
	inline coordinate_type Vector<coordinate_type, dimension>::operator[](int index) const
	{
		if (index >= this->coords.size())
			return coordinate_type();

		return this->coords[index];
	}

	template<class coordinate_type, size_t dimension>
	inline void Vector<coordinate_type, dimension>::assign(int dim, coordinate_type value)
	{
		if (dim >= this->coords.size())
			return;

		this->coords[dim] = value;
	}

	template<class coordinate_type, size_t dimension>
	double dotproduct(const Vector<coordinate_type, dimension>& v1, const Vector<coordinate_type, dimension>& v2)
	{
		if (v1.coords.size() != v2.coords.size())
			return DBL_MIN;

		double dp = 0.0;
		for (int i = 0; i < dimension; i++)
			dp += v1[i] * v2[i];

		return dp;
	}

	template<class coordinate_type, size_t dimension>
	inline coordinate_type Vector<coordinate_type, dimension>::magnitude() const
	{
		coordinate_type m = 0.0;
		for (int i = 0; i < dimension; i++)
			m += this->coords[i] * this->coords[i];

		return sqrt(m);
	}

	template<class coordinate_type, size_t dimension>
	inline void Vector<coordinate_type, dimension>::normalize() const
	{
		coordinate_type mag = magnitude();

		for (int i = 0; i < dimension; i++)
			assign(i, this->coords[i] / mag);
	}

	double crossProduct2D(Vector2d& v1, Vector2d& v2);
	Vector3d crossProduct3D(Vector3d& v1, Vector3d& v2);
};