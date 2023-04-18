class Solution {
public:
    int maxJump(vector<int>& v) {
        long long n = v.size(), i;
    long long maxi = INT_MIN, cal;

    for (i = 0; i + 2 < n; i += 2)
    {
        cal = v[i + 2] - v[i];
        maxi = max(cal, maxi);
    }
    if (i != n - 1)
    {
        cal = v[i + 1] - v[i];
        maxi = max(cal, maxi);
        i++;
    }
    if (n & 1)
    {
        cal = v[n - 1] - v[n - 2];
        maxi =  max(maxi, cal);
        cal = v[1] - v[0];
        maxi =  max(maxi, cal);
        i--;
    }
    while (i - 2 > 0)
    {
        cal = v[i] - v[i - 2];
        maxi  = max(cal, maxi);
        i -= 2;
    }
    return maxi;
    }
};