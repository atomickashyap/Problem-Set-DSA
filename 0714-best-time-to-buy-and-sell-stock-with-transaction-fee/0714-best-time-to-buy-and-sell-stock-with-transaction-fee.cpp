class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int Hbuy=0,Hnotbuy=0,Cbuy, Cnotbuy;
        for(int i  = n-1;i>=0;i--)
        {
            Cnotbuy = max((prices[i] + Hbuy),(0+Hnotbuy));
            
            Cbuy = max(-prices[i] - fee + Hnotbuy, 0 + Hbuy);
            
            Hbuy = Cbuy;
            Hnotbuy = Cnotbuy;
        }
        
        return Hbuy;
    }
};