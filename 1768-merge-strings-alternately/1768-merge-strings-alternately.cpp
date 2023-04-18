class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i1L=word1.size(), i2L=word2.size();
        int i1=0, i2=0, L=i1L+i2L;
        string ans(L, 0);
        for (int i=0; i<L; ){
            if (i1<i1L){
                ans[i]=word1[i1++];
                i++;
            }
            if (i2<i2L){
                ans[i]=word2[i2++];
                i++;
            }
        }
        return ans;  
    }
};