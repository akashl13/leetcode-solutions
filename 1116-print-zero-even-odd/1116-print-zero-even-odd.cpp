#include <mutex>
#include <condition_variable>
#include <functional>
using namespace std;

class ZeroEvenOdd {
private:
    int n;
    int turn = 0; // 0 = zero, 1 = odd, 2 = even
    mutex m;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&]() { return turn == 0; });

            printNumber(0);

            turn = (i % 2 == 1) ? 1 : 2;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&]() { return turn == 1; });

            printNumber(i);

            turn = 0;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&]() { return turn == 2; });

            printNumber(i);

            turn = 0;
            cv.notify_all();
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna