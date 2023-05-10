class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {    
        vector<vector<int>> v(n,vector<int> (n,0));
        
        int cnt  =  1;
        int dir,l,r,t,b;
        dir = 0; l = 0;t = 0; r = n-1; b = n-1;
        
        while(t<=b and l<=r)
        {
            if(dir == 0)
            {
                for(int i = l; i<=r; i++)
                {
                    v[t][i] = cnt;
                    cnt++;
                }
                t++;
            }
            
            else if(dir == 1)
            {
                for (int i = t; i<=b;i++)
                {
                    v[i][r] = cnt;
                    cnt++;
                }
                r--;
            }
            
            else if(dir  == 2)
            {
                for (int i = r ; i>=l;i--)
                {
                    v[b][i] = cnt;
                    cnt++;   
                }
                b--;
            }
            
            else if(dir == 3)
            {
                for(int i = b; i>= t;i--)
                {
                    v[i][l]  =cnt;
                    cnt++;
                }
                l++;
            }
            
            dir = (dir+1)%4;
        }
        
        return v;
    }
};