# include<iostream>
# include<vector>
using namespace std;

bool canPlace(int** board, int r, int c, int n)
{
    for(int i=0;i<9;i++)
    {
        if(r==i) continue;
        if(board[i][c] == n) return false;
    }
    for(int j=0;j<9;j++)
    {
        if(c==j) continue;
        if(board[r][j] == n) return false;
    }
    int top = (r/3)*3;
    int left = (c/3)*3;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            if(top+i==r && left+j==c) continue;
            if(board[top+i][left+j] == n) return false;
        }
    return true;
}

bool BackTrack(int**& board, vector<int>& rows, vector<int>& cols)
{
    if(rows.size() == 0) 
    {
        return true;
    }
    int r = rows.back();
    rows.pop_back();
    int c = cols.back();
    cols.pop_back();
    
    for(int i=1;i<=9;i++)
    {
        if(canPlace(board, r, c, i))
        {
            board[r][c] = i;
            if(BackTrack(board, rows, cols)) return true;
            board[r][c] = 0;
        }
    }
    rows.push_back(r);
    cols.push_back(c);
    return false;
}

int main()
{
    int** board = new int*[9];
    for(int i=0;i<9;i++)
    {
        board[i] = new int[9];
    }
    vector<int> rows;
    vector<int> cols;
    for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
    {
        cin>>board[i][j];
        if(board[i][j]==0)
        {
            rows.push_back(i);
            cols.push_back(j);
        }
    }
    BackTrack(board, rows, cols);
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            if(j==8) cout<<board[i][j]<<endl;
            else cout<<board[i][j]<<" ";
        }
    return 0;
}
