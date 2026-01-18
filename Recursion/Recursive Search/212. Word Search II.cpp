// 212. Word Search II

class Solution {
public:
    struct TrieNode {
        TrieNode* children[26];
        string word;

        TrieNode() {
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
            word = "";
        }
    };

    vector<string> ans;
    int m, n;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& word : words) {
            TrieNode* node = root;
            for (char character : word) {
                int idx = character - 'a';
                if (!node->children[idx])
                    node->children[idx] = new TrieNode();
                node = node->children[idx];
            }
            node->word = word;
        }
        return root;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {
        char ch = board[r][c];
        if (ch == '#' || !node->children[ch - 'a'])
            return;

        node = node->children[ch - 'a'];

        if (node->word != "") {
            ans.push_back(node->word);
            node->word = "";
        }

        board[r][c] = '#';

        for (auto& d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n)
                dfs(board, nr, nc, node);
        }

        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        TrieNode* root = buildTrie(words);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }
        return ans;
    }
};
