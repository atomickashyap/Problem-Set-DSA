class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median;
        vector<int> m((int)nums1.size() + (int)nums2.size());
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),m.begin());
        long long size = m.size();
        long long c;
        if(!(size&1))
        {
            c=size/2;
            cout<<m[c-1]<<"   "<<m[c]<<endl;
            median = (m[c-1]+m[c])/2.0;
        }
        else{
            c=(size+1)/2;
            cout<<m[c-1]<<endl;
            median = (m[c-1]);
        }
        return median;
    }
};