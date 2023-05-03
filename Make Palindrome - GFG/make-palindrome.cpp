//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
bool makePalindrome(int n,vector<string> &arr){
        // Code here
        unordered_set<string>s;
        for(int i = 0;i<n;i++){
            string str=arr[i];
            reverse(str.begin(),str.end());
            if(s.find(str)!=s.end()){
                s.erase(str);
            } else{
                s.insert(arr[i]);
            }
        }
        if(s.size()==0){
            return true;
        }
        if(s.size()==1){
            auto it = s.begin();
            string str = *it;
            int i=0, j=str.length()-1;
            while(i<=j){
                if(str[i]!=str[j]){
                    return false;
                }
                i++;
                j--;
            }
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends