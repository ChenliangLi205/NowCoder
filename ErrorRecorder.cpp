#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

void Record(const string& path, const int& row,
            vector< pair<string,int> >& fileVec,
           vector<int>& countVec,
           set< pair<string,int> >& fileSet)
{
    istringstream iss(path);
    string fileName,tmp;
    while(getline(iss, tmp, '\\')){fileName = tmp;}
    auto filePair = pair<string, int>(fileName, row);
    if(fileSet.find(filePair) != fileSet.end()) return;
    auto it = find(fileVec.begin(), fileVec.end(),
                  filePair);
    if(it == fileVec.end())
    {
        if(fileVec.size() == 8)
        {
            fileSet.insert(*fileVec.begin());
            fileVec.erase(fileVec.begin());
            countVec.erase(countVec.begin());
        }
        fileVec.push_back(filePair);
        countVec.push_back(1);
    }
    else
    {
        auto cntIt = countVec.begin() + (it - fileVec.begin());
        ++(*cntIt);
    }
    return ;
}

void show(const vector< pair<string,int> >& fileVec,
          const vector<int>& countVec)
{
    for(size_t i=0;i<fileVec.size();++i)
    {
        string fileName = fileVec[i].first;
        if(fileName.size() > 16) 
            fileName = string(fileName.end()-16, fileName.end());
        cout << fileName << " " << fileVec[i].second
            << " " << countVec[i] << endl;
    }
    return;
}

int  main()
{
    string path;
    int row;
    vector< pair<string, int> > fileVec;
    vector<int> countVec;
    set< pair<string, int> > fileSet;
    while(cin >> path >> row)
    {
        Record(path, row, fileVec, countVec, fileSet);
    }
    show(fileVec, countVec);
    return 0;
}