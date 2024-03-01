#include <bits/stdc++.h>
using namespace std;


bool isValidSudoku(vector<vector<char>>& board) {
    vector<unordered_set<int>> r(9),c(9), sq(9);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                int curr = board[i][j] - '0';

                if (r[j].find(curr) != r[j].end()) {
                    return false;
                }
                else {
                    r[j].insert(curr);
                }

                if (c[i].find(curr) != c[i].end())
                    return false;
                else
                    c[i].insert(curr);

                int x = i/3, y = j/3;
                if (sq[x+(y*3)].find(curr) != sq[x+(y*3)].end())
                    return false;
                else 
                    sq[x+(y*3)].insert(curr);
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> test1 = {{'5','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'},
                                  {'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','1','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'}};
    cout << isValidSudoku(test1) << '\n';
}
