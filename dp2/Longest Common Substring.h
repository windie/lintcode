class Solution {
public:
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        if(A.size() == 0 || B.size() == 0){
            return 0;
        }
        vector<vector<int> > f(A.size(), vector<int>(B.size(), 0));
        // f[i][j]: lcs of string ending with A[i] and string ending with B[j]
        int res = 0;
        for(int i = 0; i < A.size(); i++){
            if(A[i] == B[0]){
                f[i][0] = 1;
                res = 1;
            }
        }
        for(int j = 0; j < B.size(); j++){
            if(A[0] == B[j]){
                f[0][j] = 1;
                res = 1;
            }
        }
        for(int i = 1; i < A.size(); i++){
            for(int j = 1; j < B.size(); j++){
                if(A[i] == B[j]){
                    f[i][j] = f[i-1][j-1] + 1;
                    res = max(res, f[i][j]);
                }
            }
        }
        return res;
    }
};

