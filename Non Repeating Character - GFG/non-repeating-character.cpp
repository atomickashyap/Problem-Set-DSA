//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
       int n= S.length();
       unordered_map<char,int>map;
       for(int i=0;i<S.length();i++)
       {
           map[S[i]]++;
       }
       for(int i=0;i<S.length();i++)
       {
           if(map[S[i]]==1)
           return S[i];
           
       }
       return '$';
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends