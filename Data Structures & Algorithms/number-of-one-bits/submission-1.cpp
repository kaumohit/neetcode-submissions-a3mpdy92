class Solution {
public:
    int hammingWeight(uint32_t n) {
        int oneCount = 0;
        while(n > 0) {
            oneCount += n%2;
            n = n/2;
        }
        return oneCount;
    }
};
