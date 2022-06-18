// counted.h - counted iterable
#ifndef UMF_COUNTED_INCLUDED
#define UMF_COUNTED_INCLUDED
#include "concept.h"

namespace umf::iterable {

	template<forward_iterable I>
	class counted {
		size_t n;
		I i;
	public:
		using value_type = typename I::value_type;
		using reference = typename I::reference;

		counted()
		{ }
		counted(size_t n, const I& i)
			: n(n), i(i)
		{ }
		auto operator<=>(const counted&) const = default;
		explicit operator bool() const
		{
			return n != 0;
		}
		counted begin() const
		{
			return *this;
		}
		counted end() const
		{
			return skip(n, *this);
		}
		value_type operator*() const
		{
			return *i;
		}
		reference operator*()
		{
			return *i;
		}
		counted& operator++()
		{
			if (operator bool()) {
				--n;
				++i;
			}

			return *this;
		}
		counted operator++(int)
		{
			auto tmp = *this;

			operator++();

			return tmp;
		}
	};

} // namespace umf::iterable

#ifdef _DEBUG
#include <cassert>
#include <numeric>
#include "iota.h"

inline int test_counted()
{
	using umf::iterable::counted;
	using umf::iterable::iota;

	{
		auto i = counted(3, iota<int>{});
		assert(i);
		auto i2{ i };
		assert(i2 == i);
		i = i2;
		assert(!(i != i2));
		assert(0 == *i);
		++i;
		assert(1 == *i);
		assert(1 == *i++);
		assert(2 == *i);
		assert(!++i);
	}
	{
		auto i = counted(3, iota<int>{});
		int s = 0;
		for (const auto& t : i) {
			s += t;
		}
		assert(s == std::accumulate(i.begin(), i.end(), 0));
	}
	return 0;
}

#endif // _DEBUG

#endif // UMF_COUNTED_INCLUDED
