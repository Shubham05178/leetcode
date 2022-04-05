/**
* Leetcode Problem - https://leetcode.com/problems/course-schedule/
* Author - Shubham Nagaria
* Date - 5th April 2022
Course Schedule
**/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<int>graph[numCourses];
        for(auto i : prerequisites){
            indegree[i[1]]++;
            graph[i[0]].push_back(i[1]);
        }
        int c = 0;
        queue<int>q;
        for(int i =0 ; i < numCourses;i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        while(q.size() > 0){
            int x = q.front();
            c++;
            q.pop();
            for(int i : graph[x]){
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }
        return c == numCourses;
    }
};