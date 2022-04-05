/**
* Leetcode Problem - https://leetcode.com/problems/course-schedule-ii/
* Author - Shubham Nagaria
* Date - 6th April 2022
Course Schedule II
**/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>res;
        vector<int>graph[numCourses];
        vector<int>indegree(numCourses,0);
        queue<int>q;
        int c = 0;
        for(auto i : prerequisites){
            indegree[i[0]]++;
            graph[i[1]].push_back(i[0]);
        }
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        while(q.size()>0){
            int x= q.front();
            q.pop();
            res.push_back(x);
            c++;
            for(int i : graph[x]){
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }
        if(c == numCourses)
            return res;
        return {};
    }
};