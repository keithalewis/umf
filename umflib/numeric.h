// numeric.h - numeric operations on iterables
#ifndef UML_NUMERIC_INCLUDED
#define UML_NUMERIC_INCLUDED
#include "concept.h"
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

	// t, op(t,*i), op(t, *++i), ...
	template<class Op, forward_iterable I, class T = typename I::value_type>
	class scan {
		const Op& op;
		I i;
		T t;
	public:
		using value_type = T;
		using reference = T&;

		scan(const Op& op, const I& i, T t)
			: op(op), i(i), t(t)
		{ }
		bool operator==(const scan& s) const
		{
			return i == s.i and t == s.t; // same op
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

} // umf::iterable

#ifdef _DEBUG
#include <cassert>
#include "array.h"
#include "counted.h"

inline int test_scan()
{
	using umf::iterable::array;
	using umf::iterable::factorial;

	{
		int i[] = { 1,1,2,6,24 };
		auto a = array(i);
		auto f = factorial<int>();
		auto t = take(5, f);
		//assert(equal(array(i), take(5, factorial<int>())));
	}

	return 0;
}

inline int test_numeric()
{
	test_scan();

	return 0;
}

#endif // _DEBUG

#endif // UML_NUMERIC_INCLUDED
