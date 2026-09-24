class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) return 1 / recursive( x,  abs(n));
        else return  recursive( x,  n);
    }
    double recursive(double x, int n){
        if(n == 0) return 1;
        double y = recursive(x, n / 2);
        
        if(n % 2 != 0) return x * y * y;
        else return y * y;
    }
};
