class Solution
{
private:
    map<char,int> char2times;
    queue<char> q1, q2;
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        if(char2times.find(ch) == char2times.end())
        {
            char2times[ch] = 1;
            if(q1.empty() && q2.empty()) q1.push(ch);
            else if(q1.empty()) q2.push(ch);
            else if(q2.empty()) q1.push(ch);
            return;
        }

        if(char2times[ch] == 1)
        {
            char2times[ch]++;
            if(q2.empty())
            {
                while(!q1.empty())
                {
                    if(q1.front() != ch)
                        q2.push(q1.front());
                    q1.pop();
                }
            }
            else
            {
                while(!q2.empty())
                {
                    if(q2.front() != ch)
                        q1.push(q2.front());
                    q2.pop();
                }
            }
            return;
        }
        return ;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        if(q1.empty() && q2.empty()) return '#';
        if(q2.empty()) return q1.front();
        else return q2.front();
    }

};