class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()) return false;
        if(sequence.size()==1) return true;
        vector<int>::size_type idx = sequence.size()-2;
        int rootVal = sequence.back(), rightVal = sequence[idx];
        auto it = sequence.begin();
        while(it!=sequence.end()-1)
        {
            if(*it > rootVal) break;
            it++;
        }
        auto leftEnd = it;
        bool rightBigger=true;
        while(it!=sequence.end()-1)
        {
            if(*it<rootVal) {rightBigger=false;break;}
            it++;
        }
        return rightBigger && VerifyHelper(vector<int>(sequence.begin(),leftEnd)) &&
            VerifyHelper(vector<int>(leftEnd,sequence.end()-1));
    }
    
    bool VerifyHelper(vector<int>&& sequence)
    {
        if(sequence.empty()) return true;
        if(sequence.size()==1) return true;
        vector<int>::size_type idx = sequence.size()-2;
        int rootVal = sequence.back(), rightVal = sequence[idx];
        auto it = sequence.begin();
        while(it!=sequence.end()-1)
        {
            if(*it > rootVal) break;
            it++;
        }
        auto leftEnd = it;
        bool rightBigger=true;
        while(it!=sequence.end()-1)
        {
            if(*it<rootVal) {rightBigger=false;break;}
            it++;
        }
        return rightBigger && VerifyHelper(vector<int>(sequence.begin(),leftEnd)) &&
            VerifyHelper(vector<int>(leftEnd,sequence.end()-1));
    }
};