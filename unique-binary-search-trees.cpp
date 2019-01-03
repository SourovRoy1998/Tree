//https://leetcode.com/problems/unique-binary-search-trees/

class Solution {
public:
    int numTrees(int n) {
        vector<int> vtr;
        vtr.push_back(1);
        vtr.push_back(1);
        vtr.push_back(2);
        for(int i=3;i<=n;i++){
            int temp=0;
            for(int j=0;j<=i;j++)
                temp+=vtr[j]*vtr[i-j-1];
            vtr.push_back(temp);
        }
        return vtr[n];
    }
};
