#include<vector>
class Solution {
public:
     int  NumberOf1(int n) {
         if(n==0) return 0;
         int res = 0;
         while(n)
         {
             res++;
             n = (n-1)& n;
         }
         return res;
     }
};