{
    int n = nums.size();
    vector<vector<int, int>> v;
    for (int i = 0; i < n; i++){
        v.push_back(v[i], i);
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for (int i = 0; i < n; i++){

        if (v[i].second == i)
            continue;
        else
            swap(v[i], v[v[i].second]);
        cnt++;
        i--;
    }
    return cnt;
}