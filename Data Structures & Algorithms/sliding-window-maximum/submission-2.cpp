class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); ++i){
            while(!window.empty() && nums[i] >= nums[window.back()]) window.pop_back();
            while(!window.empty() && i - k >= window.front()) window.pop_front();
            window.push_back(i);
            
            if(i >= k - 1){
                ans.push_back(nums[window.front()]);
            }
        }

        return ans;
    }
};
