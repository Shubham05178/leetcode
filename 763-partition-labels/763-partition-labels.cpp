/**
* Leetcode Problem - https://leetcode.com/problems/partition-labels/
* Author - Shubham Nagaria
* Date - 21st March 2022
Partition Labels
**/
class Solution {
public:
    vector<int> partitionLabels(string s) {
    int n = s.size();
    vector<int>res;
    unordered_map<char,int>mp;
    for(int i = 0; i < n; i++)
        mp[s[i]]=i;
    int count = 0, curr = mp[s[0]];
    for(int i = 0; i < n; i++){
        count++;
        if(curr < mp[s[i]])
            curr = mp[s[i]];
        if(curr == i){
            res.push_back(count);
            count=0;
        }
    }
    return res;
    }
};