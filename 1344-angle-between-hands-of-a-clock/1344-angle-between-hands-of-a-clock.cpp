class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minuteAngle = minutes * 6.0;

        double hourAngle = (hour % 12) * 30.0 + minutes * 0.5;

        double angle = abs(hourAngle - minuteAngle);

        return min(angle, 360.0 - angle);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna