#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), comp);
        int currweight = 0;
        int finalvalue = 0;
        for(int i = 0; i < n; i++){
            int boxes = boxTypes[i][0];
            int units = boxTypes[i][1];

            if(currweight + boxes <= truckSize){
                currweight += boxes;
                finalvalue += boxes * units;
            }
            else{
                int remain = truckSize - currweight;
                finalvalue += remain * units;
                break;
            }
        }
        return finalvalue;
    }
};