class Solution {
public:
    /**
     * @param s: A string
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    int len(const char *s){
        char *p = (char *) s;
        int length = 0;
        while(*p){
            length++;
            p++;
        }
        return length;
    }
    bool isMatch(const char *s, const char *p) {
        int m = len(s), n = len(p);
        if(n == 0) {
            return m == 0 ? true : false;
        }
        if(m == 0) {
            return *p == '*' ? true : false;
        }
        // f[i][j]: s[0,i)与p[0,j)是否matched
        vector<vector<bool> > f(m + 1, vector<bool>(n + 1, false));
        // init
        f[0][0] = true;
        for(int i = 1; i <= n; i++){
            f[0][i] = f[0][i - 1] && p[i - 1] == '*';
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(p[j] == '*') {
                    f[i + 1][j + 1] = f[i][j + 1] || f[i + 1][j];
                }else if(p[j] == '?') {
                    f[i + 1][j + 1] = f[i][j];
                }else {
                    f[i + 1][j + 1] = (p[j] == s[i]) && f[i][j];
                }
            }
        }
        return f[m][n];
    }
};

