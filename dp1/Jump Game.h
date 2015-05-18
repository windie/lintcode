class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    // bool canJump(vector<int> A) {
    //     if(A.size() == 0) {
    //         return false;
    //     }
    //     vector<bool> f(A.size());
    //     f[0] = true;
    //     for(int i = 1; i < A.size(); i++) {
    //         for(int j = 0; j < i; j++){
    //             if(f[j] && A[j] + j >= i){
    //                 f[i] = true;
    //                 break;
    //             }
    //         }
    //     }
    //     return f[A.size()-1];
    // }
    bool canJump(vector<int> A) {
        if(A.size() == 1) {
            return true;
        }
        int require = 1;
        for(int i = A.size() - 2; i > 0; i--) {
            if(A[i] > require){
                require = 1;
            } else {
                require++;
            }
        }
        return A[0] > require;
    }
};

