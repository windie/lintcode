class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0){
            return 0;
        }
        vector<vector<int> > f(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            f[i][0] = 1;
        }
        for(int j = 0; j < n; j++){
            f[0][j] = 1;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                f[i][j] = f[i-1][j] + f[i][j-1];
            }
        }
        return f[m-1][n-1];
    }
};

