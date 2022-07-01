// array.h - iterable counted array
#ifndef UMF_ARRAY_INCLUDED
#define UMF_ARRAY_INCLUDED
#include <algorithm>
#include "concept.h"

namespace umf::iterable {

	// counted array
	template<class T>
	class array {
		std::size_t n;
		T* p;
	public:
		using value_type = T;
		using reference = T&;

		array(std::size_t n, T* p)
			: n(n), p(p)
		{ }
		template<std::size_t n>
		array(T(&p)[n])
			: n(n), p(p)
		{ }
		bool operator==(const array& a) const
		{
			return n == a.n and p == a.p;
		}
		explicit operator bool() const
		{
			return n != 0;
		}
		array begin() const
		{
			return *this;
		}
		array end() const
		{
			return array(0, p + n);
		}
		value_type operator*() const
		{
			return *p;
		}
		reference operator*()
		{
			return *p;
		}
		array& operator++()
		{
			if (operator bool()) {
				--n;
				++p;
			}

			return *this;
		}
		array operator++(int)
		{
			auto tmp = *this;

			operator++();

			return tmp;
		}

		// take from front (m >= 0) or back (m < 0)
		array& take(int m)
		{
			int N = static_cast<int>(n);
			m = std::clamp(m, -N, N);

			if (m >= 0) {
				n = m;
			}
			else {
				p += n + m;
				n = -m;
			}

			return *this;
		}

		// drop from front (m >= 0) or back (m < 0)
		array& drop(int m)
		{
			int N = static_cast<int>(n);
			m = std::clamp(m, -N, N);

			if (m > 0) {
				p += m;
				n -= m;
			}
			else if (m < 0) {
				n += m;
			}

			return *this;
		}
	};

} // namespace umf::iterable

template<class T>
inline auto take(int m, umf::iterable::array<T> i)
{
	return i.take(m);
}
template<class T>
inline auto drop(int m, umf::iterable::array<T> i)
{
	return i.drop(m);
}

#ifdef _DEBUG
#include <cassert>

inline int test_array()
{
	using umf::iterable::array;

	{
		int i[] = { 1,2,3 };
		array a(i);
		auto a2{ a };
		assert(a2 == a);
		a = a2;
		assert(!(a != a2));

		assert(3 == length(a));

		assert(1 == *a);
		++a;
		assert(2 == *a);
		assert(2 == *a++);
		assert(3 == *a);
		assert(!++a);
		++a;
		assert(!a);
	}
	{
		int i[] = { 1,2,3 };
		array a(i);
		assert(equal(drop(1, a), take(-2, a)));
		assert(equal(drop(-2, a), take(1, a)));
	}

	return 0;
}

#endif // _DEBUG

#endif // UMF_ARRAY_INCLUDED

