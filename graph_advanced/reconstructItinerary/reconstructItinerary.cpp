#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    https://leetcode.com/problems/reconstruct-itinerary/
    Given airline tickets, find valid itinerary (use all tickets once)
    Ex. tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
        output  = ["JFK","MUC","LHR","SFO","SJC"]

    Greedy DFS, build route backwards when retreating, merge cycles into main path
    
    *The normal DFS/BFS algorithms help us traverse all nodes in the graph, but fail
    to cover all edges in the graph, so we need to look for something more special.*
    
    An Eulerian Path is a list of all edges in a graph in a sequence such that you can 
    go from point A to all other nodes in the graph multiple times, as long as an edge is not visited.
    This should solve our problem.
    Eulerian Path can be implemented using a slightly modified version of DFS

    Note: Elements in a multiset are always sorted following a specific strict weak  
    ordering criterion indicated by its internal comparison object (of type Compare).
    The value of the elements in a multiset cannot be modified once in the container
    (the elements are always const), but they can be inserted or removed from the container.
    
    Time: O(E log (E / V)) -> E = # of flights, V = # of airports, sorting
    Space: O(V + E) -> store # of airports & # of flights in hash map
*/
// https://leetcode.com/problems/reconstruct-itinerary/discuss/897615/C%2B%2B-DFS-Euler-Walk-O(E-Log-E)-Solution
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // adjacency list with all possible destinations for current source
        unordered_map<string, multiset<string>> adjacencyMap;
        for (int i = 0; i < tickets.size(); i++) {
            adjacencyMap[tickets[i][0]].insert(tickets[i][1]);
        }
        
        vector<string> result;
        dfs(adjacencyMap, "JFK", result);
        reverse(result.begin(), result.end());
        return result;
    }
private:
    void dfs(unordered_map<string, multiset<string>>& adjacencyMap,
                            string airport, vector<string>& result) {
        // If node has any edge call DFS with the edge destination node
        // also remove the edge as we will not visit the edge again (Euler walk)
        while (!adjacencyMap[airport].empty()) {
            string next = *adjacencyMap[airport].begin();
            adjacencyMap[airport].erase(adjacencyMap[airport].begin());
            // dfs to next airport
            dfs(adjacencyMap, next, result);
        }
        // after entire recursion is complete, start adding to result
        // last airport in result list pushed first
        result.push_back(airport);
        cout<<airport<<"<--";
    }
}; 

int main(){
    vector<vector<string>> tickets = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
    Solution sol;
    vector<string> out = sol.findItinerary(tickets);
    cout<<endl;
    vector<vector<string>> tickets2 = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    vector<string> out2 = sol.findItinerary(tickets2);
    return 0;
}

// This is the variation of dfs.
// The way to tweak the dfs is to not to put a base condition and let the dfs fill the stack and empty itself
//
// Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
// Lets say we built a graph of this and its adjacenecy list look like this:-
// JFK - MUC
// MUC - LHR
// LHR - SFO
// SFO - SJC

// So when we perform a dfs on JFK

// |        |
// |        |
// |        |   <-----Recursion Stack
// |        |
// |__JFK___|

// We explore JFKs neighbors 

// |        |
// |        |
// |        |
// |  MUC   |
// |__JFK___|

// We explore Muc neighbors

// |        |
// |        |
// |  LHR   |
// |  MUC   |
// |__JFK___|

// |        |
// |  SFO   |
// |  LHR   |
// |  MUC   |
// |__JFK___|

// |  SJC   |
// |  SFO   |
// |  LHR   |
// |  MUC   |
// |__JFK___|

// Since SJC has no neighbors we pus it back to the answer

// |        |
// |  SFO   |      ans=SJC
// |  LHR   |
// |  MUC   |
// |__JFK___|

// |        |
// |        |      ans=SJC,SFO
// |  LHR   |
// |  MUC   |
// |__JFK___|

// |        |
// |        |      ans=SJC,SFO,LHR
// |        |
// |  MUC   |
// |__JFK___|


// |        |
// |        |      ans=SJC,SFO,LHR,MUC 
// |        |
// |        |
// |__JFK___|

// |        |
// |        |      ans=SJC,SFO,LHR,MUC,JFK 
// |        |
// |        |
// |________|

// We reverse the array and return it.