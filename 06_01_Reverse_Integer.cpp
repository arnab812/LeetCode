class Solution {
public:
    int reverse(int x) {
        if(x==0 or x>2147483647 or x<-2147483647)
            return 0;
        
        int64_t val = 0;
        int sign = 1;
        if(x<0) { sign = -1; x=abs(x);}
        
        while(x%10==0)
            x=x/10;
        
        while(x){
            val =val+ x%10;
            x = x/10;
            if(val>2147483647)
                return 0;
            val = val*10;
        }
        return sign*val/10;
    }
};
