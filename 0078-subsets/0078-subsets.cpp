class Solution {
public:
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        for(int num = 0;num<(1<<n);num++)
        {
            vector<int> temp;
            for(int i =0;i<n;i++)
            {
                if((num&(1<<i))) //
                {
                    temp.push_back(arr[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


//logic behind this is 
//we need to make the power set of a set
// [1,2,3,]
//[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// 2 1 0 // i indexing worker in reverse order
// 1 2 3 => 3       pow(2,3)=> 0,7;
// 0 0 0
// 0 0 1
// 0 1 0
// 0 1 1
