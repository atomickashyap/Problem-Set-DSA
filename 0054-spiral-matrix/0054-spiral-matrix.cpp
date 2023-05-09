class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        vector<int> v;
        int dir,l,r,t,b;
        dir = 0; l = 0; r = m[0].size()-1 ;t = 0; b = m.size()-1;
        
        while(t <= b and l <= r)
        {
            if(dir == 0)
            {
                for(int i = l ;i<=r;i++)
                {
                    v.push_back(m[t][i]);
                }
                t++;
            }
            else if(dir == 1)
            {
                for(int i = t;i<=b;i++)
                {
                    v.push_back(m[i][r]);
                }
                r--;
            }
            
            else if(dir == 2)
            {
                for(int i = r; i >= l ; i--)
                {
                    v.push_back(m[b][i]);
                }
                b--;
            }
            
            else if(dir == 3)
            {
                for(int i = b; i >= t;i--)
                {
                    v.push_back(m[i][l]);
                }
                l++;
            }
            
            dir = (dir+1)%4;
        }
        
        return v;
    }
};