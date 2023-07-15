//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    private:
    void fuc(stack<int>&s,int n,int &mid)
    {
        if(n<=0)
        {
            return;
        }
        if(n==mid)
        {
            s.pop();
            return;
        }
        
        int temp = s.top();
        s.pop();
        fuc(s,n-1,mid);
        s.push(temp);
    }
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int n)
    {
        // code here..
        int mid = ceil(n+1)/2;
        fuc(s,n,mid);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends