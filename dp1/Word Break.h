class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    int getmaxlen(unordered_set<string> &dict){
        int maxlen = 0;
        for(auto it = dict.begin(); it != dict.end(); it++) {
            maxlen = max((int)((*it).size()), maxlen);
        }
        return maxlen;
    }
    bool wordSegmentation(string s, unordered_set<string> &dict) {
        if(s.size() == 0) {
            return true;
        }
        vector<bool> f(s.size() + 1, false); // f[j]: result of string whose length is j
        f[0] = true;
        int maxlen = getmaxlen(dict);
        for(int len = 1; len <= s.size(); len++){
            for(int j = max(len - maxlen, 0); j < len; j++) {
                string subword = s.substr(j, len - j);
                if(f[j] && dict.find(subword) != dict.end()){
                    f[len] = true;
                    break;
                }
            }
        }
        return f[s.size()];
    }
};
