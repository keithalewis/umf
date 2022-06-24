// iota.h - t, t + 1, t + 2, ...
#ifndef UMF_IOTA_INCLUDED
#define UMF_IOTA_INCLUDED
#include <compare>
#include <limits>
#include "concept.h"

namespace umf::iterable {

	template<class T>
	class iota {
		T t;
	public:
		using value_type = T;
		using reference = T&;

		iota(T t = 0)
			: t(t)
		{ }
		auto operator<=>(const iota&) const = default;
		explicit operator bool() const
		{
			return *this != end();
		}
		iota begin() const
		{
			return *this;
		}
		iota end() const
		{
			return iota(std::numeric_limits<T>::max());
		}
		value_type operator*() const
		{
			return t;
		}
		reference operator*()
		{
			return t;
		}
		iota& operator++()
		{
			++t;

			return *this;
		}
		iota operator++(int)
		{
			auto tmp = *this;

			operator++();

			return tmp;
		}
	};

	template<class T>
	class constant {
		T t;
	public:
		using value_type = T;
		using reference = T&;

		constant(T t = 0)
			: t(t)
		{ }
		auto operator<=>(const constant&) const = default;
		explicit operator bool() const
		{
			return true;
		}
		constant begin() const
		{
			return *this;
		}
		constant end() const
		{
			return constant(std::numeric_limits<T>::max());
		}
		value_type operator*() const
		{
			return t;
		}
		reference operator*()
		{
			return t;
		}
		constant& operator++()
		{
			return *this;
		}
		constant operator++(int)
		{
			auto tmp = *this;

			operator++();

			return tmp;
		}
	};

	template<class T>
	class arithmetic {
		T t, dt;
	public:
		using value_type = T;
		using reference = T&;

		arithmetic(T t = 0, T dt = 1)
			: t(t), dt(dt)
		{ }
		auto operator<=>(const arithmetic&) const = default;
		explicit operator bool() const
		{
			return *this != end();
		}
		arithmetic begin() const
		{
			return *this;
		}
		arithmetic end() const
		{
			return arithmetic(dt >= 0 ? std::numeric_limits<T>::max() : std::numeric_limits<T>::min(), dt);
		}
		value_type operator*() const
		{
			return t;
		}
		reference operator*()
		{
			return t;
		}
		arithmetic& operator++()
		{
			t += dt;

			return *this;
		}
		arithmetic operator++(int)
		{
			auto tmp = *this;

			operator++();

			return tmp;
		}
	};

	// t0, t0*t, t0*t^2
	template<class T>
	class geometric {
		T t, t0;
	public:
		using value_type = T;
		using reference = T&;

		geometric(T t, T t0 = 1)
			: t(t), t0(t0)
		{ }
		auto operator<=>(const geometric&) const = default;
		explicit operator bool() const
		{
			return *this != end();
		}
		geometric begin() const
		{
			return *this;
		}
		geometric end() const
		{
			return geometric(std::abs(t) < 1 ? 0 : t*t0 > 0 ? std::numeric_limits<T>::max() : std::numeric_limits<T>::min(), t);
		}
		value_type operator*() const
		{
			return t0;
		}
		reference operator*()
		{
			return t0;
		}
		geometric& operator++()
		{
			t0 *= t;

			return *this;
		}
		geometric operator++(int)
		{
			auto tmp = *this;

			operator++();

			return tmp;
		}
	};

} // namespace umf::iterable

#ifdef _DEBUG
#include <cassert>
#include "array.h"
#include "counted.h"

inline int test_iota()
{
	using umf::iterable::array;
	using umf::iterable::iota;
	using umf::iterable::arithmetic;
	using umf::iterable::geometric;

	{
		iota<int> i;
		assert(i);
		assert(i == i);
		auto i2{ i };
		assert(i2 == i);
		i = i2;
		assert(!(i != i2));
		assert(0 == *i);
		++i;
		assert(1 == *i);
		assert(1 == *i++);
		assert(2 == *i);
		*i = 5;
		assert(5 == *i);
		assert(6 == *++i);
	}
	{
		iota<char> i;
		int n = 0;
		while (i) {
			++i;
			++n;
		}
		assert(std::numeric_limits<char>::max() == n);
	}
	{
		int i[] = { 2, 5, 8 };
		assert(equal(array(i), take(3, arithmetic(2, 3))));
	}
	{
		int i[] = { 2, -1, -4 };
		assert(equal(array(i), take(3, arithmetic(2, -3))));
	}
	{
		double i[] = { 1, 2, 4 };
		assert(equal(array(i), take(3, geometric(2.))));
	}
	{
		double i[] = { 1, 0.5, 0.25 };
		assert(equal(array(i), take(3, geometric(0.5))));
	}
	{
		auto c = umf::iterable::constant(2);
		assert(c);
		assert(2 == *c);
		++c;
		assert(2 == *c);
		assert(2 == *c++);
		assert(2 == *c);
	}

	return 0;
}

#endif // _DEBUG

#endif // UMF_IOTA_INCLUDED