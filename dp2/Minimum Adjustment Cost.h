class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        // f[i][v] 前i个数，第i个数调整为v，满足相邻两数<=target，所需要的最小代价
        int range = 101;
        vector<vector<int> > f(A.size(), vector<int>(range, INT_MAX));
        // init
        for(int j = 1; j < range; j++){
            f[0][j] = abs(j - A[0]);
        }
        for(int i = 1; i < A.size(); i++) {
            for(int j = 1; j < range; j++) {
                // f[i][j] = 找到所有可能的v_previous，求最小的f[i - 1][v_previous]，加上A[i]要转换为j的代价
                for(int v_prev = 1; v_prev < range; v_prev++) {
                    if(abs(j - v_prev) > target){
                        continue;
                    }
                    f[i][j] = min(f[i][j], f[i - 1][v_prev] + abs(j - A[i]));
                }
            }
        }
        // res = 所有可能的v中转换代价最小的
        int res = INT_MAX;
        for(int i = 1; i < range; i++){
            res = min(res, f[A.size() - 1][i]);
        }
        return res;
    }
};
