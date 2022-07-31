#include <bits/stdc++.h>
using namespace std;

/*
    Topological Sort - Leetcode 269
    Kahn’s algorithm for Topological Sorting
    https://leetcode.com/problems/alien-dictionary/

    A DAG G has at least one vertex with in-degree 0 and one vertex with out-degree 0. 
    Given list of words in another language, return string such that:
    Letters are sorted in lexicographical incr order wrt this language
    Ex. words = ["wrt","wrf","er","ett","rftt"]

    Build graph + record edges, BFS + topological sort, check cyclic
    https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
    
    Time: O(n)
    Space: O(n)
    Related: courseSchedule2 : https://leetcode.com/problems/course-schedule-ii/
*/

class Solution {
public:
    string alienOrder(vector<string> &words) {
        
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> indegree;// find all unique letters
        // in-degree => no. of incoming edges
        // indegree make all char 0
        for(auto word : words){
            for(auto c : word){
                indegree[c]=0;
            }
        }
        // build graph, record indegree, find all edges
        for(int i=0; i<words.size()-1; i++){
            // get word pair to compare
            string curr = words[i];
            string next = words[i+1];
            
            bool flag = false; // to detect if given list has invalid sorting

            int len = min(curr.length(), next.length());
            for(int j=0; j<len; j++){
                char ch1 = curr[j];
                char ch2 = next[j];
                // ch1 comes before ch2 as words are sorted acc to alien dict
                if(ch1 != ch2){
                    unordered_set<char> set;
                    // if ch1->set() already in graph
                    if(graph.find(ch1) != graph.end()){
                        set = graph[ch1]; // get existing set()
                        // if ch2 not already in that set
                        if(set.find(ch2) == set.end()){
                            set.insert(ch2);
                            indegree[ch2]++;
                            graph[ch1] = set;
                        }
                    }else{
                        set.insert(ch2);
                        indegree[ch2]++;
                        graph[ch1] = set;
                    }

                    flag = true;
                    break;
                }
                
            }
            // if all char in prefix are same (flag == false)
            // (curr.length() > next.length() -> invalid case.
            if(flag == false and (curr.length() > next.length())) return "";
        }// all words compared and adjacency list created

        // minHeap
        priority_queue<char, vector<char>, greater<char>> q;
        
        // The first vertex in topological sorting is always a vertex 
        // with an in-degree of 0 (a vertex with no incoming edges).
        for(auto it : indegree){
            if(it.second == 0){
                //cout<<it.first<<endl;
                // push-to-que all nodes with in-degree 0
                q.push(it.first);
            }
        }

        int count=0;
        string ans = "";
        // Kahn’s algorithm for Topological Sorting
        // bfs + topological sort
        while(q.size()>0){
            auto rem = q.top();
            q.pop();

            ans += rem;
            count++;

            if(graph.find(rem) != graph.end()){
                unordered_set<char> nbrs = graph[rem];
                
                // iterate on the neighbour list
                for(auto nbr : nbrs){
                    indegree[nbr]--;
                    if(indegree[nbr] == 0){
                        q.push(nbr);
                    }
                }
            }
        }
        // If the count of visited nodes is not equal to the number of nodes in the graph 
        // then the topological sort is not possible for the given graph.
        if(count == indegree.size()){
            return ans;
        }
        return "";
    }
};
    
int main(){
    
    return 0;
}