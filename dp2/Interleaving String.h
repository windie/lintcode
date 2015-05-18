class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }
        // f[i][j] = s1[0,i)与s2[0,j)是否为s3[0, i + j + 1]的interleaving string
        vector<vector<bool> > f(s1.size() + 1, vector<bool> (s2.size() + 1, false));
        // init
        f[0][0] = true;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] == s3[i]){
                f[i+1][0] = f[i][0];
            }
        }
        for(int j = 0; j < s2.size(); j++){
            if(s2[j] == s3[j]){
                f[0][j + 1] = f[0][j];
            }
        }
        for(int i = 0; i < s1.size(); i++) {
            for(int j = 0; j < s2.size(); j++) {
                if(s1[i] == s3[i + j + 1]) {
                    f[i + 1][j + 1] = f[i][j + 1]; // 取s1[i]
                }
                if(s2[j] == s3[i + j + 1]) {
                    f[i + 1][j + 1] = f[i + 1][j + 1] || f[i + 1][j]; // 取s2[j]
                }
            }
        }
        return f[s1.size()][s2.size()];
    }
};
