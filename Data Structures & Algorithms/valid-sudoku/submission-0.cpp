class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<uint32_t> row(9);
        vector<uint32_t> col(9);
        vector<uint32_t> block(9);

        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[i].size(); ++j){
                if(board[i][j] == '.') continue;

                int val = board[i][j] - '1';
                uint32_t mask = 1 << val;

                if((row[i] & mask) || (col[j] & mask) || (block[(i / 3) * 3 + j / 3] & mask)){
                    return false;
                }

                row[i] |= mask;
                col[j] |= mask;
                block[(i / 3) * 3 + j / 3] |= mask;
            }
        }

        return true;
    }
};
