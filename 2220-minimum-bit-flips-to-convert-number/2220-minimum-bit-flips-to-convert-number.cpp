class Solution {
public:
    int minBitFlips(int start, int goal) {
        int set = start ^goal;
        return __builtin_popcount(set);
    }
};