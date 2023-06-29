class Solution {
    
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int keys = 0;//to store count of keys
        vector<vector<vector<bool>>> vis(m,vector<vector<bool>>(n,vector<bool>(64,0)));//visited array
        queue<vector<int>> q;//queue to perform bfs
        
        //first traverse the grid and get the count of all keys present and the starting point
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='@'){//when starting point is found
                    q.push({i,j,0});//add it to the queue
                    vis[i][j][0] = true;//and mark it visited
                }
                if(grid[i][j] >='a' && grid[i][j]<='f'){//count keys
                    keys++;
                }
            }
        }
        //to help in calculating adjacents of grid cell
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        
        //now perform a simple bfs (like level order tree traversal)
        int pathlen = 0;
        while(!q.empty()){
            int size = q.size();//get the elements present in this level
            while(size--){//and process all elements
                
                auto curr = q.front(); q.pop();//get the front of queue
                int i = curr[0];//and break it into it's components
                int j = curr[1];
                int keyinhand = curr[2];
                
                for(int p=0;p<4;p++){//go to it's adjacents
                    int x = i+dx[p];//index of adjacent
                    int y = j+dy[p];
                    int k = keyinhand;
                    if(x<0 || y<0 || x>=m || y>=n || grid[x][y]=='#') continue;//if not a valid index or a wall we can't move so we continue
                    
                    if(grid[x][y] >='a' && grid[x][y] <='f'){//if it's a key update keys in hand
                        k = k | (1<<(grid[x][y] - 'a'));//here we are using bitmasking to store which key we have
                        if(k == (1<<keys)-1)//also check if keysinhand is equal to total number of keys
                            return pathlen+1;//if true return current pathlen + 1(including this cell)
                        
                    } else if(grid[x][y] >= 'A' && grid[x][y] <= 'F'){//if it is a lock
                        if(!(k & (1<<(grid[x][y] - 'A')))) continue;//check if we have it's key and if not continue
                    }
                    
                    //at last if it was not visited earlier we mark it visited and add it to queue to process in next level
                    if(!vis[x][y][k]){
                        vis[x][y][k] = true;
                        q.push({x,y,k});
                    }
                }
            }
            //increase the pathlen after processing all the elements of current level
            pathlen++;
        }
        
        return -1;
    }
};