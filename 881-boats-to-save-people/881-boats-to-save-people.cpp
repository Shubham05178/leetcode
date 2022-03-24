/**
Leetcode Problem - https://leetcode.com/problems/boats-to-save-people/
Author - Shubham Nagaria
Date - 24th March 2022
Boats to Save People
**/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
       sort(people.begin(),people.end());
        int c = 0, w1, diff, j = people.size() - 1, i = 0;
        while(i<=j){
            if(people[i]+people[j]<=limit)
                i++;
            j--;
            c++;
        }
        return c;
    }
};