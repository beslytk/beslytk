#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/**
 *  We have to assign each tasks such a way so that each task has cool down time period between them. 
    The finish time of all tasks will always depend on the task with max frequency when cool down period n > 0.
    If the max frequency of all task is maxFreq and their count is maxFreqCount then we can find the 
    finish time using the arithmetic interval formula easily. Let, we start from the time 1 assigning maxFreq
    task first. So, the last time of the maxFreq task will be => 1 + (maxFreq-1) * (n+1). Now if there is more than
    1 maxFreq task then we can assign (maxFreqCount-1) tasks after each first maxFreq task and thus the finish
    time will be

    => 1 + (maxFreq-1) * (n+1) + (maxFreqCount-1)
    => (maxFreq-1) * (n+1) + maxFreqCount

    Now this formula can give us the finish time for tasks which has size less or equal the formula output,
    otherwise the tasks size will be the final finish time.
 */
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        if(n==0)return tasks.size();
        
        int freq[26] = {0};
        int maxFreq = INT_MIN;
        for(int i=0;i<tasks.size();i++)
        {
            freq[tasks[i]-'A']++;
            maxFreq = max(maxFreq,freq[tasks[i]-'A']);
        }
        
        int maxFreqCount  = 0;
        for(int i=0;i<26;i++)if(freq[i]==maxFreq)maxFreqCount++;
        
        return max((int)tasks.size(),(maxFreq-1)*(n+1)+maxFreqCount);
    }
};


class Solution_PQ {
public:
    int leastInterval(vector<char>& tasks, int k) {
        
        //k is the wait time between 2 same tasks
        
        unordered_map<char,int> hash;
        for(int i = 0; i<tasks.size(); i++) hash[tasks[i]]++;
        
        priority_queue<int> pq; // max queue
        // push task freq to prio_queue
        for(auto it : hash) pq.push(it.second);
        
        int timer = 0;
        
        while(!pq.empty()) {
            // reset temp every iteration
            vector<int> temp;
            // run for k+1 time units irrespective of task availability in pq
            for(int i = 0; i<=k; i++) { // block of size (k+1)
                if(!pq.empty()) {
                    temp.push_back(pq.top()); // pick frequently occuring tasks (greedy)
                    pq.pop();
                }
            }
            
            for(int i = 0; i<temp.size(); i++) {
                // push the decremented task_freq_count back to prio_que until 0
                if(--temp[i] > 0) 
                    pq.push(temp[i]);
            }
            
            timer += pq.empty() ? temp.size() : k+1; // if queue is empty then we got no remaining tasks hence the current block size 
			// is temp.size() else we got a block of size k+1
        }
        return timer;
    }
};

int main(){
    
    return 0;
}