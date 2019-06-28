#include<vector>
#include<stack>
class Solution {
private:
    std::vector<int> v;
    std::stack<int> s;
public:
    void push(int value) {
        s.push(value);
        vectorInsert(value);
    }
    void pop() {
        int n = s.top();
        s.pop();
        int pos = findPosition(n);
        v.erase(v.begin()+pos);
    }
    int top() {
        return s.top();
    }
    int min() {
        return v.front();
    }
    int findPosition(int n)
    {
        if(v.empty()) return 0;
        int left=0,right=v.size();
        int mid=left+(right-left)/2;
        while(left<right)
        {
            if(n == v[mid]) {right=mid;break;}
            else if(n < v[mid]) right = mid;
            else left = mid+1;
            mid = left + (right-left)/2;
        }
        return right;
    }
    void vectorInsert(int n)
    {
        if(v.empty()) v.push_back(n);
        else
        {
            int pos = findPosition(n);
            v.insert(v.begin()+pos, n);
        }
    }
};