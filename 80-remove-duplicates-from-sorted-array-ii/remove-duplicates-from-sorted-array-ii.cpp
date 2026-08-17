class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        nums.clear();
        int k = 0;
        for(auto x:m){
            while(x.second > 1 && k!=2) {
                nums.push_back(x.first);
                k++;
            }
            if(x.second == 1){
                nums.push_back(x.first);
            }
            k=0;
        }
        return nums.size();
    }
};