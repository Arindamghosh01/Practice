class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int x = 1, size = n*n, i = 0, j = 0, cnt = 0;
        while (1) {
            if (i < n && i >= 0 && j < n && j >= 0 && ans[i][j] == 0) {
                ans[i][j] = x++;
            }
            else {
                switch (cnt % 4) {
                    case 0:
                        j--;
                        break;
                    case 1:
                        i--;
                        break;
                    case 2:
                        j++;
                        break;
                    case 3:
                        i++;
                        break;
                }
                cnt++;
            }
            
            switch (cnt % 4) {
                case 0:
                    j++;
                    break;
                case 1:
                    i++;
                    break;
                case 2:`
                    j--;
                    break;
                case 3:
                    i--;
                    break;
            }
            if (x > size)
                break;

        }
        return ans;
    }
};