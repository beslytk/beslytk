/**
 * @file k_freqElements.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-02
 * 
 * @copyright Copyright (c) 2022
 * 
 * https://leetcode.com/problems/top-k-frequent-elements/
 */
#include<bits/stdc++.h>
using namespace std;

  vector<int> topKFrequent(vector<int>& nums, int k) {
    std::unordered_map<int, int> freq;
    std::vector<int> ret;
    ret.reserve(nums.size());
    for (auto n : nums) {
      if (1 == ++freq[n]) {
        // Count the frequency for each int, storing each new int as we go
        ret.push_back(n);
      }
    }

    // Pivot around the kth element using custom compare. Elements are not sorted, just
    // reordered such that all elements in the range [0, k] are greater than those in [k + 1, n)
    // This is an (average) O(n) operation
    std::nth_element(ret.begin(), ret.begin() + k - 1, ret.end(), [&freq] (int l, int r) -> bool {
        return freq[l] > freq[r];
      });
    ret.resize(k);
    return ret;
  }

  //using custom recursive quick select impl
  vector<int> topKFrequentRec(vector<int>& nums, int k) {
    std::unordered_map<int, int> freq;
    std::vector<int> ret;
    for (auto n : nums) {
      // Count the frequency for each int, storing each new int as we go
      if (1 == ++freq[n]) {
        ret.push_back(n);
      }
    }
    // sorting such that first k elements are sorted higher value
    std::function <void (int lo, int hi)> quick_select;
    quick_select = [&freq, &ret, k, &quick_select] (int lo, int hi) -> void {
        int pivot_freq = freq[ret[hi]];
        int idx = lo;
        // Move all elements that have a greater frequency than our pivot to be at the front 
        for (int i = lo; i < hi; ++i) {
          if (freq[ret[i]] >= pivot_freq) {
            swap(ret[i], ret[idx++]);
          }
        }
        swap(ret[hi], ret[idx]);
        if (idx == k - 1) {
          return;
        } else if (idx < k - 1) {
          // Not enough elements selected
          return quick_select(idx, hi);
        } else {
          // Too many elements selected
          return quick_select(lo, idx - 1);
        }
      };

    quick_select(0, ret.size());
    ret.resize(k);
    return ret;
  }

  //using custom iterative impl of quick select
  vector<int> topKFrequentIter(vector<int>& nums, int k) {
  std::unordered_map<int, int> freq;
  std::vector<int> ret;
  ret.reserve(nums.size());
  for (auto n : nums) {
    if (1 == ++freq[n]) {
      // Count the frequency for each int, storing each new int as we go
      ret.push_back(n);
    }
  }

  // Find the top k most frequent using O(n) time, O(1) space quick select 
  int lo = 0;
  int hi = ret.size();
  int idx = lo;
  for (;;) {
    int pivot_freq = freq[ret[hi]];
    // Move all elements that have a greater frequency than our pivot to be at the front 
    for (int i = lo; i < hi; ++i) {
      if (freq[ret[i]] >= pivot_freq) {
        swap(ret[i], ret[idx++]);
      }
    }
    swap(ret[hi], ret[idx]);

    if (idx == k - 1) {
      break;
    } else if (idx < k - 1) {
      // Not enough elements selected
      lo = idx;
    } else if (idx > k - 1) {
      // Too many elements selected
      hi = idx - 1;
      idx = lo;
    }
  }

  ret.resize(k);
  return ret;
}

int main(){

    vector<int> nums {1,2,2,3,3,3,3,3,2,1,1,1,3,4,4};
    int k=2;
    vector<int> outArr = topKFrequent(nums, k);

    for(auto n:outArr){
        cout<< n << ", ";
    }

    return 0;
}