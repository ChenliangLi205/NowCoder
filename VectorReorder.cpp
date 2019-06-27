#include<algorithm>
class Solution {
public:
    bool isEven(int a)
    {
        return a%2 == 0;
    }
    void reOrderArray(vector<int> &array) {
        if(array.size() <= 1) return;
        auto it = array.begin();
        auto end = array.end();
        vector<int> e_array;
        while(it!=array.end())
        {
            if(isEven(*it)) 
            {
                e_array.push_back(*it);
                array.erase(it);
            }
            else it++;
        }
        for(int i: e_array) array.push_back(i);
        return;
    }
};