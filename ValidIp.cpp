#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

inline int string2int(const string& s)
{
    int res=0;
    for(char c : s)
    {
        res *= 10;
        if(c > '9' || c < '0') return -1;
        res += (int)(c-'0');
    }
    return res;
}

inline bool isConsecutive(const vector<int>& mask)
{
    int i=0, j=mask.size()-1;
    while(i < mask.size() && mask[i] == 255) ++i;
    while(j >= 0 && mask[j] == 0) --j;
    if(j > i || i >= mask.size() || j < 0) return false;
    if(j < i) return true;
    if(mask[i] == 254 || mask[i] == 252 || mask[i] == 248
      || mask[i] == 240 || mask[i] == 224 || mask[i] == 192
      || mask[i] == 128)
        return true;
    else return false;
}

bool validMask(const vector<int>& mask)
{
    for(int i : mask)
    {
        if(i < 0 || i > 255)
            return false;
    }
    if(isConsecutive(mask)) return true;
    else return false;
}

inline bool Sip(const vector<int>& ip)
{
    if(ip[0] == 10) return true;
    if(ip[0] == 172 && ip[1] >= 16 && ip[1] <= 31) return true;
    if(ip[0] == 192 && ip[1] == 168) return true;
    return false;
}

void judgeIpType(const vector<int>& ip,
                 const vector<int>& mask,
                 vector<int>& res)
{
    for(size_t i=0;i<ip.size();++i)
    {
        if(ip[i] < 0 || ip[i] > 255) 
        {
            ++res[5];
            return;
        }
    }
    if(ip[0] >= 1 && ip[0] <= 126) ++res[0];
    else if(ip[0] >= 128 && ip[0] <= 191) ++res[1];
    else if(ip[0] >= 192 && ip[0] <= 223) ++res[2];
    else if(ip[0] >= 224 && ip[0] <= 239) ++res[3];
    else if(ip[0] >= 240 && ip[0] <= 255) ++res[4];
    //else ++res[5];
    if(Sip(ip)) ++res[6];
    return;
}

void classifyIp(const vector<string>& IpMask, vector<int>& res)
{
    vector<int> ip, mask;
    istringstream pointIssIp(IpMask[0]), pointIssMask(IpMask[1]);
    string tmp;
    while(getline(pointIssIp, tmp, '.'))
        ip.push_back(string2int(tmp));
    while(getline(pointIssMask, tmp, '.'))
        mask.push_back(string2int(tmp));
    if(!validMask(mask))
    {
        ++res[5];
        return;
    }
    if(!ip.size()==4 || !mask.size()==4)
    {
        ++res[5];
        return;
    }
    judgeIpType(ip, mask, res);
    return;
}

int main()
{
    string raw_input;
    vector<int> res(7, 0);
    while(cin >> raw_input)
    {
        istringstream waveIss(raw_input);
        vector<string> IpMask;
        string tmp;
        while(getline(waveIss, tmp, '~'))
            IpMask.push_back(tmp);
        classifyIp(IpMask, res);
    }
    for(size_t i=0;i<res.size()-1;++i)
        cout << res[i] << " ";
    cout << res.back() << endl;
    return 0;
}