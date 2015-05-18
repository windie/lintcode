class Solution {
public:
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // f[i][j] = number of distinct subsequences of T[0, j) in S[0, i)
        vector<vector<int> > f(S.size() + 1, vector<int> (T.size() + 1, 0));
        // init
        for(int i = 0; i <= S.size(); i++) {
            f[i][0] = 1;
        }
        for(int i = 0; i < S.size(); i++){
            for(int j = 0; j <= i && j < T.size(); j++){
                if(S[i] == T[j]) {
                    f[i + 1][j + 1] = f[i][j] + f[i][j + 1]; // 取s[i]
                }else{
                    f[i + 1][j + 1] = f[i][j + 1]; // 不取s[i]
                }
            }
        }
        return f[S.size()][T.size()];
    }
};

