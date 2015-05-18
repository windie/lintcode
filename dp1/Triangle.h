class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.size() == 0 || triangle[0].size() == 0) {
            return 0;
        }
        int m = triangle[triangle.size()-1].size();
        vector<int> f(m, 0);
        for(int i = 0; i < m; i++){
            f[i] = triangle[triangle.size()-1][i];
        }
        for(int i = triangle.size()-2; i >= 0; i--){
            for(int j = 0; j < triangle[i].size(); j++){
                f[j] = min(f[j], f[j+1]) + triangle[i][j];
            }
        }
        return f[0];
    }
};

