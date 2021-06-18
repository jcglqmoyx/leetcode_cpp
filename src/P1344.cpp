class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = hour, m = minutes;
        double angle = m * 360 / 60 - ((hour % 12) + (m / 60)) * 30;
        angle = abs(angle);
        angle = min(angle, 360 - angle);
        return angle;
    }
};