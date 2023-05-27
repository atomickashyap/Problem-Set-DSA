//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    private:
    int size_function(struct Node* head)
    {
        int cnt = 0;
        while(head!=NULL)
        {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    public:
    struct Node* modifyTheList(struct Node *head)
    {
        //add code here.
        struct Node* temp = head;
        int size = size_function(temp);
        stack<long> st;
        for(int i =0;i<size;i++)
        {
            int val = temp->data;
            st.push(val);
            temp = temp->next;
        }
        temp = head;
        for(int i =0;i<(size)/2;i++)
        {
            int val = temp->data;
            int val2 = st.top(); st.pop();
            int set = val2-val;
            // cout<<set
            temp->data = set;
            temp = temp->next;
        }
        

        while(!st.empty())
        {
            temp ->data = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends