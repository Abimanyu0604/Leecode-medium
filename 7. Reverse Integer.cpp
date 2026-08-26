class Solution {
public:
    int reverse(int x) {
        long long temp=0;
        while(x){
            temp=(temp*10)+(x%10);
            x=x/10;
        }
        if(temp > 2147483647 || temp < -2147483648LL)
        {
            return 0;
        }
        return temp;
    }
};
