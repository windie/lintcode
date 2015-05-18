class Solution {
public:
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        vector<vector<int> > f(word1.size() + 1, vector<int> (word2.size() + 1, 0));
        // f[i][j]: edit distance of word1[0, i-1] and word2[0, j-1]
        for(int i = 0; i <= word2.size(); i++){
            f[0][i] = i;
        }
        for(int i = 0; i <= word1.size(); i++){
            f[i][0] = i;
        }
        for(int i = 1; i <= word1.size(); i++){
            for(int j = 1; j <= word2.size(); j++){
                if(word1[i-1] == word2[j-1]){
                    f[i][j] = f[i-1][j-1];
                }else{
                    f[i][j] = min(min(f[i-1][j], f[i][j-1]), f[i-1][j-1]) + 1;
                }
            }
        }
        return f[word1.size()][word2.size()];
    }
};

