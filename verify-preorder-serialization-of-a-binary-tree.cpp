//https://www.lintcode.com/problem/verify-preorder-serialization-of-a-binary-tree/description
//https://www.youtube.com/watch?v=_mbnPPHJmTQ

class Solution {
public:
    /**
     * @param preorder: a string
     * @return: return a bool
     */
    bool isValidSerialization(string &preorder) {
        // write your code here
        int arrow=1;
        for(int i=0;i<preorder.length();i++){
            if(preorder[i]==',' or (i>0 && preorder[i-1]!=',')) continue;
            if(--arrow<0) return false;
            if(preorder[i]!='#') arrow+=2;
        }
        return arrow==0;
    }
};
