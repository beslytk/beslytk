#include <bits/stdc++.h>
using namespace std;

// Bellman-Ford Algo  Leetcode 787
// can deal with -ve weights
// Dijkstra's but modified
/*
    https://leetcode.com/problems/cheapest-flights-within-k-stops/
    Given cities connected by flights {from,to,price], also given src, dst, & k:
    Return cheapest price from src to dst "with at most k stops"

    Dijkstra's but modified, normal won't work b/c will discard heap nodes w/o finishing
    Modify: need to re-consider a node if dist from source is shorter than what we recorded
    But, if we encounter node already processed but # of stops from source is lesser,
    Need to add it back to the heap to be considered again

    Time: O(V^2 log V) -> V = number of cities
    Space: O(V^2)
*/

class Solution_Dijk {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // build adjacency matrix
        vector<vector<int>> adj(n, vector<int>(n));
        for (int i = 0; i < flights.size(); i++) {
            vector<int> flight = flights[i];
            adj[flight[0]][flight[1]] = flight[2]; //cost
        }
        
        // shortest distances/price
        vector<int> cost(n, INT_MAX);
        cost[src] = 0; // cost to reach src is 0
        
        // number of stops to reach indexth node with least possible price from src node
        vector<int> currStops(n, INT_MAX);// shortest stops
        currStops[src] = 0;
        
        // priority queue -> (cost, node, stops)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // minHeap
        // {cost, node, number_of_stops_from_src_node}
        pq.push({0, src, 0});
        
        while (!pq.empty()) {
            int currCost  = pq.top()[0];
            int currNode  = pq.top()[1];
            int currSteps = pq.top()[2];
            pq.pop();
            
            // if destination is reached, return cost to get here
            if (currNode == dst) {
                return currCost;
            }
            
            // if no more steps left, continue and empty que
            if (currSteps == k + 1) {
                continue;
            }
            
            // check & relax all neighboring edges
            for (int neighbor = 0; neighbor < n; neighbor++) {
                // to filter given costs +ve value
                if (adj[currNode][neighbor] > 0) {
                    int edgeWeight = adj[currNode][neighbor];
                    int nextStep   = currSteps + 1;
                    // check if better cost can be achieved for neighbors via current node
                    // update 'cost' array with shortest distance from source
                    int currNeighDist = currCost + edgeWeight;
                    if (currNeighDist < cost[neighbor] || nextStep < currStops[neighbor]) {
                        pq.push({currNeighDist, neighbor, nextStep});
                        cost[neighbor] = currNeighDist; // updated w/ lesser cost 
                        currStops[neighbor] = currSteps; // no. of steps for which min cost updated
                    } 
                }
            }
        }
        
        if (cost[dst] == INT_MAX) {
            return -1;
        }
        return cost[dst];
    }
};
class Solution_BF {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        return bellmanFordVariation(flights, n, src, dst, k);
    }
    
    int bellmanFordVariation(vector<vector<int>>& flights, int n, int src, int dst, int k){
        vector<int> price(n, 10000000), tempPrice(n, 10000000);
        price[src] = tempPrice[src] = 0;
        
        //Relax k+1 times
        for(int i=1; i<=k+1; i++){
            for(auto& edge: flights){
                int source = edge[0], destination = edge[1], edgeCost = edge[2];
                int newCost = price[source] + edgeCost;
                
                if(newCost < tempPrice[destination]) tempPrice[destination] = newCost;
            }

			//Copy tempPrice to price
            for(int i=0; i<n; i++) price[i] = tempPrice[i];
        }
        return price[dst] == 10000000 ? -1 : price[dst];
    }
};
// Bellman-ford
class Solution
{
    public:
        int findCheapestPrice(int n, vector<vector < int>> &flights, int src, int dst, int k)
        {
            vector<int> costs(n, INT_MAX);
            vector<int> temp(n, INT_MAX);
            costs[src] = 0;
            temp[src]  = 0;// to store costs from previous iteration

            // relax k+1 times
            for (int i = 0; i <= k; i++)
            {
                for (auto eachEdge: flights)
                {
                    int src      = eachEdge[0];
                    int dest     = eachEdge[1];
                    int edgeCost = eachEdge[2];
                    
                    if (temp[src] != INT_MAX)
                        costs[dest] = min(costs[dest], temp[src] + edgeCost);
                }

                temp = costs;
            }
            if (costs[dst] == INT_MAX)
                return -1;
            return costs[dst];
        }
};
// Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
// Output: 700
int main(){
    int n = 4;
    vector<vector<int>> flights = { {0,1,100},
                                    {1,2,100},
                                    {2,0,100},
                                    {1,3,600},
                                    {2,3,200} };
    int src = 0;
    int dst = 3;
    int k = 1;
    Solution_Dijk sol;
    cout<<"flight1: cheapest price with k stops is: "<<sol.findCheapestPrice(n, flights, src, dst, k)<<endl;

    n = 3; 
    vector<vector<int>> flights2 = {{0,1,100},{1,2,100},{0,2,500}};
    src = 0;
    dst = 2;
    k = 1;
    cout<<"flight2: cheapest price with k stops is: "<<sol.findCheapestPrice(n, flights2, src, dst, k)<<endl;

    n = 3;
    vector<vector<int>> flights3 = {{0,1,100},{1,2,100},{0,2,500}};
    src = 0;
    dst = 2;
    k = 0;
    cout<<"flight3: cheapest price with k stops is: "<<sol.findCheapestPrice(n, flights3, src, dst, k)<<endl;
    Solution sol_bf;
    cout<<"BF: flight3: cheapest price with k stops is: "<<sol_bf.findCheapestPrice(n, flights3, src, dst, k)<<endl;
    return 0;
}


// Why we need tempPrice?
// Let's take an example.

// 3
// [[0,1,100],[1,2,100],[1,2,500]]
// 0
// 2
// 0
// You can take 0 stops in going from 0 to 2, suppose you didn't take temp array, and are making changes directly in price array.
// You will make k+1 -> 0+1 = 1 relaxation only.

// Let's start: (Not taking temp array)
// 0 -> 1, original price = price[1] = Infinity, new price = 0+100 -> price[1] = 100.
// 1 -> 2, original price = price[2] = Infinity, new price = 100+100 -> price[2] = 200.
// 0 -> 2, original price = price[2] = 200 (calculated just above) < 500 -> No update.

// You see, just because, changes were made directly to price array, we didn't know that we took a stop at 1, and then moved to 2 from 1, that contradicted the condition that we can't take any stops in between.

// If you took temp array:
// Let's start: (Taking temp array)
// 0 -> 1, original price = price[1] = Infinity, new price = 0+100 -> tempPrice[1] = 100. //tempPrice is updated, not price.
// 1 -> 2, original price = price[2] = Infinity, new price = price[1] (Infinity) + 100 -> tempPrice[2] = Infinity.
// 0 -> 2, original price = price[2] = Infinity,new price = price[0] + 500 -> which is smaller than infinity -> Update tempPrice[2] = 500.

// Hence price[2] = 500 taking 0 stops in between.