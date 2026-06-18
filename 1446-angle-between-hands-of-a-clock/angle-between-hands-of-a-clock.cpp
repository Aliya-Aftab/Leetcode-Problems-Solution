
class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour = hour % 12;
        
        double hourAngle = (hour * 30.0) + (minutes * 0.5);
        double minuteAngle = minutes * 6.0;
        double diff = abs(hourAngle - minuteAngle);
        return min(diff, 360.0 - diff);
    }
};
/*
1hr- 30 deg (360/12)
1min - 0.5    (360/720)
hour = 3, minutes = 30

*/
