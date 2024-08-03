#include <bits/stdc++.h>
int firstMissing(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= 0)
        {
            arr[i] = n + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int index = abs(arr[i] - 1);
        if (index < n)
        {
            arr[index] *= -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            return i + 1;
        }
    }

    return n + 1;
}