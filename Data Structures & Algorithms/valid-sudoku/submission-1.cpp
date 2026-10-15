class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> rows, cols, squares;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue;
                if (rows[i].find(c) != rows[i].end()) return false;
                if (cols[j].find(c) != cols[j].end()) return false;
                if (squares[(i / 3) * 3 + (j / 3)].find(c) != squares[(i / 3) * 3 + (j / 3)].end())
                    return false;

                rows[i].insert(c);
                cols[j].insert(c);
                squares[(i / 3) * 3 + (j / 3)].insert(c);
            }
        }
        return true;
    }
};
