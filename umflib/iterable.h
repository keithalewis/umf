// iterable.h - iterator with operator bool() const
#pragma once
#include <compare>
#include <concepts>
#include <iterator>
#include <type_traits>

namespace umf {

	template<class I>
	concept iterable = requires (I i) {
		typename I::value_type;
		{ i.end() } -> std::same_as<I>;
		{ i.operator bool() } -> std::same_as<bool>;
		{  *i } -> std::convertible_to<typename I::value_type>;
		{ ++i } -> std::same_as<I&>;
		{ i++ } -> std::same_as<I>;
	};

	// "All happy iterables begin alike..."
	template<iterable I>
	inline I begin(I i)
	{
		return i;
	}
	// "...but each iterable ends after its own fashion."
	template<iterable I>
	inline I end(I i)
	{
		return i.end();
	}

	template<iterable I>
	inline I advance(size_t n, I i)
	{
		while (n--) {
			++i;
		}

		return i;
	}

	template<iterable I>
	inline size_t length(I i)
	{
		size_t n = 0;

		while (i) {
			++i;
			++n;
		}

		return n;
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

	template<class T>
	class iota {
		T t;
	public:
		iota(T t = 0)
			: t(t)
		{ }
		auto operator<=>(const iota&) const = default;
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
			}

			return 0;
		}
#endif // _DEBUG
	};

	template<iterable I>
	class take : public I {
		size_t n;
	public:
		take(size_t n, I i)
			: n(n), I(i)
		{ }

	};

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

			}

			return 0;
		}
#endif // _DEBUG
	};

}
