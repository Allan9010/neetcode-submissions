class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hash;
        for(int i = 0; i < strs.size(); ++i){
            string key = getHashKey(strs[i]);
            hash[key].push_back(strs[i]);
        }
        for(const auto& keyValue : hash){
            ans.push_back(keyValue.second);
        }
        return ans;
    }
private:
    string getHashKey(string& str){
        string key(26, 0);
        for(auto c : str){
            key[c - 'a']++;
        }
        return key;
    }
};
