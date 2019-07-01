#include<algorithm>
#include<numeric>
class BigHeap
{
private:
    vector<int> v;
    int maxSize;
public:
    BigHeap(int k): maxSize(k){}
    ~BigHeap(){}
    void push(int n)
    {
        v.push_back(n);
        shiftUp();
        if(v.size()>maxSize) pop();
    }
    void pop()
    {
        v.erase(v.begin());
        if(v[1] > v[0]) swap(v[0], v[1]);
        return;
    }
    vector<int> get()
    {
        return v;
    }
    void shiftUp()
    {
        if(v.size() <= 1) return;
        vector<int>::size_type idx = v.size()-1;
        vector<int>::size_type pIdx;
        while(idx > 0)
        {
            if(idx%2==0) pIdx = (idx-1)/2;
            else pIdx = idx/2;
            if(v[idx] <= v[pIdx]) break;
            swap(v[idx],v[pIdx]);
            idx = pIdx;
        }
        return;
    }
    int top()
    {
        return v.front();
    }
};

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        BigHeap h(k);
        if(input.size() < k) return res;
        for(int i:input)
        {
            h.push(i);
        }
        return h.get();
    }
};