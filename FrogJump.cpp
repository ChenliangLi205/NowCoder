class Solution {
public:
    int jumpFloor(int number) {
        if(number <= 0) return 0;
        if(number <= 2) return number;
        int from2=1, from1=2, cur;
        for(int i=3;i<=number;i++)
        {
            cur = from2+from1;
            from2 = from1;
            from1 = cur;
        }
        return cur;
    }
};