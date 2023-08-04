class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n+1,true);
        prime[0]= prime[1] = false;
        int primeCount = 0;
        for(int i =2;i<n;i++)
        {
            if(prime[i] == true)
            {
                primeCount++;
                for(int j = (i<<1);j<n;j+=i)
                {
                    prime[j] = false;
                }
            }
        }
        return primeCount;
    }
};