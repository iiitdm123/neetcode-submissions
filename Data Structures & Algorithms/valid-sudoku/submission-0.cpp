class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 0(0 to 2, 0 to 2),1 (0 to 2, 3 to 5),2 (0 to 2, 6 to 8)
        // 3(3 to 5, 0 to 2),4(3 to 5, 3to 5),5 (3 to 5, 6 to 8)
        // 6(6 to 8, 0 to 2),7(6 to 8, 3 to 5),8(6 to 8, 6 to 8)
        map<int, set<int>> rows, cols, squares;
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
