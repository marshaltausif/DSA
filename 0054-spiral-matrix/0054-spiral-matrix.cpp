class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int srow = 0, scol = 0;
        int erow = matrix.size() - 1;
        int ecol = matrix[0].size() - 1;

        while (srow <= erow && scol <= ecol) {

            // Top row
            for (int j = scol; j <= ecol; j++)
                ans.push_back(matrix[srow][j]);

            // Right column
            for (int i = srow + 1; i <= erow; i++)
                ans.push_back(matrix[i][ecol]);

            // Bottom row
            if (srow < erow) {
                for (int j = ecol - 1; j >= scol; j--)
                    ans.push_back(matrix[erow][j]);
            }

            // Left column
            if (scol < ecol) {
                for (int i = erow - 1; i > srow; i--)
                    ans.push_back(matrix[i][scol]);
            }

            srow++; scol++;
            erow--; ecol--;
        }

        return ans;
    }
};