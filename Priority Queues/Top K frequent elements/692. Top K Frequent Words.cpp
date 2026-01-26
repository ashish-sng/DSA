// 692. Top K Frequent Words

class Solution {
public:
    struct cmp {
        bool operator()(const pair<int, string>& a,
                        const pair<int, string>& b) {
            if (a.first != b.first)
                return a.first > b.first; // smaller frequency first
            return a.second < b.second;   // lexicographically larger first
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mw;
        for (auto str : words) {
            mw[str]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;

        for (auto& i : mw) {
            pq.push({i.second, i.first});
            while (pq.size() > k)
                pq.pop();
        }

        vector<string> ans;

        while (!pq.empty()) {
            pair<int, string> p = pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};