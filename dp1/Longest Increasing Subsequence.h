class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        vector<int> f(nums.size());
        if(nums.size() == 0){
            return 0;
        }
        f[0] = 1;
        int res = 1;
        for(int i = 1; i < nums.size(); i++) {
            f[i] = 1;
            for(int j = 0; j < i; j++) {
                if(nums[i] >= nums[j]){
                    f[i] = max(f[j] + 1, f[i]);
                }
            }
            res = max(res, f[i]);
        }
        return res;
    }
};

