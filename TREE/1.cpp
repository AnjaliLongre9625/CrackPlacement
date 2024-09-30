#include <bits/stdc++.h>
int fishEater(vector<int> &fishes)
{
    stack<int> s;

    for (int i = 0; i < fishes.size(); i++)
    {
        while (!s.empty() && fishes[i] > s.top())
        {
            s.pop();
        }
        s.push(fishes[i]);
    }
    return s.size();
}