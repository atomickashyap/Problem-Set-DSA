//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		if(n*m<k)
         return -1;
         int rL=0;
         int rH=n;
         int cL=0;
         int cH=m;
         while(rL<rH && cL<cH)
         {
             for(int i=cL;i<cH;i++)
             {
                 if(k==1)
                 return a[rL][i];
                 k--;
             }
             rL++;
             for(int i=rL;i<rH;i++)
             {
                 if(k==1)
                 return a[i][cH-1];
                 k--;
             }
             cH--;
             if(rL<rH)
             {
                 for(int i=cH-1;i>=cL;i--)
                 {
                     if(k==1)
                     return a[rH-1][i];
                     k--;
                 }
                 rH--;
             }
             if(cL<cH)
             {
                 for(int i=rH-1;i>=rL;i--)
                 {
                     if(k==1)
                     return a[i][cL];
                     k--;
                 }
                 cL++;
             }
         }
         return -1;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends