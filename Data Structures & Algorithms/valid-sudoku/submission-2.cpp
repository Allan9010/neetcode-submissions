class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        array<uint32_t, 9> row = {0};
        array<uint32_t, 9> col = {0};
        array<uint32_t, 9> block = {0};

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
