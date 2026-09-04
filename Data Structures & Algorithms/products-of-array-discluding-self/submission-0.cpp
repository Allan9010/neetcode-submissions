class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> frontProduct(nums.size(), 1);
        vector<int> backProduct(nums.size(), 1);
        vector<int> ans(nums.size(), 0);

        for(int i = nums.size() - 2; i >= 0; --i){
            frontProduct[i] = nums[i + 1] * frontProduct[i + 1];
        }

        for(int i = 1; i < nums.size(); ++i){
            backProduct[i] = nums[i - 1] * backProduct[i - 1];
        }

        for(int i = 0; i < nums.size(); ++i){
            ans[i] = frontProduct[i] * backProduct[i];
        }

        return ans;
    }
};
