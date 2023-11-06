class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> vis;
    vector<int> v;
    SeatManager(int n) {
        v.resize(n + 2, 0);
        vis.resize(n + 2, 0);
        pq.push(1);
        vis[1] = 1;
    }
    
    int reserve() {
        int ans = pq.top();
        pq.pop();
        vis[ans] = 0;
        v[ans++] = 1;
        if(!v[ans] && !vis[ans]){
            pq.push(ans);
            vis[ans] = 1;
        }
        return ans - 1;
    }
    
    void unreserve(int seatNumber) {
        v[seatNumber] = 0;
        if(!vis[seatNumber]){
            pq.push(seatNumber);
            vis[seatNumber] = 1;
        }
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */