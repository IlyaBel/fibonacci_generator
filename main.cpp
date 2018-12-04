#include "fibonacci_generator.h"
#include <iostream>
#include <algorithm>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
    //Create generator with the default constructor (0, 1)
    FibonacciGenerator<int> gen1 {};
    std::generate_n(std::ostream_iterator<decltype(gen1)::result_type>(cout," "), 20, gen1);
    cout << endl;

//    auto gg = gen1;

    //Concatenate strings in Fibonacci way
    FibonacciGenerator gen2 { string{"A"}, string{"B"} };
    std::generate_n(std::ostream_iterator<decltype(gen2)::result_type>(cout," "), 10, gen2);
    cout << endl;

    //Get the max Fibonacci number less than 1000
    for (auto it = gen1.getIterator(); *it < 1000; ++it);

    //Iterate to the same state
    FibonacciGenerator<int> gen3 {};
    for (auto it = gen3.getIterator(); it != gen1.getIterator(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
