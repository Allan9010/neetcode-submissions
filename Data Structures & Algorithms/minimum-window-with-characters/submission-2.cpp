class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        vector<int> check(52, 0);
        int left = 0;
        int ansleft = 0, ansright = 0;
        int minlen = INT_MAX;
        for(auto c : t){
            if('a' <= c && c <= 'z') check[c - 'a']++;
            else check[c - 'A' + 26]++;
        }

        for(int i = 0; i < s.size(); ++i){
            if('a' <= s[i] && s[i] <= 'z'){
                check[s[i] - 'a']--;
            }
            else check[s[i] - 'A' + 26]--;

            while(checkZero(check)){
                if((i - left) < minlen){
                    ansright = i;
                    ansleft = left;
                    minlen = ansright - ansleft + 1;
                }
                if(islower(s[left])) check[s[left] - 'a']++;
                else check[s[left] - 'A' + 26]++;
                left++;
            }
        }

        return minlen == INT_MAX ? "" : s.substr(ansleft, minlen);

    }
    bool checkZero(const vector<int> &check){
        for(auto count : check){
            if(count > 0) return false;
        }
        return true;
    }
};
//先right++，當條件符合後，就嘗試縮短left並且若長度較短就更新答案
//left無法在縮短後，繼續right++