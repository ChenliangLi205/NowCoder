class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        if(A.empty()) return vector<int>();
        if(A.size() == 1) return vector<int>(1,1);
        vector<int> left(A.size(), 1);
        vector<int> right(A.size(), 1);
        vector<int> res(A.size(),1);
        for(int i=1;i<A.size();i++)
            left[i] = left[i-1] * A[i-1];
        for(int i=A.size()-2;i>=0;i--)
            right[i] = right[i+1] * A[i+1];
        for(int i=0;i<A.size();i++)
            res[i] = left[i] * right[i];
        return res;
    }
};