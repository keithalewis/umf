// concept.h - iterable concept
#ifndef UMF_CONCEPT_INCLUDED
#define UMF_CONCEPT_INCLUDED
#include <concepts>

namespace umf::iterable {

	template<class I>
	concept forward_iterable = requires (I i) {
		typename I::value_type;
		typename I::reference;
		std::equality_comparable<I>;
		{ i.operator bool() } -> std::same_as<bool>;
		{ i.begin() } -> std::same_as<I>;
		{ i.end() }   -> std::same_as<I>;
		{  *i } -> std::convertible_to<typename I::value_type>;
		{ ++i } -> std::same_as<I&>;
		{ i++ } -> std::same_as<I>;
	};

	/*
	struct postfix_increment {
		template<typename Self>
		auto operator++(this Self&& self, int)
		{
			auto tmp = self;
			++self;
			return tmp;
		}
	};

	class some_iterable : public postfix_increment {
	public:
		some_iterable& operator++();
	};
	*/

} // namespace umf

template<umf::iterable::forward_iterable I>
inline I begin(I i)
{
	return i.begin();
}
template<umf::iterable::forward_iterable I>
inline I end(I i)
{
	return i.end();
}

template<umf::iterable::forward_iterable I>
inline I back(I i)
{
	I i_ = i;

	while (i and ++i)
		++i_;

	return i_;
}

template<umf::iterable::forward_iterable I, umf::iterable::forward_iterable J>
inline void copy(I i, J j)
{
	while (i and j) {
		*j++ = *i++;
	}
}

template<umf::iterable::forward_iterable I, umf::iterable::forward_iterable J>
inline bool equal(I i, J j)
{
	while (i and j) {
		if (*i != *j) {
			return false;
		}
		++i;
		++j;
	}

	return !i and !j;
}

// length(i) + length(j) = length(i, length(j))
template<umf::iterable::forward_iterable I>
inline std::size_t length(I i, std::size_t n = 0)
{
	while (i) {
		++i;
		++n;
	}

	return n;
}

template<umf::iterable::forward_iterable I>
inline I skip(std::size_t n, I i)
{
	while (i and n--) {
		++i;
	}

	return i;
}

#ifdef _DEBUG
#include <cassert>
#include "array.h"

inline int test_concept()
{
	using umf::iterable::array;

	{
		int i[] = { 1,2,3 };
		int j[3];
		auto ai = array(i);
		auto b = back(ai);
		assert(b);
		assert(3 == *b);
		auto aj = array(j);
		copy(ai, aj);
		assert(equal(ai, aj));
		assert(3 == length(ai));
		assert(length(ai) + length(aj) == length(ai, length(aj)));
	}
	{
		int i[] = { 1,2,3 };
		auto ai = array(i);
		assert(equal(array(2, i + 1), skip(1, ai)));
		assert(1 == *ai);
		auto as = skip(10, ai);
		assert(equal(++++++++ai, as));
	}

	return 0;
}

#endif // _DEBUG

#endif // UMF_CONCEPT_INCLUDED
