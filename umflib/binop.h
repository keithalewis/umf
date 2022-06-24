// binop.h - binary operators
#ifndef UMF_BINOP_INCLUDED
#define UMF_BINOP_INCLUDED
#include <functional>
#include "apply.h"

namespace umf::iterable {

	template<class Op, forward_iterable I, forward_iterable J>
	class binop {
		const Op& op;
		I i;
		J j;
	public:
		using value_type = std::invoke_result_t<Op, typename I::value_type, typename J::value_type>;
		using reference = value_type&;

		binop(const Op& op, const I& i, const J& j)
			: op(op), i(i), j(j)
		{ }
		bool operator==(const binop& b) const
		{
			return &op == &b.op and i == b.i and j == b.j;
		}
		binop begin() const
		{
			return *this;
		}
		binop end() const
		{
			return binop(op, i.end(), j.end());
		}
		operator bool() const
		{
			return i and j;
		}
		value_type operator*() const
		{
			return op(*i, *j);
		}
		binop& operator++()
		{
			++i;
			++j;

			return *this;
		}
		binop operator++(int)
		{
			auto tmp = *this;

			operator++();

			return tmp;
		}
	};

} // umf::iterable

#define UMF_ARITHMETIC_OPS(X)     \
	X(+, add, std::plus)          \
	X(-, sub, std::minus)         \
	X(*, mul, std::multiplies)    \
	X(/, div, std::divides)       \
	X(%, mod, std::modulus)       \

#define UMF_ARITHMETIC_BINOP(a, b, c) \
template<umf::iterable::forward_iterable I, umf::iterable::forward_iterable J> \
inline auto operator a(const I& i, const J& j) \
{ using T = std::common_type_t<typename I::value_type, typename J::value_type>; return umf::iterable::binop(c<T>{}, i, j); } \
\
template<umf::iterable::forward_iterable I, class T> \
inline auto operator a(const I& i, T t) \
{ return umf::iterable::apply([t](T u) { return c<T>{}(u, t); }, i); } \
\
template<class T, umf::iterable::forward_iterable I> \
inline auto operator a(T t, const I& i) \
{ return umf::iterable::apply([t](T u) { return c<T>{}(t, u); }, i); } \

UMF_ARITHMETIC_OPS(UMF_ARITHMETIC_BINOP)

#undef UMF_ARITHMETIC_BINOP
#undef UMF_ARITHMETIC_OPS

#ifdef _DEBUG
#include <cassert>
#include "array.h"
inline int test_binop()
{
	using umf::iterable::array;

	{
		int i[] = { 1, 2, 3 };
		int j[] = { 4, 5, 6 };
		{
			int ij[] = {5, 7, 9};
			assert(equal(array(ij), array(i) + array(j)));
		}
		{
			int ij[] = { -3, -3, -3 };
			assert(equal(array(ij), array(i) - array(j)));
		}
		{
			int ij[] = { 4, 10, 18 };
			assert(equal(array(ij), array(i) * array(j)));
		}
		{
			int ji[] = { 4, 2, 2 };
			assert(equal(array(ji), array(j) / array(i)));
		}
		{
			int ji[] = { 0, 1, 0 };
			assert(equal(array(ji), array(j) % array(i)));
		}
		{
			int k[] = { 3, 4, 5 };
			auto l = array(i) + 2;
			assert(l);
			assert(3 == *l);
			assert(4 == *++l);
			assert(5 == *++l);
			assert(!++l);
			assert(equal(array(k), array(i) + 2));
			assert(equal(array(k), 2 + array(i)));
		}

	}

	return 0;
}

#endif // _DEBUG

#endif // UMF_BINOP_INCLUDED
