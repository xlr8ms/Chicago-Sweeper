class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1, h = nums.size()-1;
        while(l<h){
            int mid = l + (h-l)/2;
            int count = 0;
            for(int i=0; i<nums.size(); i++){
                if(nums[i] <= mid) count++;
            }
            if(count <= mid) l = mid + 1;
            else h = mid;
        }
        return l;
    }
};