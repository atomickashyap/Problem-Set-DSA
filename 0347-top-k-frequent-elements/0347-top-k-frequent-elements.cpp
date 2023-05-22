class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for(int x : nums){
            if (hash.count(x)==0) hash[x]=1;
            else hash[x]++;
        }

        auto bigger=[&](int i, int j){ return hash[i]> hash[j]; };
  
        priority_queue<int, vector<int>, decltype(bigger)> pq(bigger);
        for (auto& [key, v]: hash){
 //           cout<<key<<"->"<<v<<endl;
            pq.push(key);
            if (pq.size()>k) pq.pop();
        }
        vector<int> ans(k);
        copy(&(pq.top()), &(pq.top())+k, &ans[0]);

        return ans;
    }
};