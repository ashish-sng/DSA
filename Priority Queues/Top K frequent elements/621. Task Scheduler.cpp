// 621. Task Scheduler

// 1. Maths approach

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for (char c : tasks) {
            freq[c - 'A']++;
        }

        int maxFreq = 0;

        for (int i : freq) {
            maxFreq = max(i, maxFreq);
        }

        int countMax = 0;

        for (int i : freq) {
            if (i == maxFreq) {
                countMax++;
            }
        }

        int calculatedTasks = (maxFreq - 1) * (n + 1) + countMax;

        int tasksSize = tasks.size();

        int ans = max(tasksSize, calculatedTasks);

        return ans;
    }
};

// 2. Priority Queue approach

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char t : tasks) {
            freq[t - 'A']++;
        }

        // Max heap of remaining task counts
        priority_queue<int> maxHeap;
        for (int f : freq) {
            if (f > 0)
                maxHeap.push(f);
        }

        // Queue for cooldown: {remainingCount, readyTime}
        queue<pair<int, int>> cooldown;

        int time = 0;

        while (!maxHeap.empty() || !cooldown.empty()) {
            time++;

            // Step 1: execute a task if possible
            if (!maxHeap.empty()) {
                int cnt = maxHeap.top();
                maxHeap.pop();
                cnt--; // one execution

                if (cnt > 0) {
                    cooldown.push({cnt, time + n});
                }
            }

            // Step 2: check if any task finishes cooldown
            if (!cooldown.empty() && cooldown.front().second == time) {
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return time;
    }
};