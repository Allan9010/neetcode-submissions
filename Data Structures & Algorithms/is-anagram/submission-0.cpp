class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        unordered_map<char, int> hash;
        for(int i = 0; i < s.size(); ++i){
            if(hash.find(s[i]) != hash.end()){
                hash[s[i]]++;
            }
            else{
                hash[s[i]] = 1;
            }
        }
        for(int i = 0; i < t.size(); ++i){
            if(hash.find(t[i]) != hash.end()){
                hash[t[i]]--;
                if(hash[t[i]] == 0) hash.erase(t[i]);
            }
            else{
                return false;
            }
        }
        if(hash.empty()) return true;
        return false;
    }
};
