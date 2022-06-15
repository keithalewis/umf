// iterable.t.cpp - test iterable
#include <cassert>
#include "iterable.h"

using namespace umf;

int main()
{
	iota<int>::test();
	iterable_ptr<int>::test();

	return 0;
}