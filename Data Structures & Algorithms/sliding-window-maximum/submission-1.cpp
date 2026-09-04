class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> maxheap;
        vector<int> ans;
        for(int i = 0; i < k; ++i){
            maxheap.push({nums[i], i});
        }
        ans.push_back(maxheap.top().first);
        
        for(int i = k; i < nums.size(); ++i){
            while(!maxheap.empty() && maxheap.top().second <= i - k) maxheap.pop();
            maxheap.push({nums[i], i});
            ans.push_back(maxheap.top().first);
        }
        return ans;
    }
};
