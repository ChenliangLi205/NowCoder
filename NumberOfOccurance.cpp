class Solution {
public:
    int BinarySearch(const vector<int>& v, float f)
    {
        if(v.empty()) return 0;
        int left=0, right=v.size();
        int mid = left+(right-left)/2;
        while(left < right)
        {
            if(f < v[mid]) right = mid;
            else if(f > v[mid]) left = mid + 1;
            else {right=mid+1;break;}
            mid = left+(right-left)/2;
        }
        return right;
    }
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty()) return 0;
        return BinarySearch(data,k+0.1)-BinarySearch(data,k-0.1);
    }
};