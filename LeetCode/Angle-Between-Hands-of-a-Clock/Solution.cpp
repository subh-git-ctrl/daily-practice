1class Solution {
2public:
3    double angleClock(int hour, int minutes) {
4        double hr_deg= 0.5 * (hour * 60 + minutes) ;
5        double mins_deg= minutes * 6 ;
6
7        double ans = abs (hr_deg-mins_deg);
8        if(ans<=180) return ans;
9        else return (360-ans);
10    }
11};