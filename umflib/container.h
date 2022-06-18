// container.h - Convert STL container to an iterable
#ifndef UMF_CONTAINER_INCLUDED
#define UMF_CONTAINER_INCLUDED
#include <compare>
#include "concept.h"

namespace umf::iterable {

	template<class C>
	class container {
		typename C::iterator b;
		typename C::iterator e;
	public:
		using value_type = typename C::value_type;
		using reference = typename C::reference;

		container(const typename C::iterator& b, const typename C::iterator& e)
			: b(b), e(e)
		{ }
		container(C& c)
			: container(c.begin(), c.end())
		{ }
		auto operator<=>(const container&) const = default;
		explicit operator bool() const
		{
			return b != e;
		}
		container begin() const
		{
			return container(b, e);
		}
		container end() const
		{
			return container(e, e);
		}
		value_type operator*() const
		{
			return *b;
		}
		reference operator*()
		{
			return *b;
		}
		container& operator++()
		{
			if (operator bool()) {
				++b;
			}

			return *this;
		}
		container operator++(int)
		{
			auto tmp = *this;

			operator++();

			return tmp;
		}
	};

} // namespace umf

#ifdef _DEBUG
#include <cassert>
#include <vector>
inline int test_container()
{
	using umf::iterable::container;
	{
		std::vector<int> i({ 1,2,3 });
		auto c = container(i);
		assert(c);
		auto c2{ c };
		assert(c2 == c);
		c = c2;
		assert(!(c != c2));
		assert(1 == *c);
		++c;
		assert(2 == *c);
		assert(2 == *c++);
		assert(3 == *c);
		++c;
		assert(!c);
		++c;
		assert(!c);
	}
	{
		std::vector<int> i({ 1,2,3 });
		auto c = container(i);
		int s = 0;
		for (const auto& t : c) {
			s += t;
		}
		assert(6 == s);
	}
	{
		std::vector<int> i({ 1,2,3 });
		auto c = container(i);
		++c;
		*c = 4;
		assert(4 == i[1]);
	}

	return 0;
}
#endif // _DEBUG

#endif // UMF_CONTAINER_INCLUDE

