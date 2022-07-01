// iterable.t.cpp - test iterable
#include <cassert>
#include "iterable.h"

using namespace umf;

#ifdef UMF_APPLY_INCLUDED
int apply_test = test_apply();
#endif
#ifdef UMF_ARRAY_INCLUDED
int array_test = test_array();
#endif
#ifdef UMF_BINOP_INCLUDED
int binop_test = test_binop();
#endif
#ifdef UMF_COMPARE_INCLUDED
int compare_test = test_compare();
#endif
#ifdef UMF_CONCEPT_INCLUDED
int concept_test = test_concept();
#endif
#ifdef UMF_CONTAINER_INCLUDED
int container_test = test_container();
#endif
#ifdef UMF_COUNTED_INCLUDED
int counted_test = test_counted();
#endif
#ifdef UMF_IOTA_INCLUDED
int iota_test = test_iota();
#endif
#ifdef UMF_NULL_INCLUDED
int null_test = test_null();
#endif
#ifdef UMF_NUMERIC_INCLUDED
int numeric_test = test_numeric();
#endif
#ifdef UMF_POINTER_INCLUDED
int pointer_test = test_pointer();
#endif
#ifdef UMF_SCAN_INCLUDED
int scan_test = test_scan();
#endif

/*
int apply_test()
{
	{
		auto i = apply([](auto x) { return 2 * x;  }, arithmetic<int>(1));
		assert(i);
		auto i2{ i };
		assert(i == i2);
		i = i2;
		assert(!(i2 != i));
		assert(2 == *i);
		++i;
		assert(4 == *i);
	}
	{
		//auto i = apply([](auto x) { return 2 * x;  }, arithmetic<int>(1));
		//int j[] = { 2,4,6 };
		//assert(equal(iterable_ptr(j), take(3, i)));
	}

	return 0;
}
*/

int main()
{
	/*
	apply_test();
	arithmetic<float>::test();
	geometric<double>::test();
	iterable_n<arithmetic<int>>::test();
	iterable_null<char>::test();
	iterable_ptr<int>::test();

	double x = 1;
	auto xn = power(x);
	auto n_ = factorial(0.);
	auto q = xn / n_;
	double expx = sum(epsilon(q), std::numeric_limits<double>::epsilon());
	*/

	return 0;
}
