#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> divideString(string s, int k, char fill)
    {
        vector<string> res;
        int start = 0;
        while(start < s.length())
        {
            string div;
            if (start+k < s.length())
            {
                div = s.substr(start, k);
            }
            else
            {
                // How many char do we need?
                int pad = start+k - s.length();
                div = s.substr(start);
                for (int i = 0; i < pad; i++)
                {
                    div += fill;
                }
            }
            res.push_back(div);
            start += k;
        }

        return res;
    }
};

int main(int argc, char* argv[])
{
    cout << "2138-divide-str-groups-size-k\n";

    string s;
    int k;
    char fill;
    if (argc > 3)
    {
        s = argv[1];
        k = atoi(argv[2]);
        fill = argv[3][0];
    }
    else
    {
        s = "abcdefghi";
        k = 3;
        fill = 'x';
    }

    cout << "Input:\n\ts = '" << s << "'\n\tk = " << k << "\n\tfill = '" << fill << "'\n";

    Solution sol;
    auto result = sol.divideString(s, k, fill);
    cout << "Output:\n\tres = [";
    for (auto s : result)
    {
        cout << '"' << s << "\",";
    }
    cout << "]\n";

    return 0;
}

