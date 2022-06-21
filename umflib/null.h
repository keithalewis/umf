// null.h - zero terminated array
#ifndef UMF_NULL_INCLUDED
#define UMF_NULL_INCLUDED
#include "concept.h"

namespace umf::iterable {

	// zero terminated array
	template<class T>
	class null {
		T* p;
	public:
		using value_type = T;
		using reference = T&;

		explicit null(T* p)
			: p(p)
		{ }
		bool operator==(const null& a) const
		{
			return p == a.p;
		}
		explicit operator bool() const
		{
			return p and *p != 0;
		}
		null begin() const
		{
			return *this;
		}
		null end() const
		{
			null e = *this;

			while (e) 
				++e;

			return e;
		}
		value_type operator*() const
		{
			return *p;
		}
		reference operator*()
		{
			return *p;
		}
		null& operator++()
		{
			if (operator bool()) {
				++p;
			}
		
			return *this;
		}
		null operator++(int)
		{
			auto tmp = *this;

			operator++();

			return tmp;
		}
	};

} // namespace umf::iterable

#ifdef _DEBUG
#include <cassert>

inline int test_null()
{
	using umf::iterable::null;

	{
		int i[] = { 1,2,3,0 };
		null p(i);
		auto p2{ p };
		assert(p2 == p);
		p = p2;
		assert(!(p != p2));
		assert(1 == *p);
		++p;
		assert(2 == *p);
		assert(2 == *p++);
		assert(3 == *p);
		++p;
		assert(!p);
	}
	{
		char s[] = "abc";
		null p(s);
		assert(p);
		assert(3 == length(p));
	}
	{
		const wchar_t s[] = L"abc";
		null p(s);
		assert(p);
		assert(3 == length(p));
	}

	return 0;
}

#endif // _DEBUG

#endif // UMF_NULL_INCLUDED
