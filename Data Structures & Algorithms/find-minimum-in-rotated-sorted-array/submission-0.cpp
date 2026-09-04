class Solution {
public:
    int findMin(vector<int> &nums) {
        int nums_size = nums.size();
        if(nums[0] <= nums[nums_size - 1]) return nums[0];

        int tail = nums_size - 1;
        int head = 0;
        int ans = 0;
        while(head <= tail){
            int mid = (tail + head) / 2;
            if(nums[mid] > nums[tail]) head = mid + 1;
            else if(nums[mid] < nums[tail]) tail = mid;
            else return nums[tail]; 
        }

        return -1;
    }
};
//找到大變小的邊界(原本都是上升)
//兩邊都是上升
//左一定大於右