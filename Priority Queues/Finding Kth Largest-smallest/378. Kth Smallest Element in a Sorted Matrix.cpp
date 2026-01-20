// 378. Kth Smallest Element in a Sorted Matrix

class Solution {
public:
    // Counts how many elements in the matrix are <= given value
    int countLessOrEqual(const vector<vector<int>>& matrix, int value) {
        int n = matrix.size();
        int row = n - 1; // start from bottom-left
        int col = 0;
        int count = 0;

        while (row >= 0 && col < n) {
            if (matrix[row][col] <= value) {
                // all elements above matrix[row][col] are also <= value
                count += (row + 1);
                col++; // move right
            } else {
                row--; // move up
            }
        }
        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        int left = matrix[0][0];          // smallest possible value
        int right = matrix[n - 1][n - 1]; // largest possible value

        while (left < right) {
            int mid = left + (right - left) / 2;

            int elementsCount = countLessOrEqual(matrix, mid);

            if (elementsCount < k) {
                // kth smallest is larger
                left = mid + 1;
            } else {
                // mid might be the answer
                right = mid;
            }
        }

        return left;
    }
};
