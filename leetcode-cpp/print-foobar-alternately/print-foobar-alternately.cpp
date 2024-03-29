//
// Created by smile on 2022/10/4.
//

#include <functional>
#include <mutex>
#include <future>
#include <condition_variable>

// thread yield
class FooBar {
private:
    int n;
    std::atomic<bool> isReady{true};
public:
    explicit FooBar(int n) {
        this->n = n;
    }

    void foo(const std::function<void()> &printFoo) {
        for (int i = 0; i < n; i++) {
            while (not isReady) {
                std::this_thread::yield();
            }
            printFoo();      // printFoo() outputs "foo". Do not change or remove this line.
            isReady = false;
        }
    }

    void bar(const std::function<void()> &printBar) {
        for (int i = 0; i < n; i++) {
            while (isReady) {
                std::this_thread::yield();
            }
            printBar();    // printBar() outputs "bar". Do not change or remove this line.
            isReady = true;
        }
    }
};


// 条件变量锁
class FooBar2 {
private:
    int n;
    std::mutex mtx; //  对象锁
    std::condition_variable cv; // 条件变量
    std::atomic<bool> isReady{true}; // 标志位,是否重新开头

public:
    explicit FooBar2(int n) {
        this->n = n;
    }

    void foo(const std::function<void()> &printFoo) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lck(mtx);
            while (not isReady) {
                cv.wait(lck); // 当前线程被阻塞
            }
            printFoo();      // printFoo() outputs "foo". Do not change or remove this line.
            isReady = false;
            cv.notify_one(); // 可以使用notify_all()唤醒所有线程，此处因为仅一个线程在等待使用notify_one()
        }
    }

    void bar(const std::function<void()> &printBar) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lck(mtx);
            while (isReady) {   // 如果标志位为 false, 则等待
                cv.wait(lck); // 当前线程被阻塞
            }
            printBar();    // printBar() outputs "bar". Do not change or remove this line.
            isReady = true;
            cv.notify_one();
        }
    }
};


// std::promise
class FooBar3 {
private:
    int n;
    std::promise<void> fooDone, barDone;

public:
    explicit FooBar3(int n) {
        this->n = n;
        barDone.set_value();
    }

    void foo(const std::function<void()> &printFoo) {
        for (int i = 0; i < n; i++) {
            barDone.get_future().get();
            barDone = std::promise<void>();
            printFoo();      // printFoo() outputs "foo". Do not change or remove this line.
            fooDone.set_value();
        }
    }

    void bar(const std::function<void()> &printBar) {
        for (int i = 0; i < n; i++) {
            fooDone.get_future().get();
            fooDone = std::promise<void>();
            printBar();    // printBar() outputs "bar". Do not change or remove this line.
            barDone.set_value();
        }
    }
};