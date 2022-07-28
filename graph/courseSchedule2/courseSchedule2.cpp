#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Directed Graph
    Courses & prerequisites, return ordering of courses to take to finish all courses
    Ex. numCourses = 2, prerequisites = [[1,0]] -> [0,1], take course 0 then 1

    All courses can be completed if there's no cycle, check for cycles

    Time: O(V + E)
    Space: O(V + E)
    https://leetcode.com/problems/course-schedule-ii/
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> preReqMap;
        // build adjacency list of prereqs
        for (int i = 0; i < prerequisites.size(); i++) {
            preReqMap[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        unordered_set<int> visit;
        unordered_set<int> cycle;
        
        vector<int> result;
        for (int course = 0; course < numCourses; course++) {
            if (!dfs(course, preReqMap, visit, cycle, result)) {
                return {};
            }
        }
        return result;
    }
private:
    // a course has 3 possible states:
    // visit -> course added to result
    // cycle -> course not added to result, but added to cycle
    // unvisited -> course not added to result or cycle
    bool dfs(int course, unordered_map<int, vector<int>>& preReqMap, unordered_set<int>& visit,
        unordered_set<int>& cycle, vector<int>& result) {
        
        if (cycle.find(course) != cycle.end()) {
            return false;
        }
        // already added to result output?
        if (visit.find(course) != visit.end()) {
            return true;
        }
        cycle.insert(course);
        for (int i = 0; i < preReqMap[course].size(); i++) {
            int nextCourse = preReqMap[course][i];
            if (!dfs(nextCourse, preReqMap, visit, cycle, result)) {
                return false;
            }
        }
        cycle.erase(course);
        // if current course and all its preRequisites can be completed
        // add current course to result.
        visit.insert(course);
        result.push_back(course);
        return true;
    }
};

int main(){
    
    return 0;
}