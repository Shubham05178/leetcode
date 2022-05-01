class Solution {
public:
    int longestConsecutive(vector<int>& nums) {  
 	    unordered_set<int>presenceElem;
	    for(auto &i : nums)
		  presenceElem.insert(i);
  	  int maxChainLength = 0, chain, j;
	    for(auto &i : nums) {
    	  	if(presenceElem.find(i-1) == presenceElem.end()){
			      chain = 1;
			      j = i;
		      	while( presenceElem.find(j+1) != presenceElem.end()){
				      chain++;
				       j++;
			      }
			      maxChainLength = max(maxChainLength, chain);
		      }
	    } 
	    return maxChainLength;
    }
};