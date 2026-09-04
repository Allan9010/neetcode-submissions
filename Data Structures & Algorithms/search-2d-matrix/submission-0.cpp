class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int head = 0;
        int tail = m * n - 1;

        while(tail >= head){
            int mid = (tail + head) / 2;
            int row = mid / m;
            int col = mid % m;
            
            if(matrix[row][col] > target) tail = mid - 1;
            else if(matrix[row][col] < target) head = mid + 1;
            else return true;
        }

        return false;
    }
};
