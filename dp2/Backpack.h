class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // f[i][j] = “前i”个数，取出一些能否组成和为j
        vector<vector<bool> > f(A.size() + 1, vector<bool>(m + 1, false));
        for(int i = 0; i <= A.size(); i++) {
            f[i][0] = true;
        }
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j <= m; j++){
                f[i+1][j] = f[i][j]; // 不取A[i]
                if(j >= A[i] && f[i][j - A[i]]){ // 取A[i]
                    f[i+1][j] = true;
                }
            }
        }
        for(int i = m; i >= 0; i--){
            if(f[A.size()][i]){
                return i;
            }
        }
        return 0;
    }
};
