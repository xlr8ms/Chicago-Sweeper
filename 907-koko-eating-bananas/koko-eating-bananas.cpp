class Solution {
public:
    bool check(vector<int>& v, int x, int h){
        long long sum = 0;
        for(int i=0; i<v.size(); i++){
            sum += (v[i] + x - 1)/x;
        }
        if(sum <= h) return 1;
        else return 0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        //sort(piles.begin(), piles.end());
        int l = 1, hi = *max_element(piles.begin(), piles.end());
        int ans = l;
        while(l<=hi){
            int mid = l + (hi-l)/2;
            if(check(piles, mid, h)){
                ans = mid;
                hi = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};