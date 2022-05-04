class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
      unordered_map<int,int>freq;
      int count = 0;
      for(int &i : nums) {
        if(freq[ k - i]> 0) {
          freq[k - i]--;
          count++;
        }
        else 
          freq[i]++;
      }
    return count;
    }
};