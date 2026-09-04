class Solution {
public:
    int search(vector<int>& nums, int target) {
        int tail = nums.size() - 1;
        int head = 0;

        while(head <= tail){
            int mid = head + (tail - head) / 2;
            if(nums[mid] == target) return mid;

            if(nums[mid] >= nums[head]){
                if(target >= nums[head] && target < nums[mid]) tail = mid - 1;
                else head = mid + 1;
            }
            else{
                if(target <= nums[tail] && target > nums[mid]) head = mid + 1;
                else tail = mid - 1;
            }

        }

        return -1;
    }
};
