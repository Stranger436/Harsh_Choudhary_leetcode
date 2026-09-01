class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxsum = 0, lsum = 0, rsum = 0;

        for(int i = 0; i < k; i++){
            lsum += cardPoints[i];
        }
        maxsum = lsum;
        int rightindx = n - 1;
        for(int i = k - 1; i >= 0; i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[rightindx];
            rightindx--;
            maxsum = max(maxsum, rsum + lsum);
        }
        return maxsum;
    }
};