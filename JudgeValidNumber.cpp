class Solution {
public:
    bool isNumeric(char* string)
    {
        int len=0;
        char number = '0';
        while(string[len]!='\0') ++len;
        if(len <= 0) return false;
        vector< map<char, int> > StatusMachine;
        
        // start
        StatusMachine.push_back(map<char,int>());
        StatusMachine[0]['-'] = 1;
        StatusMachine[0]['+'] = 1;
        StatusMachine[0]['.'] = 4;
        while(number <= '9')
        {
            StatusMachine[0][number] = 2;
            ++number;
        }
        number = '0';
        
        //Meets +- sign
        StatusMachine.push_back(map<char, int>());
        StatusMachine[1]['.'] = 4;
        while(number <= '9')
        {
            StatusMachine[1][number] = 2;
            ++number;
        }
        number = '0';
        
        //Meets number
        StatusMachine.push_back(map<char, int>());
        StatusMachine[2]['e'] = 3;
        StatusMachine[2]['E'] = 3;
        StatusMachine[2]['.'] = 4;
        while(number <= '9')
        {
            StatusMachine[2][number] = 2;
            ++number;
        }
        number = '0';
        
        //Meets e or E
        StatusMachine.push_back(map<char, int>());
        StatusMachine[3]['-'] = 5;
        StatusMachine[3]['+'] = 5;
        while(number <= '9')
        {
            StatusMachine[3][number] = 6;
            ++number;
        }
        number = '0';
        
        //Meets point
        StatusMachine.push_back(map<char, int>());
        while(number <= '9')
        {
            StatusMachine[4][number] = 7;
            ++number;
        }
        number = '0';
        
        //Meets positive or negative sign after e
        StatusMachine.push_back(map<char, int>());
        while(number <= '9')
        {
            StatusMachine[5][number] = 6;
            ++number;
        }
        number = '0';
        
        //Meets number after e
        StatusMachine.push_back(map<char, int>());
        while(number <= '9')
        {
            StatusMachine[6][number] = 6;
            ++number;
        }
        number = '0';
        
        //Meets number after point
        StatusMachine.push_back(map<char, int>());
        StatusMachine[7]['e'] = 8;
        StatusMachine[7]['E'] = 8;
        while(number <= '9')
        {
            StatusMachine[7][number] = 7;
            ++number;
        }
        number = '0';
        
        //Meets e after point and number
        StatusMachine.push_back(map<char, int>());
        StatusMachine[8]['+'] = 9;
        StatusMachine[8]['-'] = 9;
        while(number <= '9')
        {
            StatusMachine[8][number] = 10;
            ++number;
        }
        number = '0';
        
        //Meets +- after e after point and number
        StatusMachine.push_back(map<char, int>());
        while(number <= '9')
        {
            StatusMachine[9][number] = 10;
            ++number;
        }
        number = '0';
        
        //Meets Number after +- or e after point and number
        StatusMachine.push_back(map<char, int>());
        while(number <= '9')
        {
            StatusMachine[10][number] = 10;
            ++number;
        }
        number = '0';
        
        //check
        int CurStatus = 0;
        bool res = true;
        for(int i=0;i<len;++i)
        {
            if(StatusMachine[CurStatus].count(string[i]) == 0)
            {
                res = false;
                break;
            }
            else
                CurStatus = StatusMachine[CurStatus][string[i]];
        }
        if (CurStatus!=2 && CurStatus!=6 && CurStatus != 7 && CurStatus!=10)
            res = false;
        return res;
    }

};