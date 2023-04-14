class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int s = 0;
        int e = arr.size() - 2; // Second last Index
        int mid = (s+e)/2;
        while(s<=e){
            // checking left part or not
            if(arr[mid] == arr[mid^1]){
                s = mid+1;  
            }
            else{
                e = mid-1;
            }
            mid = (s+e)/2;
        }
        return arr[s];
    }
};