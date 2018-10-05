#include <iostream>
#include <cassert>
#include <vector>
#include <regex>

using namespace std;

unsigned int getStringLength(const char str[])
{
    unsigned int count = 0;
    while(str[count++]);
    return count;
}

unsigned int getNumberOfSpaces(const char str[])
{
    unsigned int count = 0;

    for (int i = 0; i < str[i]; ++i)
    {
        if (str[i] == ' ')
        {
            ++count;
        }
    }

    return count;
}


string method1(const string &str)
{
    return regex_replace(str, regex(" "), "%20");
}

string method2(const string &str)
{
    string newString;
    for (const char &ch : str)
    {
        newString += (ch != ' ' ? string(1, ch) : "%20");
    }

    return newString;
}

string method3(const char str[])
{
    unsigned int len = getStringLength(str);
    vector<char> newString (len + 2 * getNumberOfSpaces(str) - 1);
    unsigned int index = 0;

    const char *pointer = str;

    while (*pointer)
    {
        if (*pointer == ' ')
        {
            newString[index++] = '%';
            newString[index++] = '2';
            newString[index++] = '0';
        }
        else
        {
            newString[index++] = *pointer;
        }
        ++pointer;
    }

    return string(newString.begin(), newString.end());
}

int main()
{
    const string input  = "Mr John Smith ";
    const string output = "Mr%20John%20Smith%20";

    assert(output == method1(input));
    assert(output == method2(input));
    assert(output == method3(input.c_str()));

    return 0;
}
