#include <iostream>
// https://www.boost.org/
// Free peer-reviewed portable C++ source libraries.
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;

// 21/10/2018

int main()
{
    unsigned n = 100;
    cpp_int fact = n;
    for (unsigned i = n; i != 0; i--) fact *= i;

    cpp_int sum = 0;
    while (fact != 0) {
        sum += fact % 10;
        fact /= 10;
    }

    std::cout << sum << std::endl;
    
    return 0;
}