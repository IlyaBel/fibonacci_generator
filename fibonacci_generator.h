#ifndef FIB_GENERATOR_H
#define FIB_GENERATOR_H

#include <functional>

template <class T, class Plus = std::plus<T>>
class FibonacciGenerator {
private:
    T first_;
    T second_;
    Plus plus_;

    constexpr void generateNew(){
        T tmp = plus_(first_, second_);
        first_ = second_;
        second_ = tmp;
    }

public:
    using result_type = T;

    FibonacciGenerator() : first_(0), second_(1) {}

    FibonacciGenerator(const T& first_0, const T& second_0) :
        first_(first_0), second_(second_0) {}

    constexpr T operator () (){
        T tmp = first_;
        generateNew();
        return tmp;
    }
};

#endif // FIB_GENERATOR_H
