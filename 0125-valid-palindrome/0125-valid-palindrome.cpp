class Solution {
public:

    bool fun(string&s, int low, int high)
    {
        int len = high - low + 1;
        
        if(len == 0 || len == 1)
        return true;
        
        if(s[low] != s[high])
        return false;
        
        return fun(s, low + 1, high - 1);
    }

    bool isPalindrome(string s) {
        string temp;

        for(char &i : s)
        {
            if(isalnum(i))
                temp += tolower(i);
        }
        return fun(temp, 0, temp.size() - 1);
    }
};