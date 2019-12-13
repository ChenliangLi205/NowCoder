#include<bits/stdc++.h>
using namespace std;

class range
{
private:
    vector<int> starts;
    vector<int> ends;
    bool visible;
public:
    range(int,int);
    void cover(int,int);
    bool isVisible();
    void show();
};

range::range(int start, int end)
{
    visible = true;
    starts.push_back(start);
    ends.push_back(end);
}

void range::cover(int start, int end)
{
    // no influence
    if(!visible) return;
    if(start >= ends.back() || end <= starts.front()) return;
    // whole visible parts covered
    if(start <= starts.front() && end >= ends.back())
    {
        starts.clear();
        ends.clear();
        visible = false;
        return;
    }
    // some parts covered
    auto iter_starts = starts.begin();
    auto iter_ends = ends.begin();
    int left, right;
    while(iter_starts != starts.end() && iter_ends != ends.end())
    {
        left = *iter_starts;
        right = *iter_ends;
        // completely not inside
        if(left >= end || right <= start)
        {
            ++iter_starts;
            ++iter_ends;
            continue;
        }
        // compeletly inside
        if(left >= start && right <= end)
        {
            starts.erase(iter_starts);
            ends.erase(iter_ends);
            continue;
        }
        // partially inside
        if(left >= start && left < end)
        {
            *iter_starts = end;
            ++iter_starts;
            ++iter_ends;
            continue;
        }
        if(right > start && right <= end)
        {
            *iter_ends = start;
            ++iter_starts;
            ++iter_ends;
            continue;
        }
        // new comer completely inside
        if(left < start && right > end)
        {
            *iter_ends = start;
            starts.insert(++iter_starts, 1, end);
            ends.insert(++iter_ends, 1, right);
            break;
        }
    }
    return;
}

bool range::isVisible()
{
    if(starts.empty() || ends.empty()) visible = false;
    return visible;
}

void range::show()
{
    for(size_t i = 0 ; i < starts.size() ; ++i)
    {
        cout <<"("<<starts[i]<<","<<ends[i]<<") "; 
    }
    cout<<endl;
}

int main()
{
    vector<range> ranges;
    int n, left, right, cnt=0;
    auto iter=ranges.begin();
    cin >> n;
    for(int i=0;i<n;++i)
    {
        cin >> left >> right;
        while(iter!=ranges.end())
        {
            iter->cover(left, right);
            if(!iter->isVisible()) ranges.erase(iter);
            else ++iter;
        }
        ranges.push_back(range(left, right));
        iter = ranges.begin();
    }
    for(range r:ranges)
    {
        if(r.isVisible())
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}