// compare.h - three way lexicographical compare
#ifndef UMF_COMPARE_INCLUDED
#define UMF_COMPARE_INCLUDED
#include "concept.h"

namespace umf::iterable {

	template<forward_iterable I, forward_iterable J>
	inline auto compare(I i, J j)
	{
		for (; i and j; ++i, ++j) {
			auto cmp = *i <=> *j;
			if (cmp != 0) {
				return cmp;
			}
		}

		using T = std::common_type_t<typename I::value_type, typename J::value_type>;

		return T(!!i) <=> T(!!j);
	}

} // namespace umf::iterable

#ifdef _DEBUG
#include <cassert>
#include <vector>
#include "container.h"

inline int test_compare()
{
	using umf::iterable::container;

	{
		std::vector<int> a({ 1,2,3 });
		std::vector<int> b({ 1,2,4 });
		std::vector<int> c({ 2,1 });
		assert(compare(container(a), container(a)) == 0);
		assert(compare(container(a), container(b)) < 0);
		assert(compare(container(a), container(c)) < 0);
	}

	return 0;
}

#endif // _DEBUG

#endif // UMF_COMPARE_INCLUDED

