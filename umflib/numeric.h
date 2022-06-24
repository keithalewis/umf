// numeric.h - numeric operations on iterables
#ifndef UMF_NUMERIC_INCLUDED
#define UMF_NUMERIC_INCLUDED
#include <limits>
#include "concept.h"
#include "counted.h"
#include "iota.h"

template<class Op, umf::iterable::forward_iterable I, class T = typename I::value_type>
inline T reduce(const Op& op, I i, T t)
{
	while (i) {
		t = op(*i, t);
		++i;
	}

	return t;
}

template<umf::iterable::forward_iterable I, class T = typename I::value_type>
inline T sum(I i, T t = 0)
{
	return reduce(std::plus<T>{}, i, t);
}
template<umf::iterable::forward_iterable I, class T = typename I::value_type>
inline T product(I i, T t = 1)
{
	return reduce(std::multiplies<T>{}, i, t);
}

#ifdef _DEBUG
#include <cassert>
#include "counted.h"

inline int test_reduce()
{
	using umf::iterable::counted;
	using umf::iterable::iota;

	{
		assert(6 == sum(take(3, iota<int>(1))));
		assert(6 == product(take(3, iota<int>(1))));
	}

	return 0;
}

#endif // _DEBUG

namespace umf::iterable {

	// stop when abs(*i) <= epsilon n times in a row
	template<forward_iterable I, class T = typename I::value_type>
	class epsilon {
		I i;
		T eps;
		size_t n, _n;
	public:
		using value_type = T;
		using reference = T&;

		epsilon(const I& i, T eps = std::numeric_limits<T>::epsilon(), std::size_t n = 1)
			: i(i), eps(eps), n(n), _n(n)
		{ }
		auto operator<=>(const epsilon&) const = default;
		explicit operator bool() const
		{
			return std::abs(*i) > eps or _n;
		}
		epsilon begin() const
		{
			return *this;
		}
		epsilon end() const
		{
			auto e = *this;
			while (e) ++e;

			return e;
		}
		value_type operator*() const
		{
			return *i;
		}
		reference operator*()
		{
			return *i;
		}
		epsilon& operator++()
		{
			if (operator bool()) {
				++i;
				if (std::abs(*i) <= eps) {
					--_n;
				}
				else {
					_n = n;
				}
			}

			return *this;
		}
		epsilon operator++(int)
		{
			auto tmp = *this;

			operator++();

			return tmp;
		}
	};

	// t, op(t,*i), op(t, *++i), ...
	template<class Op, forward_iterable I, class T = typename I::value_type>
	class scan {
		Op op;
		I i;
		T t;
	public:
		using value_type = T;
		using reference = T&;

		scan(const Op& op, const I& i, T t)
			: op(op), i(i), t(t)
		{ }
		scan(const scan& s)
			: scan(s.op, s.i, s.t)
		{ }
		scan& operator=(const scan& s) //= delete;
		{
			if (this != &s) {
				i = s.i;
				t = s.t;
			}

			return *this;
		}
		~scan()
		{ }
		bool operator==(const scan& s) const
		{
			return i == s.i; // same i, same final t
		}
		explicit operator bool() const
		{
			return !!i;
		}
		scan begin() const
		{
			return *this;
		}
		scan end() const
		{
			scan(op, i.end(), 0);
		}
		value_type operator*() const
		{
			return t;
		}
		reference operator*()
		{
			return t;
		}
		scan& operator++()
		{
			if (i) {
				t = op(t, *i);
				++i;
			}

			return *this;
		}
		scan operator++(int)
		{
			auto tmp = *this;

			operator++();

			return tmp;
		}
	};

	template<class T>
	inline auto factorial(T t = 1)
	{
		return scan(std::multiplies<T>{}, iota<T>(1), t);
	}

	// Pochhammer (x)_n,k: x, x(x + k), x(x + k)(x + 2k), ...
	template<class T, class U>
	inline auto pochhammer(T x, U k = U(1))
	{
		return scan([x, k](T t, T i) { return t * (x + i * k); }, iota<T>(0), x);
	}

	template<class T>
	inline auto power(T x, T x0 = 1)
	{
		return scan([x](T t, T) { return t * x; }, x0);
	}

	template<class T>
	inline auto sequence(std::size_t n, T start = 0, T step = 1)
	{
		return take(n, arithmetic<T>(start, step));
	}

	template<class T>
	inline auto interval(T start, T stop, T incr = 1)
	{
		std::size_t n = 1u + static_cast<std::size_t>(fabs((stop - start) / incr));

		return take(n, arithmetic<T>(start, incr));
	}

} // umf::iterable

#ifdef _DEBUG
#include <cassert>
#include "array.h"
#include "counted.h"

inline int test_epsilon()
{
	return 0;
}

inline int test_scan()
{
	using umf::iterable::array;
	using umf::iterable::factorial;
	using umf::iterable::pochhammer;

	{
		int i[] = { 1, 1, 2, 6, 24 };
		assert(equal(array(i), take(5, factorial<int>())));
	}
	{
		auto q = pochhammer(1.2, 3.);
		auto q2{ q };
		assert(q2 == q);
		q = q2;
		assert(!(q != q2));


		double x = 1.2;
		for (double k : { -2, -1, 0, 1, 2}) {
			auto p = pochhammer(x, k);
			double a, b;
			a = x;
			b = *p;
			++p;
			a = x * (x + double(k));
			b = *p;
			/*
			assert(x == *p);
			assert(x * (x + double(k)) == *++p);
			assert(x * (x + 2 * double(k)) == *++p);
			*/
		}
	}

	return 0;
}

inline int test_numeric()
{
	test_epsilon();
	test_scan();

	return 0;
}

#endif // _DEBUG

#endif // UMF_NUMERIC_INCLUDED
