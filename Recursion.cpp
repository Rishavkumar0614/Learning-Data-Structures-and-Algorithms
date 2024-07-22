#include <vector>
#include <string>
#include <iostream>
using namespace std;

bool isPrime(int);
int Factorial(int);
int Power(int, int);
int NthFibonacci(int);
string Reverse(string);
string reverse(string);
string replacePI(string);
bool isSorted(int[], int);
string moveXToEnd(string);
void PrintPrime(int, bool);
void countSort(int[], int);
bool nQueen(int **, int, int);
string RemoveDuplicates(string);
int LastOcc(int[], int, int, int);
int FirstOcc(int[], int, int, int);
bool isSafe(int **, int, int, int);
bool isSafeQueen(int **, int, int, int);
vector<int> FirstAndLastOcc(int[], int, int);
bool RatInMaze(int **, int, int, int, int **);
void TOH(int, char = 'A', char = 'B', char = 'C');
bool isSafe(int **array, int x, int y, int n) { return (x < n && y < n && array[x][y] == 1); }

string Reverse(string s)
{
    if (s.size() == 1)
    {
        return s;
    }
    string str = Reverse(s.substr(1));
    return str + s[0];
}

string RemoveDuplicates(string s)
{
    if (s.size() == 1)
    {
        return s;
    }
    string str = RemoveDuplicates(s.substr(1));
    if (str[0] == s[0])
    {
        return str;
    }
    else
    {
        return s[0] + str;
    }
}

string moveXToEnd(string s)
{
    if (s.size() == 1)
    {
        return s;
    }
    if (s[0] != 'X' && s[0] != 'x')
    {
        return s[0] + moveXToEnd(s.substr(1));
    }
    else
    {
        return moveXToEnd(s.substr(1)) + s[0];
    }
}

bool RatInMaze(int **array, int x, int y, int n, int **solArray)
{
    if (x == n - 1 && y == n - 1)
    {
        return true;
    }
    if (isSafe(array, x, y, n))
    {
        solArray[x][y] = 1;
        if (RatInMaze(array, x + 1, y, n, solArray))
        {
            return true;
        }
        if (RatInMaze(array, x, y + 1, n, solArray))
        {
            return true;
        }
        solArray[x][y] = 0;
        return false;
    }
    return false;
}

bool isSafeQueen(int **array, int x, int y, int n)
{
    int row, col;
    for (col = 0; col < n; col++)
    {
        if (array[x][col])
        {
            return false;
        }
    }
    for (row = 0; row < n; row++)
    {
        if (array[row][y])
        {
            return false;
        }
    }
    row = x;
    col = y;
    while (col >= 0 && row >= 0)
    {
        if (array[row][col])
        {
            return false;
        }
        row--;
        col--;
    }
    row = x;
    col = y;
    while (row >= 0 && col < n)
    {
        if (array[row][col])
        {
            return false;
        }
        row--;
        col++;
    }
    return true;
}

bool nQueen(int **array, int x, int n)
{
    if (x >= n)
    {
        return true;
    }
    for (int col = 0; col < n; col++)
    {
        if (isSafeQueen(array, x, col, n))
        {
            array[x][col] = 1;
            if (nQueen(array, x + 1, n))
            {
                return true;
            }
            array[x][col] = 0;
        }
    }
    return false;
}

void countSort(int arr[], int n)
{
    int maxno = arr[0], minno = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (maxno < arr[i])
        {
            maxno = arr[i];
        }
        if (minno > arr[i])
        {
            minno = arr[i];
        }
    }
    int count = 0;
    int *countArray = new int[maxno - minno];
    for (int i = 0; i < (maxno - minno); i++)
    {
        countArray[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        countArray[arr[i] - minno]++;
    }
    for (int i = 0; i < (maxno - minno); i++)
    {
        for (int j = 0; j < countArray[i]; j++)
        {
            arr[count] = i + minno;
            count++;
        }
    }
}

int NthFibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return NthFibonacci(n - 1) + NthFibonacci(n - 2);
}

bool isSorted(int arr[], int n)
{
    if (n == 1)
    {
        return true;
    }
    return ((arr[0] < arr[1]) && isSorted(arr + 1, n - 1));
}

bool isPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void PrintPrime(int n, bool dir = false)
{
    if (n == 1)
    {
        cout << "1 ";
        return;
    }
    if (dir)
    {
        PrintPrime(n - 1, dir);
        if (isPrime(n))
        {
            cout << n << " ";
        }
    }
    else
    {
        if (isPrime(n))
        {
            cout << n << " ";
        }
        PrintPrime(n - 1, dir);
    }
}

int FirstOcc(int arr[], int n, int k, int i = 0)
{
    if (n == 0)
    {
        return -1;
    }
    int ans;
    if (arr[0] == k)
    {
        ans = i;
    }
    else
    {
        ans = FirstOcc(arr + 1, n - 1, k, i + 1);
    }
    return ans;
}

int LastOcc(int arr[], int n, int k, int i = 0)
{
    if (n == 0)
    {
        return -1;
    }
    int ans;
    ans = LastOcc(arr + 1, n - 1, k, i + 1);
    if (ans == -1 && arr[0] == k)
    {
        ans = i;
    }
    return ans;
}

vector<int> FirstAndLastOcc(int arr[], int n, int k)
{
    vector<int> ans;
    ans.push_back(FirstOcc(arr, n, k));
    ans.push_back(LastOcc(arr, n, k));
    return ans;
}

string reverse(string str)
{
    if (str.size() == 0)
    {
        return str;
    }
    return (reverse(str.substr(1)) + str[0]);
}

string replacePI(string str)
{
    if (str.size() == 0)
    {
        return str;
    }
    if (str[0] == 'p' && str[1] == 'i')
    {
        return ("3.14" + replacePI(str.substr(2)));
    }
    else
    {
        return (str[0] + replacePI(str.substr(1)));
    }
}

void TOH(int n, char src, char help, char dest)
{
    if (n == 0)
    {
        return;
    }
    TOH(n - 1, src, dest, help);
    cout << src << " TO " << dest << endl;
    TOH(n - 1, help, src, dest);
}

int Power(int n, int p)
{
    if (p == 0)
    {
        return 1;
    }
    return (n * Power(n, p - 1));
}

int Factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return (n * Factorial(n - 1));
}