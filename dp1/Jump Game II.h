class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    // int jump(vector<int> A) {
    //     if(A.size() <= 1) {
    //         return 0;
    //     }
    //     vector<int> f(A.size());
    //     f[0] = 0;
    //     for(int i = 1; i < A.size(); i++) {
    //         int tmpres = INT_MAX;
    //         for(int j = 0; j < i; j++) {
    //             if(A[j] + j >= i && f[j] < tmpres){
    //                 tmpres = f[j];
    //             }
    //         }
    //         if(tmpres != INT_MAX) {
    //             f[i] = tmpres + 1;
    //         }else{
    //             f[i] = INT_MAX;
    //         }
    //     }
    //     return f[A.size() - 1];
    // }
    int jump(vector<int> A) {
        int cnt= 0, step_max = 0, one_more_step_max = 0;
        // step_max: distance can jump using cnt steps
        // one_more_step_max: distance can jump using cnt+1 steps
        for(int i = 0; i < A.size(); i++){
            if(i > step_max){
                cnt++;
                step_max = one_more_step_max;
            }
            one_more_step_max = max(one_more_step_max, i + A[i]);
        }
        return cnt;
    }
};
