class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for(const auto& num : nums){
            hash[num]++;
        }
        
        vector<vector<int>> buckets(nums.size() + 1);
        for(const auto& num : hash){
            int numFreq = num.second;
            buckets[numFreq].push_back(num.first);
        }
        
        vector<int> ans;
        for(int i = buckets.size() - 1; i >= 0 && ans.size() < k; --i){
            for(const auto& num : buckets[i]){
                ans.push_back(num);
                if(ans.size() == k) return ans;
            }
        }

        return ans;
    }
};
