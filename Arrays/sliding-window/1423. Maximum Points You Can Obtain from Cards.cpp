// 1423. Maximum Points You Can Obtain from Cards

// Let the sum of all points be total_pts. You need to remove a sub-array from cardPoints with length n - k.

int maxScore(vector<int>& cardPoints, int k) {
    int total_pts = 0,n = cardPoints.size();
    // total sum of the array
    for(int i : cardPoints){
        total_pts += i;
    }

    int i = 0, j = n - k;
    int currentWindowSum = 0;
    // sum of window of size n - k 
    for(int i = 0;i < n - k;i++){
        currentWindowSum += cardPoints[i];
    }

    int res = 0;
    res = max(total_pts - currentWindowSum, res);

    while(j < n){
        currentWindowSum += -cardPoints[i++] + cardPoints[j++];
        res = max(total_pts - currentWindowSum, res);
    }
    return res;
}