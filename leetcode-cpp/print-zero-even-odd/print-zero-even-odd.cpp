//
// Created by smile on 2022/10/5.
//

#include <functional>
#include <future>

class ZeroEvenOdd {
private:
    int n;
    std::promise<void> zeroDone, evenDone, oddDone;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        zeroDone.set_value();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(const std::function<void(int)> &printNumber) {
        for (int zeroTime = 1; zeroTime <= n; ++zeroTime) {
            zeroDone.get_future().wait();
            zeroDone = std::promise<void>();
            printNumber(0);
            if ((zeroTime & 1) == 1) {
                oddDone.set_value();
            } else {
                evenDone.set_value();
            }
        }
    }

    void even(const std::function<void(int)> &printNumber) {
        for (int even = 2; even <= n; even += 2) {
            evenDone.get_future().wait();
            evenDone = std::promise<void>();
            printNumber(even);
            zeroDone.set_value();
        }
    }

    void odd(const std::function<void(int)> &printNumber) {
        for (int odd = 1; odd <= n; odd += 2) {
            oddDone.get_future().wait();
            oddDone = std::promise<void>();
            printNumber(odd);
            zeroDone.set_value();
        }
    }
};