class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res =0;
        for(int i=0;i<32;i++)
        {
            uint32_t lsb = n&1;
            uint32_t reverse = lsb<<(31-i);
            res = res|reverse;
            n = n>>1;
        }
        return res;
    }
};