#include <vector>
#include <string>
#include <iostream>
using namespace std;

int GetSum(int[], int);
bool isPalindrome(int);
void swap(int &, int &);
bool isFascinating(int);
int Largest(int[], int);
void SumArray(int[], int);
int maxProduct(int[], int);
int FirstIndex(int[], int);
bool isPerfect(int[], int);
void bubbleSort(int[], int);
int ThirdLargest(int[], int);
void nextGreatest(int[], int);
int uniqueElement(int[], int);
string Longest(string[], int);
bool isPalinArray(int[], int);
int SecondLargest(int[], int);
bool PairSum(int[], int, int);
bool PairSum2(int[], int, int);
void PrintMaxTillI(int[], int);
void SelectionSort(int[], int);
void insertionSort(int[], int);
int GetOddOccurence(int[], int);
int TotalCount(int[], int, int);
void printAlternate(int[], int);
void maxSubArraySum1(int[], int);
void maxSubArraySum2(int[], int);
void ImmediateSmaller(int[], int);
int linearSearch(int[], int, int);
int binarySearch(int[], int, int);
int RecordBreakingDays(int[], int);
void SumOfEachSubarray(int[], int);
vector<float> streamAvg(int[], int);
void swapKthElement(int[], int, int);
void leftRotateArray(int[], int, int);
int FirstRepeatingElement(int[], int);
int FirstElementKTime(int[], int, int);
vector<int> FindIndex(int[], int, int);
void rightRotateArray(int[], int, int);
vector<int> valueEqualToIndex(int[], int);
vector<int> FindOccurence(int[], int, int);
void SubArrayWithGivenSum(int[], int, int);
void LongestArithmeticSubarray(int[], int);
vector<int> GetMoreAndLess(int[], int, int);
void scores(int[], int[], int &, int &, int);
void reverseInGroups(vector<int> &, int, int);
int SmallestPositiveNumberMissing(int[], int);
bool isEqualArray(vector<int>, vector<int>, int);

void PrintMaxTillI(int arr[], int n)
{
    int maxno = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (maxno < arr[i])
        {
            maxno = arr[i];
        }
        cout << maxno << " ";
    }
}

void SumOfEachSubarray(int arr[], int n)
{
    int sum = 0;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cout << "Sum Of Subarray ";
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
                cout << arr[k] << " ";
            }
            total++;
            cout << "Is " << sum << endl;
            sum = 0;
        }
    }
    cout << "Total Subarray Formed: " << total << endl;
}

void LongestArithmeticSubarray(int arr[], int n)
{
    int d;
    int temp = 2;
    int maxl = 2;
    int temps = 0;
    int s = 0, e = 0;
    for (int i = 0; i < (n - 1);)
    {
        d = arr[i + 1] - arr[i];
        if ((arr[i + 1] - arr[i]) == d)
        {
            temps = i;
            i++;
            while (((arr[i + 1] - arr[i]) == d) && i < (n - 1))
            {
                i++;
                temp++;
            }
            if (temp > maxl)
            {
                e = i;
                s = temps;
                maxl = temp;
            }
        }
    }
    cout << "Longest Arithmetic Subarray: ";
    for (int i = s; i <= e; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Length: " << maxl << endl;
}

int RecordBreakingDays(int arr[], int n)
{
    int maxv = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (arr[i] > arr[i + 1])
            {
                count++;
            }
        }
        else if (i == n - 1)
        {
            if (arr[i] > arr[i - 1] && arr[i] > maxv)
            {
                count++;
            }
        }
        else
        {
            if (arr[i] > maxv && arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            {
                count++;
            }
            if (arr[i] > maxv)
            {
                maxv = arr[i];
            }
        }
    }
    return count;
}

int FirstRepeatingElement(int arr[], int n)
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
    int *count = new int[(maxno - minno + 1)];
    for (int i = 0; i < (maxno - minno + 1); i++)
    {
        count[i] = -1;
    }
    int minidx = -1;
    for (int i = 0; i < n; i++)
    {
        if (count[arr[i] - minno] == -1)
        {
            count[arr[i] - minno] = i;
        }
        else if (minidx > count[arr[i] - minno] || minidx == -1)
        {
            minidx = count[arr[i] - minno];
        }
    }
    delete (count);
    return (minidx + 1);
}

void SubArrayWithGivenSum(int arr[], int n, int s)
{
    int j;
    int sum = 0;
    int temp = 0;
    bool flag = false;
    for (int i = temp; i < n; i++)
    {
        j = temp;
        sum += arr[i];
        if (sum > s)
        {
            while (sum > s && j <= i)
            {
                sum -= arr[j];
                j++;
            }
            if (sum < s)
            {
                i = temp;
                temp++;
            }
        }
        if (sum == s)
        {
            flag = true;
            cout << (j + 1) << " " << (i + 1);
        }
    }
    if (!flag)
    {
        cout << "-1";
    }
}

int SmallestPositiveNumberMissing(int arr[], int n)
{
    int maxno = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (maxno < arr[i] && arr[i] > 0)
        {
            maxno = arr[i];
        }
    }
    int minno = maxno;
    for (int i = 0; i < n; i++)
    {
        if (minno > arr[i] && arr[i] > 0)
        {
            minno = arr[i];
        }
    }
    bool *check = new bool[(maxno - minno + 1)];
    for (int i = 0; i < (maxno - minno + 1); i++)
    {
        check[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            check[arr[i] - minno] = true;
        }
    }
    for (int i = 0; i < (maxno - minno + 1); i++)
    {
        if (check[i] == false && (i + minno) > 0)
        {
            return (i + minno);
        }
    }
    delete (check);
    return -1;
}

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return (i + 1);
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int key)
{
    bubbleSort(arr, n);
    int s = 0,
        e = n,
        mid = 0;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (arr[mid] == key)
        {
            return (mid + 1);
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}

void SelectionSort(int arr[], int n)
{
    int minno;
    int minidx;
    for (int i = 0; i < (n - 1); i++)
    {
        minidx = i;
        minno = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (minno > arr[j])
            {
                minidx = j;
                minno = arr[j];
            }
        }
        swap(arr[i], arr[minidx]);
    }
}

void swap(int &p, int &q)
{
    int temp;
    temp = p;
    p = q;
    q = temp;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < (n - 1); i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(int arr[], int n)
{
    int j;
    int curr;
    for (int i = 1; i < n; i++)
    {
        j = i - 1;
        curr = arr[i];
        while (j >= 0 && curr < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr;
    }
}

void maxSubArraySum1(int arr[], int n)
{
    int subLength = arr[0],
        sum = 0,
        end = 0,
        start = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            if (sum > subLength)
            {
                end = j;
                start = i;
                subLength = sum;
            }
        }
    }
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
}

void maxSubArraySum2(int arr[], int n)
{
    int *cumsum = new int[n];
    for (int i = 0; i < n; i++)
    {
        cumsum[i] = arr[0];
    }
    for (int i = 1; i < n; i++)
    {
        cumsum[i] = cumsum[i - 1] + arr[i];
    }
    int sum = 0;
    int maxSum = 0;
    int s = 0, e = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum = cumsum[j] - cumsum[i];
            if (sum > maxSum)
            {
                s = i;
                e = j;
                maxSum = sum;
            }
        }
    }
    cout << "Max Sum: " << maxSum << endl;
    delete (cumsum);
}

bool PairSum(int arr[], int n, int k)
{
    for (int i = 0; i < (n - 1); i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[i] + arr[j]) == k)
            {
                return true;
            }
        }
    }
    return false;
}

bool PairSum2(int arr[], int n, int k)
{
    bubbleSort(arr, n);
    int l = 0, h = n - 1;
    while (l <= h)
    {
        if (arr[l] + arr[h] == k)
        {
            return true;
        }
        else if (arr[l] + arr[h] < k)
        {
            l++;
        }
        else
        {
            h--;
        }
    }
    return false;
}

void printAlternate(int array[], int n)
{
    for (int i = 0; i < n; i += 2)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

vector<int> valueEqualToIndex(int array[], int n)
{
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (array[i] == i + 1)
        {
            v.push_back(i + 1);
        }
    }
    return v;
}

int GetSum(int array[], int n)
{
    if (n == 0)
    {
        return -1;
    }
    else if (n == 1)
    {
        return array[0];
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += array[i];
    }
    return sum;
}

int Largest(int array[], int n)
{
    int maxno = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] > maxno)
        {
            maxno = array[i];
        }
    }
    return maxno;
}

int SecondLargest(int array[], int n)
{
    if (n == 0 || n == 1)
    {
        return -1;
    }
    int sl = -1;
    int maxno = Largest(array, n);
    for (int i = 0; i < n; i++)
    {
        if (array[i] > sl && array[i] < maxno)
        {
            sl = array[i];
        }
    }
    return sl;
}

bool isPalindrome(int num)
{
    int rem;
    int temp = num;
    int revnum = 0;
    while (num > 0)
    {
        rem = num % 10;
        num = num / 10;
        revnum = (revnum * 10) + rem;
    }
    return (revnum == temp);
}

bool isPalinArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!isPalindrome(array[i]))
        {
            return false;
        }
    }
    return true;
}

string Longest(string names[], int n)
{
    int lnindex = 0;
    int lnsize = names[0].size();
    for (int i = 1; i < n; i++)
    {
        if (names[i].size() > lnsize)
        {
            lnindex = i;
            lnsize = names[i].size();
        }
    }
    return names[lnindex];
}

void swapKthElement(int array[], int n, int k)
{
    swap(array[k - 1], array[n - k]);
}

vector<int> FindIndex(int array[], int n, int key)
{
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (array[i] == key && v[0] == -1)
        {
            v.insert(v.begin(), i);
        }
        if (array[n - i - 1] == key && v[1] == -1)
        {
            v.insert(v.begin() + 1, n - i - 1);
        }
    }
    return v;
}

vector<int> GetMoreAndLess(int array[], int n, int key)
{
    int count[2] = {0};
    for (int i = 0; i < n; i++)
    {
        if (array[i] < key)
        {
            count[1]++;
        }
        else if (array[i] > key)
        {
            count[2]++;
        }
        else
        {
            count[1]++;
            count[2]++;
        }
    }
    vector<int> v{count[0], count[1]};
    return v;
}

bool isPerfect(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (array[n - i - 1] != array[i])
        {
            return false;
        }
    }
    return true;
}

bool isFascinating(int num)
{
    string s = to_string(num);
    s += to_string(num * 2);
    s += to_string(num * 3);
    int count[9] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '1' && s[i] <= '9')
        {
            count[s[i] - '1']++;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (count[i] == 0 || count[i] > 1)
        {
            return false;
        }
    }
    return true;
}

vector<float> streamAvg(int array[], int n)
{
    float sum = 0;
    vector<float> v;
    for (int i = 0; i < n; i++)
    {
        sum += array[i];
        v.push_back(sum / (i + 1));
    }
    return v;
}

void scores(int a[], int b[], int &sa, int &sb, int n)
{
    int score[2] = {0};
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            score[0]++;
        }
        else if (a[i] < b[i])
        {
            score[1]++;
        }
    }
    sa = score[0];
    sb = score[1];
}

void rightRotateArray(int array[], int n, int posn)
{
    if (posn <= n)
    {
        int *temp = new int[posn];
        for (int i = 0; i < posn; i++)
        {
            temp[i] = 0;
        }
        for (int i = n - 1; i > n - posn - 1; i--)
        {
            temp[n - 1 - i] = array[i];
        }
        for (int i = n - posn - 1; i >= 0; i--)
        {
            array[i + posn] = array[i];
        }
        for (int i = posn - 1; i >= 0; i--)
        {
            array[i] = temp[posn - 1 - i];
        }
        delete (temp);
    }
}

void leftRotateArray(int array[], int n, int posn)
{
    if (posn <= n)
    {
        int *temp = new int[posn];
        for (int i = 0; i < posn; i++)
        {
            temp[i] = 0;
        }
        for (int i = 0; i < posn; i++)
        {
            temp[i] = array[i];
        }
        for (int i = 0; i < (n - posn); i++)
        {
            array[i] = array[i + posn];
        }
        for (int i = n - posn; i < n; i++)
        {
            array[i] = temp[i - (n - posn)];
        }
        delete (temp);
    }
}

vector<int> FindOccurence(int array[], int n, int key)
{
    int findex = -1, lindex = -1;
    for (int i = 0; i < n; i++)
    {
        if (array[i] == key && findex == -1)
        {
            findex = i;
        }
        if (array[n - i - 1] == key && lindex == -1)
        {
            lindex = n - i - 1;
        }
    }
    vector<int> v;
    v.push_back(findex);
    v.push_back(lindex);
    return v;
}

int ThirdLargest(int array[], int n)
{
    int tl = -1;
    int sl = SecondLargest(array, n);
    for (int i = 0; i < n; i++)
    {
        if (tl < array[i] && array[i] < sl)
        {
            tl = array[i];
        }
    }
    return tl;
}

void ImmediateSmaller(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            array[i] = array[i + 1];
        }
        else
        {
            array[i] = -1;
        }
    }
}

int TotalCount(int array[], int n, int k)
{
    int temp, sum = 0;
    int *count = new int[n];
    for (int i = 0; i < n; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        temp = array[i];
        while (temp > 0)
        {
            temp -= k;
            count[i]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        sum += count[i];
    }
    delete (count);
    return sum;
}

int FirstIndex(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i])
        {
            return i;
        }
    }
    return -1;
}

int GetOddOccurence(int array[], int n)
{
    int maxno = array[0], minno = array[0];
    for (int i = 0; i < n; i++)
    {
        if (maxno < array[i])
        {
            maxno = array[i];
        }
        if (minno > array[i])
        {
            minno = array[i];
        }
    }
    int *temp = new int[maxno - minno + 1];
    for (int i = 0; i < (maxno - minno + 1); i++)
    {
        temp[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        temp[array[i] - minno]++;
    }
    for (int i = 0; i < (maxno - minno + 1); i++)
    {
        if (temp[i] % 2 != 0)
        {
            return (i + minno);
        }
    }
    delete (temp);
    return -1;
}

void SumArray(int array[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += array[i];
    }
    for (int i = 0; i < n; i++)
    {
        array[i] = sum - array[i];
    }
}

int FirstElementKTime(int array[], int n, int k)
{
    int maxno = array[0], minno = array[0];
    for (int i = 1; i < n; i++)
    {
        if (maxno < array[i])
        {
            maxno = array[i];
        }
        if (minno > array[i])
        {
            minno = array[i];
        }
    }
    int *temp = new int[maxno - minno + 1];
    for (int i = 0; i < (maxno - minno + 1); i++)
    {
        temp[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        temp[array[i] - minno]++;
        if (temp[array[i] - minno] == k)
        {
            return array[i];
        }
    }
    delete (temp);
    return -1;
}

int maxProduct(int array[], int n)
{
    int maxno = array[0];
    for (int i = 1; i < n; i++)
    {
        if (maxno < array[i])
        {
            maxno = array[i];
        }
    }
    int sl = -1;
    for (int i = 0; i < n; i++)
    {
        if (sl < array[i] && array[i] < maxno)
        {
            sl = array[i];
        }
    }
    return sl * maxno;
}

int uniqueElement(int array[], int n)
{
    int maxno = array[0], minno = array[0];
    for (int i = 1; i < n; i++)
    {
        if (maxno < array[i])
        {
            maxno = array[i];
        }
        if (minno > array[i])
        {
            minno = array[i];
        }
    }
    int *temp = new int[maxno - minno + 1];
    for (int i = 0; i < (maxno - minno + 1); i++)
    {
        temp[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        temp[array[i] - minno]++;
    }
    for (int i = 0; i < (maxno - minno + 1); i++)
    {
        if (temp[i] % 2 != 0)
        {
            return (i + minno);
        }
    }
    delete (temp);
    return -1;
}

void reverseInGroups(vector<int> &array, int n, int k)
{
    int temp = 0;
    int size = n;
    while (n >= k)
    {
        for (int i = 0; i < (k / 2); i++)
        {
            swap(array[temp + i], array[temp + k - i - 1]);
        }
        n -= k;
        temp += k;
    }
    for (int i = 0; i < (n / 2); i++)
    {
        swap(array[temp + i], array[size - i - 1]);
    }
}

bool isEqualArray(vector<int> p, vector<int> q, int n)
{
    int maxno = p[0], minno = q[0];
    for (int i = 0; i < n; i++)
    {
        if (maxno < p[i])
        {
            maxno = p[i];
        }
        if (minno > p[i])
        {
            minno = p[i];
        }
    }
    int **temp = new int *[2];
    for (int i = 0; i < 2; i++)
    {
        temp[i] = new int[maxno - minno + 1];
    }
    for (int i = 0; i < (maxno - minno + 1); i++)
    {
        temp[0][i] = temp[1][i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (maxno < q[i])
        {
            return false;
        }
        temp[0][p[i] - minno]++;
        temp[1][q[i] - minno]++;
    }
    for (int i = 0; i < (maxno - minno + 1); i++)
    {
        if (temp[0][i] != temp[1][i])
        {
            return false;
        }
    }
    delete (temp);
    return true;
}

void nextGreatest(int array[], int n)
{
    int temp;
    int maxno = array[n - 1];
    for (int i = 0; i < n; i++)
    {
        temp = array[i];
        array[i] = maxno;
        if (maxno < temp)
        {
            maxno = temp;
        }
    }
}