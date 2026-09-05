class Solution {
public:
    bool check(vector<int>& nums, int x, int y){
        long long sum = 0;
        for(int i=0; i<nums.size(); i++){
            //nums[i] = (nums[i] + x - 1)/x;
            sum += (nums[i] + x - 1)/x;
        }
        if(sum <= y) return 1;
        else return 0;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, h = *max_element(nums.begin(), nums.end());
        int ans = l;
        while(l<=h){
            int mid  = l + (h-l)/2;
            if(check(nums, mid, threshold)){
                ans = mid;
                h = mid - 1;
            }
            else l = mid +1 ;
        }
        return ans;
    }
};