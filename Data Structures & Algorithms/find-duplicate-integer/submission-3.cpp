class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0;
        int slow = 0;
        
        for(int i = 0; i < nums.size(); ++i){
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(slow == fast) break;
        }
        slow = 0;
        while(slow != fast){
            fast = nums[fast];
            slow = nums[slow];
        }

        return fast;
    }
};
