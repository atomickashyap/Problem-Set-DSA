class Solution {
public:
    int count(string str,char ch){
        int count = 0;
        for(auto it : str)
            if(it == ch)
                count++;
        return count;
    }
    string predictPartyVictory(string senate) {
        int red = 0 , der = 0;
        int nr = count(senate,'R');
        int nd = count(senate,'D');
        int n = senate.size() , i = 0;
        unordered_set<int> s;
        while(nr and nd){
            if(s.find(i) != s.end()){
                i = (i+1)%n;
                continue;
            }
            if(senate[i] == 'R'){
                if(!der)
                    red++;
                else{
                    nr--;
                    s.insert(i);
                    der--;
                }
                i = (i+1)%n;
            }
            else{
                if(!red)
                    der++;
                else{
                    red--;
                    nd--;
                    s.insert(i);
                }
                i = (i+1)%n;
            }
        }
        return (nr == 0)?"Dire":"Radiant";
    }
};