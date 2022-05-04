class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
      multiset<int>s;
      int count = 0;
      for(int i : nums){
        if(s.find(k - i) != s.end()){
          s.erase(s.find(k - i));
          count++;
        }
        else 
          s.insert(i);
      }
    return count;
    }
};