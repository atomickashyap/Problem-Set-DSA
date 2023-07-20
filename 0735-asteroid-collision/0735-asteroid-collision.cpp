class Solution {
public:
     vector<int> asteroidCollision(vector<int>& ast) {
        stack<int>st;
        
        for(int i=0; i<ast.size();i++){
            if(ast[i] > 0)
                st.push(ast[i]);
            else{
                while(!st.empty() && st.top()>0 && st.top() < -ast[i]){
                    st.pop();
                }
                if(!st.empty() && st.top() == -ast[i]){
                    st.pop();
                }
                else if(!st.empty() && st.top() > -ast[i]){
                    continue;
                }
                else{
                    st.push(ast[i]);
                }
                
            }
        }
        
        vector<int>ans(st.size());
        int i = st.size()-1;
        while(!st.empty()){
            ans[i--] = st.top();
            st.pop();
        }
        
        return ans;
    }
};