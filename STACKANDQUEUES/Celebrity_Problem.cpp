#include <iostream>
#include <vector>
using namespace std;

int findCelebrity(vector<vector<int>>& mat) {
    int n = mat.size();
    vector<int> iknow(n, 0), knowme(n, 0);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {
                iknow[i]++;
                knowme[j]++;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (iknow[i] == 0 && knowme[i] == n - 1) {
            return i; // Celebrity found
        }
    }
    return -1; // No celebrity
}

int main() {
    vector<vector<int>> mat = {
        {0, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 1, 0, 1},
        {0, 1, 0, 0}
    };
    
    int celeb = findCelebrity(mat);
    if (celeb == -1) {
        cout << "No celebrity found" << endl;
    } else {
        cout << "Celebrity is at index: " << celeb << endl;
    }
    return 0;
}
