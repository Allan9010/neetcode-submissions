class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> hash;
        for(int i = 0; i < nums.size(); ++i){
            if(hash.find(nums[i]) != hash.end()){
                return true;
            }
            else{
                hash.insert(make_pair(nums[i], true));
            }
        }
        return false;
    }
};