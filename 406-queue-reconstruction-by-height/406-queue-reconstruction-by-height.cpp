class Solution {
public:
    bool static comp(vector<int>first, vector<int>second){
        if(first[0] == second[0])
            return first[1]<second[1];
        return first[0]>second[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),comp);
        int size = people.size();
        vector<vector<int>>ans;
        for(auto peop : people) 
            ans.insert(ans.begin() + peop[1], peop);
        return ans;
    }
};