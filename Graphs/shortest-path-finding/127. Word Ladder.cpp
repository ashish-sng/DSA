// 127. Word Ladder

class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (dict.find(endWord) == dict.end())
            return 0;

        queue<string> q;
        q.push(beginWord);

        int level = 1;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                string word = q.front();
                q.pop();

                // Try changing each character
                for (int i = 0; i < word.size(); i++) {
                    char original = word[i];

                    // Try all letters from 'a' to 'z'
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;

                        // If we reached the target word
                        if (word == endWord)
                            return level + 1;

                        // If new word exists in dictionary
                        if (dict.find(word) != dict.end()) {
                            q.push(word);
                            dict.erase(word); // mark visited
                        }
                    }

                    // Restore original character
                    word[i] = original;
                }
            }

            // Finished one BFS level (one transformation step)
            level++;
        }

        return 0; // no transformation found
    }
};