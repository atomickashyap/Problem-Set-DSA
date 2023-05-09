class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i = 0 ;i< haystack.size() ;i++){
            int j = 0, k = i;
             while(i<haystack.size() && haystack[i] == needle[j] && j<needle.size()){
                 i++; j++;
             }
             if(j == needle.size()) return k;
             i = k;
        }
        return -1;
    }
};