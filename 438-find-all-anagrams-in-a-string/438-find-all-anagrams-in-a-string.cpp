class Solution {
public:
    vector<int> findAnagrams(string B, string A) {
    unordered_map < char , int > mp;
    int need = A.size();
    int m = need;
    int n = B.size();
    vector<int> res;
    for( char c : A )
        mp[c]++;
    for(int i =0; i < n ; i++ ){
        if(i- m >= 0 && ++ mp[B[i - m]] > 0) need++;
        mp[B[i]]--;
        if(mp[B[i]] > -1 ) need--; 
        if(need == 0 )
            res.push_back(i - m + 1);
    }
    return res;
    }
};