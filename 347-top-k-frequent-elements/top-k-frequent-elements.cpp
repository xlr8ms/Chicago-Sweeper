class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        vector<pair<int,int>> v;
        for(auto x:m){
            v.push_back({x.second,x.first});
        }
        sort(v.begin(), v.end());
        vector<int> v1;
        for(int i=0; i<k; i++){
            v1.push_back(v[v.size()-1-i].second);
        }
        return v1;
    }
};