class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty()) return false;
        if(array[0].empty()) return false;
        int row=0, col=array[0].size()-1;
        while(row<array.size() && col>=0)
        {
            if(array[row][col] > target)
            {
                col--;
                continue;
            }
            if(array[row][col] == target)
            {
                return true;
            }
            if(array[row][col] < target)
            {
                row++;
                continue;
            }
        }
        return false;
    }
};