/**
* Leetcode Problem - https://leetcode.com/problems/top-k-frequent-elements/
* Author - Shubham Nagaria
* Date - 9th April 2022
Top K Frequent Elements
**/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        priority_queue<pair<int,int>> pq;
        vector<int> result;
        for(int& i:nums){
            freq[i]++;
        }
        for(auto& it : freq){
            pq.push(make_pair(it.second, it.first));
            if(pq.size() > freq.size() - k){
                result.push_back(pq.top().second); pq.pop();
            }
        }
        return result;
    }
};