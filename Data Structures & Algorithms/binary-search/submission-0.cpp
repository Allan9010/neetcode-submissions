class Solution {
public:
    int search(vector<int>& nums, int target) {
        int head = 0;
        int tail = nums.size() - 1;

        while(head <= tail){
            int mid = (tail + head) / 2;
            if(nums[mid] > target) tail = mid - 1;
            else if(nums[mid] < target) head = mid + 1;
            else return mid;
        }
        return -1;
    }
};
