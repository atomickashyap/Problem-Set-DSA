class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
      const auto& p0 = coordinates[0];
        const auto& p1 = coordinates[1];
        const int x0 = p0[0];
        const int y0 = p0[1];
        const int x1 = p1[0];
        const int y1 = p1[1];
        for (int i = 2; i < coordinates.size(); i++) {
            const auto& point = coordinates[i];
            const int x = point[0];
            const int y = point[1];

            if ((x1 - x0) * (y - y0) != (y1 - y0) * (x - x0)) {
                return false;
            }
        }
        return true;   
    }
};