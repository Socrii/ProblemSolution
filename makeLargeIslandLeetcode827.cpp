#include<bits/stdc++.h>
using namespace std;

class Solution 
{
// private:
public:
    vector<vector<int>>grid;

    bool isnotvalid(int i,int j,int row,int col)    // out of bound condition which is invalid
    {
        if(i<0||j<0||i>=row||j>=col)
        {
            return 1;
        }
        return 0;
    }

    // dfs function

    int  dfs(int i,int j,vector<vector<int>>& grid,int &color)
    {
        int row=grid.size();
        int col=grid[0].size();
        if(isnotvalid(i,j,row,col)||grid[i][j]!=1) // we will increase the area by 1 only there is grid[i][j] = 1
        {
            return 0;
        }
        int ans=grid[i][j];
        grid[i][j]=color;               // colored different for different island
        ans+=dfs(i+1,j,grid,color);     
        ans+=dfs(i,j+1,grid,color);
        ans+=dfs(i-1,j,grid,color);
        ans+=dfs(i,j-1,grid,color);
        return ans;
    }

    // solve function 
    int solve(int i,int j,vector<vector<int>>& grid,map<int, int> &dp)
    {
        int row=grid.size();
        int col=grid[0].size();
        int ans=1;           // as we can change 0 to 1 and take the surrounding that is different island 
        int leftc=0,rightc=0,upc=0,downc=0;
        if(j-1>=0)
        leftc=grid[i][j-1];
        if(j+1<col)
        rightc=grid[i][j+1];
        if(i-1>=0)
        upc=grid[i-1][j];
        if(i+1<row)
        downc=grid[i+1][j];
        set<int>s;
        s.insert(leftc);
        s.insert(rightc);
        s.insert(downc);
        s.insert(upc);
        for(auto it:s)
        {
            ans+=dp[it];
        }
        return ans; 
    }
    int largestIsland(vector<vector<int>>& grid) 
    {
         map<int, int> dp; // color formating technique 
                          // val 100 se start karta hu random number i have initialised with 100 

        int  row = grid.size();
        int  col = grid[0].size();
        
        // coloring 
        int color=100;
        int countones=0;
        for (int i = 0; i < row; i++) 
        {
            for (int j = 0; j < col; j++) 
            {
                if (grid[i][j] == 1)
                {    
                    countones++;                
                    int count=0;
                    count=dfs(i, j, grid,color);                 
                    dp[color]=count;
                    color++;
                }
            }
        }
       
        int ans = 0;
        for (int i = 0; i < row; i++) 
        {
            for (int j = 0; j < col; j++) 
            {
                if (grid[i][j] == 0) 
                    ans = max(ans, solve(i, j, grid, dp));
            }
        }
       if(ans==0)return dp[100];
        return ans;
    }

    void gridfill()
    {
        int row,col;
        cout<<"Enter the grid's row's and column's size\n";
        cin>>row>>col;
        cout<<"row "<<row<<" col "<<col<<endl;

        for(int i=0;i<row;i++)
        {
            vector<int>a(col,0);
            for(int j=0;j<col;j++)
            {   
                cin>>a[j];
            }
            grid.push_back(a);
        }

    }
    void gridshow()
    {
        cout<<"\nGRID SHOW\n";
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<"\n";
        }

    }

};

int main()
{

    Solution *object1=new Solution;
    object1->gridfill();
    object1->gridshow();
   int area=object1->largestIsland(object1->grid);
   cout<<"area" <<area<<endl;

    return 0;
}