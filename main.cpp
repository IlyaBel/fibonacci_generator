#include "fib_generator.h"
#include <iostream>
#include <algorithm>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {

    FibonacciGenerator<size_t> gen1 {};
    std::generate_n(std::ostream_iterator<decltype(gen1)::result_type>(cout," "), 20, gen1);
    cout << endl;

    FibonacciGenerator gen2 { string{"A"}, string{"B"} };
    std::generate_n(std::ostream_iterator<decltype(gen2)::result_type>(cout," "), 10, gen2);
    cout << endl;

    return 0;
}
