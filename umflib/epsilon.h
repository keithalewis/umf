// epsilon.h - truncate iterables
#ifndef UMF_EPSILON_INCLUDED
#define UMF_EPSILON_INCLUDED
#include <limits>
#include "concept.h"
#include "counted.h"
#include "iota.h"

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

} // umf::iterable

#ifdef _DEBUG
#include <cassert>
#include "array.h"
#include "counted.h"

inline int test_epsilon()
{
	return 0;
}

#endif // _DEBUG

#endif // UMF_EPSILON_INCLUDED
