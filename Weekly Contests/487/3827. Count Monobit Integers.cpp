class Solution {
public:
    int countMonobit(int n) {
        int count = 1; // counting zero
        int value = 1; 

        while(value <= n){
            count++;
            value = (value << 1) | 1;
        }

        return count;
    }
};