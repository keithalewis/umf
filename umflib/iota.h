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
			return t != *end();
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

} // namespace umf::iterable

#ifdef _DEBUG
#include <cassert>

inline int test_iota()
{
	using umf::iterable::iota;

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

	return 0;
}

#endif // _DEBUG

#endif // UMF_IOTA_INCLUDED