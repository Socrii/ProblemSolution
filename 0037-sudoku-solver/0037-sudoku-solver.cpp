class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        solve(board);
    }
     bool solve(vector<vector<char>>& board) 
    {
        int n=board.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='.')
                {
                    for(int ch=1;ch<=(n);ch++)
                    {
                        
                        if(isvalid(board,i,j,ch+48))
                        {
                            board[i][j]=ch+48; // daalo aur check karo 
                            if(solve(board)==1) 
                            {
                                return 1;
                            }
                            else
                            {
                                board[i][j]='.'; // backtracked
                            }
                        }
                    }
                        return 0;
                }
            }
        }
        return 1;
    }

        bool isvalid(vector<vector<char>>&board,int row_check,int col_check,char check)
        {
            for(int i=0;i<9;i++)
            {
                if(board[i][col_check]==check)return 0;
                if(board[row_check][i]==check)return 0;
                if(board[3*(row_check/3)+i/3][3*(col_check/3)+i%3]==check)return 0;
             
            }
            return 1;
        }

};