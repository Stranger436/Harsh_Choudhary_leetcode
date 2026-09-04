class Solution {
public:
    const int INT_MIN_VAL = -2147483648; 
    const int INT_MAX_VAL =  2147483647;

    int helper(string s, int i, long long num, int sign){
        int n = s.size();
        if(i >= n || !isdigit(s[i])){
            return num * sign;
        }
        num = num * 10 + s[i] - '0';
        if(sign == 1 && num > INT_MAX_VAL){
            return INT_MAX_VAL;
        }
        if(sign == -1 && -num < INT_MIN_VAL){
            return INT_MIN_VAL;
        }
        
        return helper(s,i+1,num,sign);

    }
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        int sign = 1;
        while(i < n && s[i] == ' '){ // skip spaces
            i++;
        }
        if(i < n && (s[i] == '+' || s[i] == '-')){ // handle sign
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        return helper(s,i,0,sign);
    }
};