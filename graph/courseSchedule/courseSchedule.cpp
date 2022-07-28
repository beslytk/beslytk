#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Directed Graph
    Courses & prerequisites, return true if can finish all courses
    Ex. numCourses = 2, prerequisites = [[1,0]] -> true

    All courses can be completed if there's no cycle (visit already visited)

    Time: O(V + E)
    Space: O(V + E)
    https://leetcode.com/problems/course-schedule/
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // map each course to prereq list
        // Adjacency List
        unordered_map<int, vector<int> > preReqMap;
        // constraint: prerequisites[i].length == 2
        for (int i = 0; i < prerequisites.size(); i++) {
            preReqMap[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        // to mark all visited courses along current DFS path
        unordered_set<int> visited;
        // need to iterate over all course, since there
        // could be disconnected courses
        for (int course = 0; course < numCourses; course++) {
            if (!dfs(course, preReqMap, visited)) {
                return false;
            }
        }
        return true;
    }
private:
    bool dfs(int course, unordered_map<int, vector<int>>& preReqMap, unordered_set<int>& visited) {
        if (visited.find(course) != visited.end()) {
            return false; // cycle detected in current dfs
        }
        if (preReqMap[course].empty()) {
            return true; // courses w/o prerequisite
        }
        visited.insert(course);
        for (int i = 0; i < preReqMap[course].size(); i++) {
            int nextCourse = preReqMap[course][i];
            if (!dfs(nextCourse, preReqMap, visited)) {
                return false;
            }
        }
        // clear preReq list for current course as all preReq
        // are verified as able for completion
        preReqMap[course].clear();
        // clear current course from Visited as its no longer along path
        visited.erase(course);
        return true;
    }
}; 

int main(){
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0},{0,1}};
    Solution sol;
    
    cout<< "can the courses be finished: "<< sol.canFinish(numCourses, prerequisites)<<endl;
    numCourses = 5;
    vector<vector<int>> prerequisites1 = {{0,1},{0,2},{1,3},{1,4},{3,4}};
    cout<< "can the courses be finished: "<< sol.canFinish(numCourses, prerequisites1)<<endl;
    return 0;
}