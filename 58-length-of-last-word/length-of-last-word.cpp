class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0, k = 0;    
        for(int i=s.size()-1; i>=0; i--){
            if(cnt>0 && k>0 && s[i] != ' ') return cnt;
            if(s[i] != ' ') cnt++;
            if(s[i] == ' ' && cnt != 0) k++;
        }
        return cnt;
    }
};