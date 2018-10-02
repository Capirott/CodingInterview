#include <map>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define ALPHABET_MAX_LENGTH 255

bool method1(const string str)
{
    const size_t len = str.length() - 1;

    string sorted = str;

    sort(sorted.begin(), sorted.end());

    for (size_t i = 0; i < len; ++i)
    {
        if (sorted[i] == sorted[i + 1])
        {
            return false;
        }
    }
    return true;
}

bool method2(const string str)
{
    map<char, int> hash;

    for (const char &ch : str)
    {
        if (hash[ch]++ > 0)
        {
            return false;
        }
    }
    return true;
}

bool method3(const string str)
{
    vector<bool> vec(ALPHABET_MAX_LENGTH);

    for (const char &ch : str)
    {
        std::_Bit_reference ref = vec[static_cast<unsigned>(ch)];
        if (ref)
        {
            return false;
        }
        ref = true;
    }

    return true;
}

int main()
{
    const string str = "abcdefghijklmnopqrstuvwxyz";
    const string str2 = "abcdefghijklmnopqrstuvwxyzd";
    const bool res1 = method1(str);

    assert(res1 == true);
    assert(res1 == method2(str));
    assert(res1 == method3(str));

    assert(method1(str2) == false);
    assert(method2(str2) == false);
    assert(method3(str2) == false);

    return 0;
}
