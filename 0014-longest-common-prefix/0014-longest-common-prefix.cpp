class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // sort(strs.begin(),strs.end()); // -->O(nlogn)

        string ans="";
        string cur=strs[0];
        int n=strs.size(),search_space=cur.size();

        // -->O(n*search_space)
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<search_space;j++){
                if(cur[j]==strs[i][j]){
                    cnt++;
                }
                else{
                    break;
                }
            }
            //keeping track of search space
            if(cnt<search_space){
                search_space=cnt;
            }
        }

        for(int i=0;i<search_space;i++){
            ans += cur[i];
        }

        return ans;        
    }
};