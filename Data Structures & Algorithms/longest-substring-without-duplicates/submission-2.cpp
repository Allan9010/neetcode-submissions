class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> check;
        int ans = 0;
        int left = 0;

        for(int i = 0; i < s.size(); ++i){
            char c = s[i];

            if(check.count(c) && check[c] >= left){
                left = check[c] + 1;
            }
            check[c] = i;

            ans = std::max(ans, i - left + 1);
        }

        return ans;
    }
};
