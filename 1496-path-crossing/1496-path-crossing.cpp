class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int,int>,bool> loc;
        pair<int,int> p=make_pair(0,0);
        loc[p]=true;
        for(int i=0,x=0,y=0;i<path.size();i++){
            if(path[i]=='N') y++;
            else if(path[i]=='S') y--;
            else if(path[i]=='E') x++;
            else if(path[i]=='W') x--;
            p=make_pair(x,y);
            if(loc[p]) return true;
            loc[p]=true;
        }   
        return false;
    }
};