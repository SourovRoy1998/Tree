class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int x=grid.size(),y=grid[0].size();
        
        int arr[x][y];
        arr[0][0]=grid[0][0];
        
        for(int i=0;i<x;i++)
            for(int j=0;j<y;j++){
                if(i==0 && j!=0)
                    arr[i][j]=arr[i][j-1]+grid[i][j];
                else if(j==0 && i!=0)
                    arr[i][j]=arr[i-1][j]+grid[i][j];
                else if(i!=0 && j!=0)
                    arr[i][j]=min(arr[i-1][j],arr[i][j-1])+grid[i][j];
            }
       /* for(int i=0;i<x;i++){
            for(int j=0;j<y;j++)
                cout<<arr[i][j]<<" ";
            cout<<endl;
        }
        */
        
        return arr[x-1][y-1];
        
    }
};
