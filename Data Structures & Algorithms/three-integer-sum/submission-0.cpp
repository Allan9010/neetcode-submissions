class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); ++i){
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            int check = nums[i];
            int front = i + 1, back = nums.size() - 1;

            while(front < back){
                int total = check + nums[front] + nums[back];
                if(total > 0) back--;
                else if(total < 0) front++;
                else{
                    ans.push_back({check, nums[front], nums[back]});
                    front++;
                    back--;
                    while(front < back && nums[front] == nums[front - 1]) front++;
                }
            }
        }
        return ans;
    }
};
