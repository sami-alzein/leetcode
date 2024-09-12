#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int length = 0;

        for (size_t i = 0; i < s.length(); i++)
        {
            string temp = "";

            for (size_t j = i; j < s.length(); j++)
            {
              
              if (contains(temp, s[j]))
              {
                break;
              }

              temp +=s[j];
              if (temp.length() > length)
              {
                length = temp.length();
              }
                
            }
        }

        return length;
    }

    bool contains(string s, char c)
    {
        for (size_t i = 0; i < s.length(); i++)
        {
            if (s[i] == c)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << s.lengthOfLongestSubstring("bbbbb") << endl;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;
    cout << s.lengthOfLongestSubstring("") << endl;
    cout << s.lengthOfLongestSubstring(" ") << endl;
    cout << s.lengthOfLongestSubstring("au") << endl;
    return 0;
}