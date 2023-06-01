//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    void unionfind(int u , int v, vector<int>&par, vector<int>&size)
    {
        int fu=findpar(u,par);
        int fv=findpar(v,par);
        if(fu==fv) return ;
        if(size[fu]<size[fv])
        {
            par[fu]=fv;
            size[fv]=size[fv]+size[fu];
            
        }
        else
        {
            par[fv]=fu;
            size[fu]=size[fu]+size[fv];
        }
    }
    int findpar(int i, vector<int>&par)
    {
        if(par[i]==i) return i;
        return par[i]=findpar(par[i],par);
    }
    vector<int> prime;
    void precompute(){
        vector<bool> isPrime(1e6+1,true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i=2;i<=1e6+1;i++)
        if(isPrime[i]){
            prime.push_back(i);
            for(int j = 2*i;j<=1e6+1;j += i) isPrime[j] = false;
        }
    }
    int helpSanta(int n, int m, vector<vector<int>> &g){
        
        vector<int>size(n+1,1);
        vector<int>par(n+1);
        for(int i=1;i<=n;i++) par[i]=i;
        for(int i=1;i<=n;i++)
        {
            for(auto x:g[i])
           unionfind(i,x,par,size);   
        }
        int s=0;
        for(int i=1;i<=n;i++)
        {
            s=max(s,size[i]);
        }
        
        if(s==1) return -1;
        return prime[s-1];
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends