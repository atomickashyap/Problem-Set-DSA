class Solution {
public:
    
    bool check(vector<int>&dist,long long val,double target)
    {
        double ans=0;
        for(int i=0;i<dist.size();i++)
        {
            if(i<dist.size()-1)
            ans+=ceil((double)dist[i]/val);
            else ans+=(double)dist[i]/val;
        }
        return ans<=target;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        long long st=1,en=1e10,mid,ans=-1;
        while(st<=en)
        {
            mid=(st+en)/2;
            if(check(dist,mid,hour))
            {
                ans=mid;
                en=mid-1;
            }
            else st=mid+1;
        }
        return ans;
    }
};