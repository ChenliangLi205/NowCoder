class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0) return 0;
        if(rotateArray.size() == 1) return rotateArray[0];
        int back = rotateArray.size()-1;
        int front = 0;
        int res = rotateArray[0];
        while(back >= front)
        {
            if(rotateArray[front] > rotateArray[front+1])
            {
                res = rotateArray[front+1];
                break;
            }
            if(rotateArray[back] < rotateArray[back-1])
            {
                res = rotateArray[back];
                break;
            }
            back--;
            front++;
        }
        return res;
    }
};