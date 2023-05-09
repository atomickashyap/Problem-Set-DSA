class Solution {
public:
    int removeElement(vector<int>& v, int val) {
        
        int n = v.size(),cnt = 0;
        queue<int> q;
        
        for(int i = 0;i<n;i++)
        {
            if(v[i] == val)
            {
                cnt++;
                q.push(i);
            }
            else{
                if(q.empty())
                    continue;
                int pos = q.front();
                swap(v[i],v[pos]);
                q.pop();
                q.push(i);
            }
        }
        
        return n-cnt;
        
    }
};