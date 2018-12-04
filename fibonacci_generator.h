#ifndef FIBONACCI_GENERATOR_H
#define FIBONACCI_GENERATOR_H

#include <functional>

template <class T, class Plus = std::plus<T>>
class FibonacciIterator;

template <class T, class Plus = std::plus<T>>
class FibonacciGenerator;

template <class T, class Plus>
class FibonacciIterator {
private:
    FibonacciGenerator<T, Plus>& gen_;
    T saved_state;

public:
    FibonacciIterator(FibonacciGenerator<T, Plus>& gen) :
        gen_(gen), saved_state(gen.first_) {}

    T operator * () const {
        return saved_state;
    }

    auto& operator ++ () {
        gen_();
        saved_state = gen_.first_;
        return *this;
    }

    auto operator ++ (int) {
        auto tmp {*this};
        operator++();
        return tmp;
    }

    bool operator == (const FibonacciIterator& rhs) const{
        return saved_state == rhs.saved_state;
    }

    bool operator != (const FibonacciIterator& rhs) const{
        return !(*this == rhs);
    }
};

template <class T, class Plus>
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
        first_(first_0), second_(second_0) {
        generateNew();
        generateNew();
    }

    constexpr T operator () (){
        T tmp = first_;
        generateNew();
        return tmp;
    }

    auto getIterator(){
        return FibonacciIterator(*this);
    }

    friend class FibonacciIterator<T, Plus>;
};

#endif // FIBONACCI_GENERATOR_H
