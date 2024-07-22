#include <vector>
#include <string>
#include <iostream>
using namespace std;

bool isBinary(string);
void reverse(string &);
string transform(string);
void toLowerCase(string &);
string removeSpaces(string);
string delAlternate(string);
string removeVowels(string);
string convertString(string);
int countCamelCaseChar(string);
vector<int> countChars(string);
string longestName(string[], int);
vector<string> splitString(string);
vector<string> extractIntegerWords(string);

bool isBinary(string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != '1' || str[i] != '0')
        {
            return false;
        }
    }
    return true;
}

string longestName(string names[], int n)
{
    int lname = 0;
    int lnidx = 0;
    for (int i = 0; i < n; i++)
    {
        if (names[i].size() > lname)
        {
            lname = names[i].size();
            lnidx = i;
        }
    }
    return names[lnidx];
}

void toLowerCase(string &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] - ('A' - 'a');
        }
    }
}

void reverse(string &str)
{
    for (int i = 0; i < (str.size() / 2); i++)
    {
        swap(str[i], str[str.size() - i - 1]);
    }
}

string removeSpaces(string str)
{
    string newstr = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != ' ')
        {
            newstr += str[i];
        }
    }
    return newstr;
}

string delAlternate(string str)
{
    string newstr = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (i % 2 == 0)
        {
            newstr += str[i];
        }
    }
    return newstr;
}

int countCamelCaseChar(string str)
{
    int count = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            count++;
        }
    }
    return count;
}

string transform(string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ' && str[i + 1] != ' ' && i < str.size() - 1)
        {
            str[i + 1] += ('A' - 'a');
        }
        else if (i == 0)
        {
            str[0] += ('A' - 'a');
        }
    }
    return str;
}

vector<int> countChars(string str)
{
    vector<int> v{0, 0, 0, 0};
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            v[0]++;
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            v[1]++;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            v[2]++;
        }
        else
        {
            v[3]++;
        }
    }
    return v;
}

string removeVowels(string str)
{
    string newstr = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != 'a' && str[i] != 'A' && str[i] != 'e' && str[i] != 'E' && str[i] != 'i' && str[i] != 'I' && str[i] != 'o' && str[i] != 'O' && str[i] != 'u' && str[i] != 'U')
        {
            newstr += str[i];
        }
    }
    return newstr;
}

string convertString(string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += ('Z' - 'A' - 2 * (str[i] - 'A'));
        }
        else
        {
            str[i] += ('z' - 'a' - 2 * (str[i] - 'a'));
        }
    }
    return str;
}

vector<string> splitString(string str)
{
    vector<string> v{"", "", ""};
    for (int i = 0; i < str.size(); i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            v[0] += str[i];
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            v[1] += str[i];
        }
        else
        {
            v[2] += str[i];
        }
    }
    return v;
}

vector<string> extractIntegerWords(string str)
{
    string temp;
    vector<string> v;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            while (str[i] >= '0' && str[i] <= '9' && i < str.size())
            {
                temp += str[i];
                i++;
            }
            v.push_back(temp);
            temp = "";
        }
    }
    return v;
}