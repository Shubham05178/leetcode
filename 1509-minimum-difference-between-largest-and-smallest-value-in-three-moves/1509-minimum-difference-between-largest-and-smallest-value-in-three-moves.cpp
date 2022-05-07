class Solution {
public:
    int minDifference(vector<int>& nums) {
        int arrsize = nums.size();
        if(arrsize < 5) 
          return 0;
        multiset<int>maxElem, minElem;

        for(int idx = 0; idx < arrsize; idx++) {
          if(maxElem.size() < 4){
            maxElem.insert(nums[idx]);
          }
          else if( nums[idx] > *maxElem.begin()){
            maxElem.erase(maxElem.begin());
            maxElem.insert(nums[idx]);
          }
          if(minElem.size() < 4) {
            minElem.insert(nums[idx]);
          }
          else if( nums[idx] < *minElem.rbegin()){
            minElem.erase(minElem.find(*minElem.rbegin()));
            minElem.insert(nums[idx]);
          }
        }
      int mini = INT_MAX;
      auto iter1 = maxElem.begin(), iter2 = minElem.begin();
      while(iter1 != maxElem.end() && iter2 != minElem.end()){
        mini = min( mini, (*iter1) - (*iter2));
        iter1++;
        iter2++;
      }
      return mini;
    }
};  

//[20,66,68,57,45,18,42,34,37,58]
//[18,20,34,37,42,45,57,58,66,68]
// [1,5,0,10,14]
// [0,1,5,10,14] 
// [0,1,5]   [ 5, 10, 14]
//[6,6,0,1,1,4,6]
// [0,1,1,4,6,6,6]
    // [0,1,1,4] [4,6,6,6]