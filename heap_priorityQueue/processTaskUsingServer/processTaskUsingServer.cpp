#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
// https://leetcode.com/problems/process-tasks-using-servers
// Here, we have two min heaps, ordered by [time, weight, index]: available and busy. First, we put all servers into the available heap with time equals to zero.

// As we process our tasks:

// Move servers that have finished (time <= t) from busy to avail.
// Pick the top server from the avail heap and move it to the busy heap with time = t + tasks[t].
// This is where we record the index of the server for that task.
// What happens if no servers are available? In this case, the server that is closest to finishing its task will pick up the new task. So:

// We move the top server from busy to avail heap.
// Then we move it back to the busy heap, but this time we extend the completion time for the duration of the new task time + task[t].
// In other words, the time is t + task[t] if we have an available server vs. time + task[t].
vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
    priority_queue<array<long, 3>, vector<array<long, 3>>, greater<array<long, 3>>> avail, busy;
    vector<int> res;
    for (int i = 0; i < servers.size(); ++i)
        avail.push({ 0, servers[i], i });
    for (long t = 0; t < tasks.size(); ++t) {
        while(!busy.empty() && (busy.top()[0] <= t || avail.empty())) {
            auto [time, w, i] = busy.top(); busy.pop();
            avail.push({ time <= t ? 0 : time, w, i });
        }
        auto [time, w, s] = avail.top(); avail.pop();
        busy.push({ max(time, t) + tasks[t], w, s });
        res.push_back(s);
    }
    return res;
} 

int main(){
    
    return 0;
}