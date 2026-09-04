class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        
        vector<int> count(26, 0);
        for(auto c : s1){
            count[c - 'a']++;
        }

        int windowSize = s1.size();
        for(int i = 0; i < windowSize; i++){
            count[s2[i] - 'a']--;
        }
        if(checkZero(count)) return true;

        for(int i = windowSize; i < s2.size(); ++i){
            count[s2[i] - 'a']--;
            count[s2[i - windowSize] -'a']++;
            if(count[s2[i] - 'a'] == 0 && checkZero(count)) return true;            
        }

        return false;
    }
    bool checkZero(const vector<int> &count){
        for(int i = 0; i < count.size(); ++i){
            if(count[i] != 0) return false;
        }
        return true;
    }
};
