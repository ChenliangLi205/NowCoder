# include<iostream>
# include<string>
# include<sstream>
# include<vector>
using namespace std;

int string2int(string& str)
{
    istringstream iss(str);
    int num;
    iss >> num;
    return num;
}

void add(string str, vector<int>& v)
{
    string tmp;
    int root, left, right;
    for(char c: str)
    {
        if(c==':')
        {
            root = string2int(tmp);
            tmp = "";
        }
        else if(c=='|')
        {
            left = string2int(tmp);
            tmp = "";
        }
        else
        {
            tmp += c;
        }
    }
    right = string2int(tmp);
    for(int i = 0; i< v.size(); i++)
    {
        if(v[i] == root)
        {
            if(right != -1) v.insert(v.begin()+i+1, right);
            if(left != -1) v.insert(v.begin()+i, left);
            break;
        }
    }
    return;
}

int main()
{
    int root;
    cin>>root;
    string s;
    vector<int> v;
    v.push_back(root);
    while(cin >> s)
    {
        add(s, v);
    }
    bool isBST = true;
    for(int i=1;i<v.size();i++)
    {
        if(v[i] <= v[i-1])
        {
            isBST = false;
            break;
        }
    }
    if(isBST) cout<<1<<endl;
    else cout<<0<<endl;
    return 0;
}