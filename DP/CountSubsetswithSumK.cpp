#include <iostream>
#include <vector>
using namespace std;

int findWays(vector<int> &arr, int k)
{
}
int main()
{
    int n, sum;

    // Input: Size of array and the target sum
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the target sum: ";
    cin >> sum;

    Solution sol;
    if (sol.isSubsetSum(arr, sum))
    {
        cout << "Subset with given sum exists!" << endl;
    }
    else
    {
        cout << "No subset with the given sum exists." << endl;
    }

    return 0;
}

