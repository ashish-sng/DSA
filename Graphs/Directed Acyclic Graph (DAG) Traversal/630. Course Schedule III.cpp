// 630. Course Schedule III

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto& a, auto& b){
            return a[1] < b[1];
        });

        priority_queue<int> maxHeap;

        int totalTime = 0;

        for(auto& course : courses){
            int duration = course[0];
            int deadline = course[1];

            totalTime += duration;
            maxHeap.push(duration);

            if(totalTime > deadline){
                totalTime -= maxHeap.top();
                maxHeap.pop();
            }
        
        }

        return maxHeap.size();
    }
};