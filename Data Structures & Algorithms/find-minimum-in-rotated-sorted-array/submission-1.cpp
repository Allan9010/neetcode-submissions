class Solution {
public:
    int findMin(vector<int> &nums) {
        int nums_size = nums.size();

        int tail = nums_size - 1;
        int head = 0;
        while(head < tail){
            int mid = head + (tail - head) / 2;
            if(nums[mid] > nums[tail]) head = mid + 1;
            else tail = mid;
        }

        return nums[head];
    }
};
//找到大變小的邊界(原本都是上升)
//兩邊都是上升
//左一定大於右