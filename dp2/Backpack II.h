class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // f[i][j]表示前i个物品中，取出“若干”物品后，体积“正好”为j的最大价值。
        vector<vector<int> > f(A.size() + 1, vector<int> (m + 1, 0));
        for(int i = 1; i <= m; i++) {
            f[0][i] = INT_MIN;
        }
        for(int i = 0; i < A.size(); i++) {
            for(int j = 1; j <= m; j++) {
                f[i + 1][j] = f[i][j]; // 不取A[i]
                if(j >= A[i]){ // 取A[i], 取前需要判断是否可取
                    f[i + 1][j] = max(f[i + 1][j], f[i][j - A[i]] + V[i]);
                }
            }
        }
        int res = INT_MIN;
        for(int i = 1; i <= m; i++){
            res = max(res, f[A.size()][i]);
        }
        return res;
    }
};
