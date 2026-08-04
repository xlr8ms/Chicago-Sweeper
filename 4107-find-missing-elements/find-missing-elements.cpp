class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int min_m = *min_element(nums.begin(),nums.end());
        int max_m = *max_element(nums.begin(), nums.end());
        set<int> s; vector<int> v;
        for(int x:nums) s.insert(x);
        while(min_m < max_m){
            min_m++;
            if(!s.count(min_m)){
                v.push_back(min_m);
            }
        }
        return v;
    }
};