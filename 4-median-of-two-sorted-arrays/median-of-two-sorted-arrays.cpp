class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v = nums1;  
        v.insert(v.end(), nums2.begin(), nums2.end());
        sort(v.begin(), v.end());
        double ans;
        if(v.size() % 2 == 0) {
            ans = (v[v.size()/2] + v[(v.size()/2) - 1])/2.0;
        }
        else {
            ans = v[(v.size()-1) / 2];
        }
        return ans;
    }
};