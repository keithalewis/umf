// pointer.h - unsafe pointer iterable
#ifndef UMF_POINTER_INCLUDED
#define UMF_POINTER_INCLUDED
#include "concept.h"

namespace umf::iterable {

	// unsafe pointer iterable
	template<class T>
	class pointer {
		T* p;
	public:
		using value_type = T;
		using reference = T&;

		pointer(T* p)
			: p(p)
		{ }
		bool operator==(const pointer& a) const
		{
			return p == a.p;
		}
		explicit operator bool() const
		{
			return p != nullptr; // unsafe
		}
		pointer begin() const
		{
			return *this;
		}
		pointer end() const
		{
			return pointer(nullptr);
		}
		value_type operator*() const
		{
			return *p;
		}
		reference operator*()
		{
			return *p;
		}
		pointer& operator++()
		{
			if (operator bool()) {
				++p;
			}
		
			return *this;
		}
		pointer operator++(int)
		{
			auto tmp = *this;

			operator++();

			return tmp;
		}
	};

} // namespace umf::iterable

#ifdef _DEBUG
#include <cassert>

inline int test_pointer()
{
	using umf::iterable::pointer;

	{
		int i[] = { 1,2,3 };
		pointer p(i);
		auto p2{ p };
		assert(p2 == p);
		p = p2;
		assert(!(p != p2));
		assert(1 == *p);
		++p;
		assert(2 == *p);
		assert(2 == *p++);
		assert(3 == *p);
	}

	return 0;
}

#endif // _DEBUG

#endif // UMF_POINTER_INCLUDED
