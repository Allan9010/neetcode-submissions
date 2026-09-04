class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int front = 0, back = numbers.size() - 1;
        while(front < back){
            int cursum = numbers[front] + numbers[back];
            if(numbers[front] + numbers[back] > target) back--;
            else if(numbers[front] + numbers[back] < target) front++;
            else return {front + 1, back + 1};
        }
        
        return {};
    }
};
