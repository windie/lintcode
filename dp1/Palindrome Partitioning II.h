class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    void calPalindrome(vector<vector<bool> > &f, string &s) {
        for(int i = f.size() - 1; i >= 0; i--) {
            for(int j = i; j < f.size(); j++) {
                if(s[j] == s[i] && (j - i <= 2 || f[i+1][j-1])){
                    f[i][j] = true;
                }
            }
        }
    }

    int minCut(string s) {
        if(s.size() == 0) {
            return 0;
        }
        vector<vector<bool> > ispalin(s.size(), vector<bool>(s.size(), false)); // ispalin[i][j] = whether s[i,j] is palindrome
        calPalindrome(ispalin, s);
        vector<int> res(s.size() + 1, s.size() - 1); // res[i] mincut of s[0, i)
        res[0] = 0;
        for(int len = 1; len <= s.size(); len++) {
            if(ispalin[0][len-1]){
                res[len] = 0;
                continue;
            }
            for(int j = 1; j < len; j++) {
                if(ispalin[j][len-1]){
                    res[len] = min(res[j] + 1, res[len]);
                }
            }
        }
        return res[s.size()];
    }
};


