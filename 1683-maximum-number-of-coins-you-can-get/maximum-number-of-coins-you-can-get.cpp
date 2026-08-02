class Solution {
public:
    int maxCoins(vector<int>& piles) {
        //1 2 2 4 7 8
        // 1 2 3 4 5 6 7 8 9
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int i = n-2, k = n/3, count = 0;
        while(k--){
            count += piles[i];
            i -= 2;
        }
        return count;
    }
};