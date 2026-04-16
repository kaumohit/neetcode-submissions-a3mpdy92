class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t revBitsNum = 0;
        uint32_t power = pow(2,31);
        while(n > 0) {
            revBitsNum += (power * (n%2));
            power /=2;
            n = n/2;
        }
        return revBitsNum;
    }
};
