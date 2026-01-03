// Alien Dictionary
// Kahn's algo (TOPO SORT)

class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;

        for(auto& word : words){
            for(auto& c : word){
                indegree[c] = 0;
            }
        }

        for(int i = 0;i < words.size() - 1;i++){
            string w1 = words[i];
            string w2 = words[i + 1];

            int len = min(w1.size(), w2.size());

            bool foundDiff = false;

            for(int j = 0;j < len;j++){
                if(w1[j] != w2[j]){
                    adj[w1[j]].push_back(w2[j]);
                    indegree[w2[j]]++;

                    foundDiff = true;
                    break;
                }
            }

            if(!foundDiff && w1.size() > w2.size()){
                return "";
            }
        }

        queue<char> q;

        for(auto& [c, degree] : indegree){
            if(degree == 0){
                q.push(c);
            }
        }

        string order;

        while(!q.empty()){
            int c = q.front();
            q.pop();
            order.push_back(c);

            for(char i : adj[c]){
                indegree[i]--;

                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }

        if(order.size() != indegree.size()) return "";

        return order;
    }
};
