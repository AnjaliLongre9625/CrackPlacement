#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; // Using a vector as a stack
        
        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) { 
                st.push_back(asteroids[i]); // Push positive asteroids directly
            } else {
                // Handle collisions
                while (!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])) {
                    st.pop_back(); // Destroy smaller positive asteroid
                }
                
                // If stack is empty or last asteroid is negative, push current asteroid
                if (st.empty() || st.back() < 0) {
                    st.push_back(asteroids[i]);
                } 
                // If equal, both explode
                else if (st.back() == abs(asteroids[i])) {
                    st.pop_back();
                }
            }
        }
        return st;
    }
};

int main() {
    int n;
    cout << "Enter number of asteroids: ";
    cin >> n;

    vector<int> asteroids(n);
    cout << "Enter asteroid values: ";
    for (int i = 0; i < n; i++) {
        cin >> asteroids[i];
    }

    Solution sol;
    vector<int> result = sol.asteroidCollision(asteroids);

    cout << "Remaining asteroids: ";
    for (int ast : result) {
        cout << ast << " ";
    }
    cout << endl;

    return 0;
}
