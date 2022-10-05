//
// Created by smile on 2022/10/5.
//

#include <functional>
#include <future>

class Foo {
public:
    Foo() = default;

    void first(const std::function<void()> &printFirst) {
        printFirst();   // printFirst() outputs "first". Do not change or remove this line.
        firstDone.set_value();
    }

    void second(const std::function<void()> &printSecond) {
        firstDone.get_future().wait();
        printSecond();  // printSecond() outputs "second". Do not change or remove this line.
        secondDone.set_value();
    }

    void third(const std::function<void()> &printThird) {
        secondDone.get_future().wait();
        printThird();   // printThird() outputs "third". Do not change or remove this line.
    }

private:
    std::promise<void> firstDone, secondDone;
};