#include <semaphore>
#include <functional>
using namespace std;

class H2O {
private:
    counting_semaphore<2> h{2};
    counting_semaphore<1> o{1};
    binary_semaphore doneH{0};
    binary_semaphore doneO{0};

public:
    H2O() {}

    void hydrogen(function<void()> releaseHydrogen) {
        h.acquire();
        releaseHydrogen();

        if (h.try_acquire()) {
            // A second hydrogen has arrived.
            h.release();
            doneH.release();
        } else {
            // Wait for the other hydrogen and oxygen.
            doneH.acquire();
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        o.acquire();
        releaseOxygen();
        o.release();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna