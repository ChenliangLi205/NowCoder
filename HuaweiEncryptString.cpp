#include <iostream>
#include <string.h>
#include <set>
using namespace std;

void encrypt(char* key, char* data, char* encrypt)
{
    char ch[26], newKey[26];
    int newKeyIndex = 0;
    set<char> appeared;
    // build characted array
    for(char i=0;i<26;++i)
        ch[i] = 'a'+i;
    for(int i=0;key[i]!='\0';++i)
    {
        // make key into lower chars
        if(key[i] >= 'A' && key[i] <= 'Z')
            key[i] += 32;
        if(appeared.find(key[i]) != appeared.end())
            continue;
        appeared.insert(key[i]);
        newKey[newKeyIndex++] = key[i];
    }
    for(int i=0;i<26;++i)
    {
        if(appeared.find(ch[i]) != appeared.end())
            continue;
        newKey[newKeyIndex++] = ch[i];
    }
    // map into new key
    for(int i=0;data[i]!='\0';++i)
    {
        char tmp = data[i];
        bool isUpper = false;
        if(tmp >= 'A' && tmp <= 'Z')
        {
            tmp += 32;
            isUpper = true;
        }
        if(isUpper)
            encrypt[i] = newKey[tmp-'a']-32;
        else
            encrypt[i] = newKey[tmp-'a'];
    }
    return;
}

int main()
{
    char key[100], data[100], encrypted[100];
    while(cin >> key >> data)
    {
        memset(encrypted, '\0', sizeof(encrypted));
        encrypt(key, data, encrypted);
        cout << encrypted << endl;
    }
    return 0;
}