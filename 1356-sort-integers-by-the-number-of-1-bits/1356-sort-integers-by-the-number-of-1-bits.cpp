class Solution {
private:

public:
    static bool comp(int a, int b)
    {
        int num1 = __builtin_popcount(a);
        int num2 = __builtin_popcount(b);
        if(num1!=num2)
            return num1<num2;
        return a<b;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};