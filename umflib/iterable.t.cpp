// iterable.t.cpp - test iterable
#include <cassert>
#include "iterable.h"

using namespace umf;

int main()
{
	iota<int>::test();
	iterable_n<iota<int>>::test();
	iterable_ptr<int>::test();
	iterable_null<char>::test();

	{
		auto i = apply([](int x) { return 2 * x;  }, iota<int>(1));
		assert(2 == *i);
		++i;
		assert(4 == *i);
	}

	return 0;
}