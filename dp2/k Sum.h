class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        // f[i][j][t]前i个数取j个数出来和为t的方案数
        vector<vector<vector<int> > > f(A.size() + 1, 
                vector<vector<int> > (k + 1, vector<int> (target + 1, 0)));
        // init
        for(int i = 0; i <= A.size(); i++) {
            f[i][0][0] = 1;
        }
        for(int i = 0; i < A.size(); i++){
            for(int j = 1; j <= k; j++){
                for(int x = 1; x <= target; x++){
                    f[i+1][j][x] = f[i][j][x]; // 不取A[i]
                    if(x >= A[i]){
                        f[i+1][j][x] += f[i][j-1][x - A[i]]; // 取A[i]
                    }
                }
            }
        }
        return f[A.size()][k][target];
    }
};
