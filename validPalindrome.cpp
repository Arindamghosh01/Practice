class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for (char c : s){
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
                str += tolower(c);
        }
        string rev = str; 
        reverse(rev.begin(), rev.end());
        return str == rev;
    }
};