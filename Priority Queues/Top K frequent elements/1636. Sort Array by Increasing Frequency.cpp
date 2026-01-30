// 1636. Sort Array by Increasing Frequency

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans;
        auto cmp = [](pair<int, int>& p1, pair<int, int>& p2) {
            if (p1.first == p2.first) {
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>
            pq;
        unordered_map<int, int> mp;

        for (int i : nums) {
            mp[i]++;
        }

        for (auto& i : mp) {
            pq.push({i.second, i.first});
        }

        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();
            while (p.first--) {
                ans.push_back(p.second);
            }
        }

        return ans;
    }
};