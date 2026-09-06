class Solution {
public:
    bool check(vector<int>& v, int x, int days){
        long long sum = 0, y = 1;
        for(int i=0; i<v.size(); i++){
            if(sum + v[i] <= x){
                sum += v[i];
            }
            else{
                y++;
                sum = v[i];
            }
            if(y > days) return 0;
        }
        return 1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        vector<int> v = weights;
        int l = *max_element(v.begin(), v.end()), h = accumulate(v.begin(), v.end(), 0);
        int ans = l;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(check(v, mid, days)){
                ans = mid;
                h = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};