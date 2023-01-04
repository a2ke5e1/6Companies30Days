class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if( n < 2) {
            return 1;
        }
        return 0.5;
    }
};