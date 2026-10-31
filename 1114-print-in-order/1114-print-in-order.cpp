#include <semaphore>
using namespace std;

class Foo {
private:
    binary_semaphore sem2{0};
    binary_semaphore sem3{0};

public:
    Foo() {}

    void first(function<void()> printFirst) {
        printFirst();
        sem2.release();
    }

    void second(function<void()> printSecond) {
        sem2.acquire();
        printSecond();
        sem3.release();
    }

    void third(function<void()> printThird) {
        sem3.acquire();
        printThird();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna