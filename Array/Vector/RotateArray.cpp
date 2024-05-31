#include <bits/stdc++.h>
using namespace std;
void leftRotate(vector<int> &arr, int d)
{
    if (d == 0 || d == arr.size())
        return;
    d = d % arr.size();
    rotate(arr.begin(), arr.begin() + d, arr.end());
}
void rightRotate(vector<int> &arr, int d)
{
    if (d == 0 || d == arr.size())
        return;
    d = d % arr.size();
    rotate(arr.rbegin(), arr.rbegin() + d, arr.rend());
}
int main()
{
    vector<int> arr;
    int input;
    while (cin >> input && input != -1)
    {
        arr.push_back(input);
    }
    int k;
    cin >> k;
    // leftRotate(arr,k);
    rightRotate(arr, k);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}