class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> oneCounts;
        for(int i = 0; i<= n;i++) {
            int oneCount = 0, num = i;
            while(num > 0) {
                oneCount += num%2;
                num = num/2;
            }
            oneCounts.push_back(oneCount);
        }   
        return oneCounts;
    }
};
