class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        if(A.size() == 0 || B.size() == 0){
            return 0;
        }
        vector<vector<int> > f(A.size(), vector<int>(B.size(), 0));
        // f[i][j] lcs of A[0,i] and B[0,j]
        for(int i = 0; i < A.size(); i++){
            if(A[i] == B[0]){
                f[i][0] = 1;
            }
        }
        for(int j = 0; j < B.size(); j++){
            if(A[0] == B[j]){
                f[0][j] = 1;
            }
        }
        for(int i = 1; i < A.size(); i++){
            for(int j = 1; j < B.size(); j++){
                if(A[i] == B[j]) {
                    f[i][j] = f[i-1][j-1] + 1;
                }else{
                    f[i][j] = max(max(f[i-1][j], f[i][j-1]), f[i-1][j-1]);
                }
            }
        }
        return f[A.size()-1][B.size()-1];
    }
};

