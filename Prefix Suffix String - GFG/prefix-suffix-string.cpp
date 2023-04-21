//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        unordered_set<string> s;
        unordered_set<string> ss;
        string st="";
        string suf="";
        int n = s2.size();
        for(auto str:s1){
            st="";
            suf="";
            for(int i=0; i<str.size();i++){
                st.push_back(str[i]);
                s.insert(st);
            }
            for(int i=str.size()-1; i>=0; i--) 
            {
                suf.push_back(str[i]); ss.insert(suf);
                
            }
        }
        vector<string>s22;
        for(auto str: s2) {
            reverse(str.begin(), str.end());
            s22.push_back(str);
        }
        int sum=0;
        for(int i=0; i<n; i++)
        {
            if (ss.count(s22[i])==1)
            {
                sum++;
            }
            else if(s.count(s2[i])==1)
            {
                sum++;
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends