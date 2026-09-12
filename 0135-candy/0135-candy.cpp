class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1;
        int sum = n; // every chimldren at least gets 1 candy

        while(i < n){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
            int peak = 0;
            while(i < n && ratings[i] > ratings[i - 1]){
                peak++;
                sum += peak;
                i++;
            }
            int down = 0;
            while(i < n && ratings[i] < ratings[i - 1]){
                down++;
                sum += down;
                i++;
            }
            sum -= min(peak,down); // keep only the high peak
        }
        return sum;
    }
};