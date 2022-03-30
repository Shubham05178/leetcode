/**
* Leetcode Problem - https://leetcode.com/problems/find-center-of-star-graph/
* Author - Shubham Nagaria
* Date - 31st March 2022
Find Center of Star Graph
**/
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        int freq[n+2];
        memset(freq,0,sizeof(freq));
        for(auto i: edges){
            if(freq[i[0]]>0) return i[0];
            if(freq[i[1]]>0) return i[1];
            freq[i[0]]++;
            freq[i[1]]++;
        }
        return 0;
    }
};