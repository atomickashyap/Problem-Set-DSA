//cost at [i] is gas[i]
// take cost[i]
// 


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0;
        int total_cost = 0;
        
        
        for(auto it: gas)
            total_gas+=it;
        for(auto it:cost)
            total_cost+=it;
        if(total_gas<total_cost)
            return -1;
        
        int current = 0,start = 0;
        for(int i = 0;i<gas.size();i++)
        {
            current +=(gas[i]-cost[i]);
            if(current<0)
            {
                current = -1;
                start = i+1;
            }
        }
        return start;
    }
};