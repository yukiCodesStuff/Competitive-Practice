#include <string>

using namespace std;

class Solution
{
public:
    int minimumLength(string s)
    {
        int begin = 0, end = s.size() - 1;
        while (begin < end)
        {
            if (s[begin] == s[end])
            {
                // handle repeating characters
                while (begin < s.size() - 2 && s[begin] == s[begin + 1])
                    ++begin;
                while (end > 1 && s[end] == s[end - 1])
                    --end;
                ++begin;
                --end;
            }
            else
                break;
        }
        if (end - begin + 1 < 0)
            return 0;
        return end - begin + 1;
    }
};