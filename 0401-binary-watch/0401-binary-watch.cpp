class Solution {
public:
    vector<string> readBinaryWatch(int onLED) {
        vector<string> time;
        for(int h=0; h<12; h++){
            for(int m=0; m<60; m++){
                int set = __builtin_popcount(h) + __builtin_popcount(m);
                if(set == onLED){
                    time.push_back(to_string(h) + ((m<10) ? ":0" : ":") + to_string(m));
                }
            }
        }

        return time;
    }
};