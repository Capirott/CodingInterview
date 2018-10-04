#include <iostream>
#include <algorithm>
#include <cassert>
#include <map>

using namespace std;

#define ALPHABET_MAX_LENGTH 255


bool method1(const string first, const string second)
{
    string firstSorted = first;
    string secondSorted = second;

    sort(firstSorted.begin(), firstSorted.end());
    sort(secondSorted.begin(), secondSorted.end());

    return firstSorted == secondSorted;
}

bool method2(string first, string second)
{
    if (first.length() != second.length())
    {
        return false;
    }

    for (const char &ch : first) {
        size_t index = second.find(ch);
        if (index == string::npos)
        {
            return false;
        }
        second.erase(index, 1);
    }

    return second.empty();
}

bool method3(const string first, const string second)
{
    if (first.length() != second.length())
    {
        return false;
    }

    map<char, int> m;

    for (const char &ch : first)
    {
        m[ch]++;
    }

    for (const char &ch : second)
    {
        if (--m[ch] == -1)
        {
            return false;
        }
    }

    return true;
}

bool method4(const string first, const string second)
{
    if (first.length() != second.length())
    {
        return false;
    }

    int letters[ALPHABET_MAX_LENGTH] = {0};

    for (const char &ch : first)
    {
        letters[static_cast<int>(ch)]++;
    }

    for (const char &ch : second)
    {
        if (--letters[static_cast<int>(ch)] == -1)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    const string first  = "abcdefghijklmnopqrstuvwxyz";
    const string second = "bacdefhgijklmnopqrstuvwxyz";
    const string third  = "aacdefghijklmnopqrstuvwxyz";

    const bool res1 = method1(first, second);

    assert(res1 == true);
    assert(res1 == method2(first, second));
    assert(res1 == method3(first, second));
    assert(res1 == method4(first, second));

    assert(res1 != method1(first, third));
    assert(res1 != method2(first, third));
    assert(res1 != method3(first, third));
    assert(res1 != method4(first, third));

    return 0;
}
