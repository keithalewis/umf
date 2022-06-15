// iterable.h - iterator with operator bool() const
#pragma once
#include <algorithm>
#include <compare>
#include <concepts>
#include <iterator>
#include <numeric>
#include <type_traits>

namespace umf {

	template<class I>
	concept iterable = requires (I i) {
		typename I::value_type;
		{ i.begin() } -> std::same_as<I>;
		{ i.end() }   -> std::same_as<I>;
		{ i.operator bool() } -> std::same_as<bool>;
		{  *i } -> std::convertible_to<typename I::value_type>;
		{ ++i } -> std::same_as<I&>;
		{ i++ } -> std::same_as<I>;
	};

	template<iterable I>
	inline I begin(I i)
	{
		return i.begin();
	}
	template<iterable I>
	inline I end(I i)
	{
		return i.end();
	}

	template<iterable I, iterable J>
	inline void copy(I i, J j)
	{
		while (i and j) {
			*j++ = *i++;
		}
	}

	// all values are equal
	template<iterable I, iterable J>
	inline bool equal(I i, J j)
	{
		while (i and j) {
			if (*i++ != *j++) {
				return false;
			}
		}

		return !i and !j;
	}

	template<iterable I>
	inline I find(typename I::value_type t, I i)
	{
		while (i and *i != t) {
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

	template<class T>
	class iota {
		T t;
	public:
		using value_type = T;
		iota(T t = 0)
			: t(t)
		{ }
		auto operator<=>(const iota&) const = default;
		iota begin() const
		{
			return *this;
		}
		iota end() const
		{
			return iota<T>(std::numeric_limits<T>::max());
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
		iota& operator++()
		{
			++t;

			return *this;
		}
		iota operator++(int)
		{
			auto tmp = *this;

			operator++();

			return tmp;
		}
#ifdef _DEBUG
		static inline int test()
		{
			{
				iota<T> i;
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

	template<class P, iterable I>
	class apply {
		const P& p;
		I i;
	public:
		using value_type = decltype(p(*i));
		apply(const P& p, const I&i)
			: p(p), i(i)
		{ }
		apply begin() const
		{
			return *this;
		}
		apply end() const
		{
			return apply(p, i.end());
		}
		auto operator<=>(const apply&) const = default;
		operator bool() const
		{
			return i;
		}
		value_type operator*() const
		{
			return p(*i);
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
#ifdef _DEBUG
		static int test()
		{
			{
				auto i = apply([](auto x) { return 2 * x;  }, iota<I::value_type>(1));
				assert(2 == *i);
			}

			return 0;
		}
#endif // _DEBUG
	};

	// first n elements of I
	template<iterable I>
	class iterable_n {
		size_t n;
		I i;
	public:
		using value_type = I::value_type;
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
				auto i = iterable_n(3, iota<I::value_type>{});
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
				auto i = iterable_n(3, iota(1));
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
				assert(equal(take(3, iota<T>(1)), iterable_ptr(p)));
				auto j = iterable_ptr(p);
				copy(iota<T>{}, j);
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

	// null terminated
	template<typename T, T zero = 0>
	class iterable_null {
		T* p;
	public:
		using value_type = T;
		explicit iterable_null(T* p)
			: p(p)
		{ }
		template<size_t N>
		iterable_null(T(&p)[N])
			: p(p)
		{ }
		auto operator<=>(const iterable_null&) const = default;
		iterable_null begin() const
		{
			return *this;
		}
		iterable_null end() const
		{
			return find(0, *this);
		}
		operator bool() const
		{
			return p and std::abs(*p) > zero;
		}
		T operator* () const
		{
			return *p;
		}
		T& operator*()
		{
			return *p;
		}
		iterable_null& operator++()
		{
			if (p and *p) {
				++p;
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
}
>>>>>>> 72580ecbf964e5b6d4397aff5a4456d74d923f60
