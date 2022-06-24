// apply.h - apply a function to an iterable
#ifndef UMF_APPLY_INCLUDED
#define UMF_APPLY_INCLUDED
#include "concept.h"

namespace umf::iterable {

	template<class F, forward_iterable I, class T = typename I::value_type>
	class apply {
		F f;
		I i;
	public:
		using value_type = std::invoke_result_t<F, T>;
		using reference = void;

		apply(const F& f, const I& i)
			: f(f), i(i)
		{ }
		apply& operator=(const apply& a)
		{
			if (this != &a) {
				//f = a.f;
				i = a.i;
			}

			return *this;
		}
		auto operator==(const apply& a) const
		{
			return i == a.i; // same f object
		}
		explicit operator bool() const
		{
			return !!i;
		}
		apply begin() const
		{
			return *this;
		}
		apply end() const
		{
			return apply(f, i.end());
		}
		value_type operator*() const
		{
			return f(*i);
		}
		// no reference
		apply& operator++()
		{
			++i;

			return *this;
		}
		apply operator++(int)
		{
			auto tmp = *this;

			operator++();

			return tmp;
		}
	};

} // namespace umf::iterable

#ifdef _DEBUG
#include <cassert>
#include <functional>
#include "array.h"
#include "iota.h"

inline int test_apply()
{
	using umf::iterable::apply;
	using umf::iterable::array;
	using umf::iterable::iota;

	{
		int i[] = { 1,2,3 };
		auto a = apply([](auto i) { return 2 * i;  }, array(i));
		assert(a);
		auto a2{ a };
		assert(a2 == a);
		a = a2;
		assert(!(a != a2));
		int i2[] = { 2,4,6 };
		assert(equal(array(i2), a));
	}
	{
		auto a = apply([](auto i) { return 2 * i;  }, iota<int>{});
		auto a2 = apply(std::bind_front(std::multiplies<int>{}, 2), iota<int>{});
		//assert(a != a2); // no matching operator!=()
		assert(*a == *a2);
		assert(*++a == *++a2);
	}
	{
		int i[] = { 1,2,3 };
		int two = 2;
		auto a = apply([two](auto i) { return two * i;  }, array(i));
		assert(a);
		auto a2{ a };
		assert(a2 == a);
		a = a2;
		assert(!(a != a2));
		int i2[] = { 2,4,6 };
		assert(equal(array(i2), a));
	}

	return 0;
}

#endif // _DEBUG

#endif // UMF_APPLY_INCLUDED
