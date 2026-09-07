class Solution {
public:
    bool check(vector<int>& nums, int x, int k){
        int k_ = 1;
        long long curr_sum = 0;
        for(int y : nums){
            if(curr_sum + y <= x){
                curr_sum += y;
            }
            else {
                k_++;
                curr_sum = y;
            }
            if(k_ > k) return 0;
        }
        return 1;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int h = accumulate(nums.begin(), nums.end(), 0);
        int ans = l;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(check(nums, mid, k)){
                ans = mid;
                h = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};