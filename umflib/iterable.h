// iterable.h - iterator with operator bool() const
#pragma once

#include "apply.h"
#include "array.h"
#include "binop.h"
#include "compare.h"
#include "container.h"
#include "counted.h"
#include "epsilon.h"
#include "iota.h"
#include "null.h"
#include "numeric.h"
#include "pointer.h"
#include "scan.h"

#if 0
#include <algorithm>
#include <compare>
#include <concepts>
#include <functional>
#include <iterator>
#include <numeric>
#include <optional>
#include <type_traits>

namespace umf {



	template<iterable I>
	inline I find(typename I::value_type t, I i)
	{
		while (i and *i != t) {
			++i;
		}

		return i;
	}
	template<class P, iterable I>
	inline I find_if(const P& p, I i)
	{
		while (i and !p(*i)) {
			++i;
		}

		return i;
	}

	template<iterable I>
	inline size_t length(I i)
	{
		size_t n = 0;

		while (i++) {
			++n;
		}

		return n;
	}

	template<iterable I>
	inline I skip(size_t n, I i)
	{
		while (i and n--) {
			++i;
		}

		return i;
	}


	// t, t + dt, t + 2 dt, ...
	template<class T>
	class arithmetic {
		T t, dt;
	public:
		using value_type = T;
		arithmetic(T dt = 1, T t = 0)
			: t(t), dt(dt)
		{ }
		auto operator<=>(const arithmetic&) const = default;
		arithmetic begin() const
		{
			return *this;
		}
		arithmetic end() const
		{
			return arithmetic<T>(std::numeric_limits<T>::max());
		}
		operator bool() const
		{
			return true;
		}
		T operator*() const
		{
			return t;
		}
		T& operator*()
		{
			return t;
		}
		arithmetic& operator++()
		{
			t += dt;

			return *this;
		}
		arithmetic operator++(int)
		{
			auto tmp = *this;

			operator++();

			return tmp;
		}
#ifdef _DEBUG
		static inline int test()
		{
			{
				arithmetic<T> i;
				assert(i);
				auto i2{ i };
				assert(i2 == i);
				assert(0 == *i);
				++i;
				assert(i);
				assert(1 == *i);
				assert(1 == *i++);
				assert(2 == *i);
				*i = 3;
				assert(3 == *i);
				i = skip(2, i);
				assert(5 == *i);
			}

			return 0;
		}
#endif // _DEBUG
	};
	template<class T>
	inline auto iota(T dt = 1, T t = 0)
	{
		return arithmetic<T>(dt, t);
	}

	template<class T>
	inline auto constant(T t)
	{
		return arithmetic(t, 0);
	}

	// t, t * dt, t * dt^2, ...
	template<class T>
	class geometric {
		T t, dt;
	public:
		using value_type = T;
		geometric(T dt = 1, T t = 1)
			: t(t), dt(dt)
		{ }
		auto operator<=>(const geometric&) const = default;
		geometric begin() const
		{
			return *this;
		}
		geometric end() const
		{
			return geometric<T>(std::numeric_limits<T>::max());
		}
		operator bool() const
		{
			return true;
		}
		T operator*() const
		{
			return t;
		}
		T& operator*()
		{
			return t;
		}
		geometric& operator++()
		{
			t *= dt;

			return *this;
		}
		geometric operator++(int)
		{
			auto tmp = *this;

			operator++();

			return tmp;
		}
#ifdef _DEBUG
		static inline int test()
		{
			{
				geometric<T> i(1,2);
				assert(i);
				auto i2{ i };
				assert(i2 == i);
				assert(1 == *i);
				++i;
				assert(i);
				assert(2 == *i);
				assert(2 == *i++);
				assert(4 == *i);
				*i = 3;
				assert(3 == *i);
				i = skip(2, i);
				assert(12 == *i);
			}

			return 0;
		}
#endif // _DEBUG
	};
	template<class T>
	inline auto power(T dt = 1, T t = 1)
	{
		return geometric<T>(dt, t);
	}

#pragma region pochhammer

	// Pochhammer symbol: x(x + k)(x + 2k)...
	// Use k = 1 for rising, k = -1 for falling.
	template<class T>
	class pochhammer {
		T x, k, x_, k_;
	public:
		using value_type = T;

		pochhammer(T x, T k = 1)
			: x(x), k(k), x_(x), k_(0)
		{ }
		pochhammer(const pochhammer&) = default;
		pochhammer& operator=(const pochhammer&) = default;
		~pochhammer()
		{ }

		auto operator<=>(const pochhammer&) const = default;
		pochhammer begin() const
		{
			return *this;
		}
		pochhammer end() const
		{
			return pochhammer(std::numeric_limits<T>::max(), k);
		}
		explicit operator bool() const
		{
			return true;
		}
		value_type operator*() const
		{
			return x_;
		}
		pochhammer& operator++()
		{
			k_ += k;
			x_ *= (x + k_);

			return *this;
		}
		pochhammer operator++(int)
		{
			auto tmp = *this;

			operator++();

			return tmp;
		}
#ifdef _DEBUG
		static int test()
		{
			{
				pochhammer<T> p(0);
				assert(1 == *p);
				assert(1 == *++p);
				assert(2 == *++p);
				assert(6 == *++p);
			}

			return 0;
		}
		#endif // _DEBUG
	};
	template<class T>
	inline auto factorial(T x)
	{
		return pochhammer<T>(x);
	}

#pragma endregion pochhammer

	template<class F, iterable I, class T = typename I::value_type>
	class apply {
		const F& f;
		I i;
	public:
		using value_type = std::invoke_result_t<F, T>;
		apply(const F& f, const I&i)
			: f(f), i(i)
		{ }
		apply(const apply& a)
			: f(a.f), i(a.i)
		{ }
		apply& operator=(const apply& a)
		{
			if (this != &a) {
				i = a.i;
			}

			return *this;
		}
		apply begin() const
		{
			return *this;
		}
		apply end() const
		{
			return apply(f, i.end());
		}
		auto operator==(const apply& a) const
		{
			return &f == &a.f and i == a.i; // same f object
		}
		operator bool() const
		{
			return i;
		}
		value_type operator*() const
		{
			return f(*i);
		}
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

	template<class Op, iterable I, iterable J>
	class binop {
		const Op& op;
		I i;
		J j;
	public:
		using value_type = std::invoke_result_t<Op, typename I::value_type, typename J::value_type>;
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

	// first n elements of I
	template<iterable I>
	class iterable_n {
		size_t n;
		I i;
	public:
		using value_type = typename I::value_type;
		iterable_n(size_t n, I i)
			: n(n), i(i)
		{ }
		auto operator<=>(const iterable_n&) const = default;
		iterable_n begin()
		{
			return *this;
		}
		iterable_n end() const
		{
			return skip(n, *this);
		}
		operator bool() const
		{
			return n != 0;
		}
		auto operator*() const
		{
			return *i;
		}
		auto operator*()
		{
			return *i;
		}
		iterable_n& operator++()
		{
			n && --n;
			++i;

			return *this;
		}
		iterable_n operator++(int)
		{
			auto tmp = *this;

			operator++();

			return tmp;
		}
#ifdef _DEBUG
		static int test()
		{
			{
				auto i = iterable_n(3, arithmetic<I::value_type>{});
				auto i2{ i };
				assert(i == i2);
				assert(0 == *i);
				++i;
				assert(1 == *i);
				++i;
				assert(2 == *i);
				++i;
				assert(!i);
				++i;
				assert(!i);
			}
			{
				auto i = iterable_n(3, arithmetic(1));
				assert(6 == std::accumulate(i.begin(), i.end(), 0));
				decltype(*i) s = 0;
				for (auto t : i)
				{
					s += t;
				}
				assert(6 == s);
			}

			return 0;
		}
#endif // _DEBUG
	};

	// take first n elements
	template<iterable I>
	inline auto take(size_t n, I i)
	{
		return iterable_n(n, i);
	}

	// counted array
	template<typename T>
	class iterable_ptr {
		T* p;
		size_t n;
	public:
		using value_type = T;
		explicit iterable_ptr(T* p, size_t n)
			: p(p), n(n)
		{ }
		template<size_t N>
		iterable_ptr(T(&p)[N])
			: p(p), n(N)
		{ }
		auto operator<=>(const iterable_ptr&) const = default;
		iterable_ptr begin() const
		{
			return *this;
		}
		iterable_ptr end() const
		{
			return iterable_ptr<T>(p + n, 0);
		}
		operator bool() const
		{
			return n != 0;
		}
		T operator* () const
		{
			return *p;
		}
		T& operator*()
		{
			return *p;
		}
		iterable_ptr& operator++()
		{
			if (n) {
				++p;
				--n;
			}

			return *this;
		}
		iterable_ptr operator++(int)
		{
			auto tmp = *this;

			operator++();

			return tmp;
		}
#ifdef _DEBUG
		static int test()
		{
			{
				T* p = 0;
				iterable_ptr<T> i(p, 0);
				assert(!i);
				auto i2{ i };
				assert(i2 == i);
				i = i2;
				assert(!(i != i2));
				++i;
				assert(i == i2);
			}
			{
				T p[3] = { 1,2,3 };
				iterable_ptr<T> i(p);
				assert(3 == length(i));
				auto i2{ i };
				assert(equal(i, i2));
				assert(i2 == i);
				i = i2;
				assert(i >= i2);

				assert(1 == *i);
				++i;
				assert(i);
				assert(2 == *i);
				assert(1 == *i2);
				*i = 4;
				assert(4 == *i);
				++i2;
				assert(4 == *i2);
				assert(4 == *i++);
				assert(3 == *i);
			}
			{
				T p[3] = { 1,2,3 };
				assert(equal(take(3, arithmetic<T>(1)), iterable_ptr(p)));
				auto j = iterable_ptr(p);
				copy(arithmetic<T>{}, j);
				assert(0 == *j);
				++j;
				assert(1 == *j);
				assert(2 == *++j);
				j++;
				assert(!j);
			}

			return 0;
		}
#endif // _DEBUG
	};

	// null/epsilon terminated
	template<iterable I>
	class iterable_null {
		using T = typename I::value_type;
		I i;
		T zero;
	public:
		using value_type = T;
		explicit iterable_null(const I& i, T zero = 0)
			: i(i), zero(zero)
		{ }
		/*
		template<size_t N>
		iterable_null(T(&p)[N], T zero = 0)
			: p(p), zero(zero)
		{ }
		*/
		auto operator<=>(const iterable_null&) const = default;
		iterable_null begin() const
		{
			return *this;
		}
		iterable_null end() const
		{
			auto i_ = *this;

			while (i_) {
				++i_;
			}

			return i_;
		}
		operator bool() const
		{
			return i and std::abs(*i) > zero;
		}
		T operator* () const
		{
			return *i;
		}
		T& operator*()
		{
			return *i;
		}
		iterable_null& operator++()
		{
			if (operator bool()) {
				++i;
			}

			return *this;
		}
		iterable_null operator++(int)
		{
			auto tmp = *this;

			operator++();

			return tmp;
		}
#ifdef _DEBUG
		static int test()
		{
			{
				iterable_null<const char> i("abc");
				assert(3 == length(i));
				assert('a' == *i);
				++i;
				assert('b' == *i);
				++++i;
				assert(!i);
				assert(0 == *i);
			}

			return 0;
		}
#endif // _DEBUG
	};
	template<iterable I, class T = typename I::value_type>
	inline auto epsilon(const I& i, T t = std::numeric_limits<T>::epsilon())
	{
		return iterable_null(i, t);
	}
}

template<umf::iterable I, umf::iterable J>
inline auto operator+(const I& i, const J& j)
{
	using T = std::common_type_t<typename I::value_type, typename J::value_type>;

	return umf::binop(std::plus<T>{}, i, j);
}
template<umf::iterable I, umf::iterable J>
inline auto operator-(const I& i, const J& j)
{
	using T = std::common_type_t<typename I::value_type, typename J::value_type>;

	return umf::binop(std::minus<T>{}, i, j);
}
template<umf::iterable I, umf::iterable J>
inline auto operator*(const I& i, const J& j)
{
	using T = std::common_type_t<typename I::value_type, typename J::value_type>;

	return umf::binop(std::multiplies<T>{}, i, j);
}
template<umf::iterable I, umf::iterable J>
inline auto operator/(const I& i, const J& j)
{
	using T = std::common_type_t<typename I::value_type, typename J::value_type>;

	return umf::binop(std::divides<T>{}, i, j);
}

#endif // 0
