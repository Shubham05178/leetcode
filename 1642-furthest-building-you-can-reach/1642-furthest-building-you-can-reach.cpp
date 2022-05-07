class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>mindiff;
        int noofBuildings = heights.size(), diff;  
        for(int idx = 0; idx < noofBuildings - 1; idx++){
          diff = heights[idx + 1] - heights[idx];
          if(diff > 0) {
            mindiff.push(-diff);
            if(mindiff.size() > ladders) {
                bricks += mindiff.top();
                mindiff.pop();
            }
            if(bricks < 0)
              return idx;
          }
        }
      return noofBuildings-1; 
    }
};