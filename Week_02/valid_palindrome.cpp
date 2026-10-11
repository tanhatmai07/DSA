class Solution {
public:
    string xu_li_chuoi(string s)
    {
        string chuoimoi = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (isalnum(s[i]))
            {
                chuoimoi += tolower(s[i]);
            }
        }
        return chuoimoi;
    }
    bool isPalindrome(string s) {
        s = xu_li_chuoi(s);
        int i = 0;
        int j = s.size() - 1;
        while (i <= j)
        {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};