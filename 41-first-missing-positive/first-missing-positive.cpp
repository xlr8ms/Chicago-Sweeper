class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int max_m = *max_element(nums.begin(), nums.end());
        bool flag = 0;
        set<int> s;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > 0) s.insert(nums[i]);
            if(nums[i] > 0) flag = 1;
        }
        for(int i=1; i<= max_m; i++){
            if(s.count(i)) continue;
            else return i;
        }
        if(!flag) return 1;
        return max_m+1;
    }
};