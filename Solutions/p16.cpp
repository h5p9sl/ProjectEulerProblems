#include <iostream>
// https://www.boost.org/
// Free peer-reviewed portable C++ source libraries.
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;

// 19/10/2018
// This is one of my first times using boost; Sorry if the code is ugly.

int main()
{
    cpp_int foo = 1;
    for (unsigned i = 0; i < 1000; i++) foo = foo * 2;

    cpp_int sum = 0;
    while (foo != 0) {
        sum += foo % 10;
        foo /= 10;
    }

    std::cout << sum << std::endl;
}