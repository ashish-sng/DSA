//973. K Closest Points to Origin

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;

        for (auto& i : points) {
            pq.push({(pow(i[0], 2) + pow(i[1], 2)), {i[0], i[1]}});
            while (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;

        while (pq.size()) {
            pair<int, pair<int, int>> front = pq.top();
            pq.pop();
            vector<int> curr = {front.second.first, front.second.second};
            ans.push_back(curr);
        }

        return ans;
    }
};