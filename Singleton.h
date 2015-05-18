class Solution {
private:
    static Solution *s; 
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        if(s == NULL){
            s = new Solution();
        }
        return s;
    }
};
Solution* Solution::s = NULL; 

