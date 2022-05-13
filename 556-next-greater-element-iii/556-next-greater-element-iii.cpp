class Solution {
public:
    int nextGreaterElement(int n) {
        string s= to_string(n);
        if(!next_permutation(s.begin(), s.end())){
          return -1;
        }
        long int a = stol(s);
        if(INT_MAX<a) return -1;
        return a;
    }
};