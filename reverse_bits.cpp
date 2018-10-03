
//https://leetcode.com/problems/reverse-bits/description/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        m=0;
        for(int i=0;i<32;i++){
            m=m|((n>>i)&1);
            m=m<<1;
        }
        return m;
            
    }
};
