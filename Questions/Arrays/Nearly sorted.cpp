// Nearly sorted -
// https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1

// Solution

// Array Approach - Gives TLE O(n * k)
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        for(int i = 0;i < n;i++){
            int minIndex = i;
            for(int j = i + 1;j <= min(n-1, i + k);j++){
                if(arr[j] < arr[minIndex]){
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
    }
};

// Optimal Solution using heap - O(n * logk)
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        int j = 0;
        for(int i = 0;i < n;i++){
            pq.push(arr[i]);
            while(!pq.empty() && pq.size() > k){
                arr[j++] = pq.top();
                pq.pop();
            }
        }
        while(!pq.empty() && j < n){
            arr[j++] = pq.top();
            pq.pop();
        }
    }
};

