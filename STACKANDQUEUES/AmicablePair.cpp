#include <bits/stdc++.h>
using namespace std;

bool amicablePair(int x, int y) {
    int sum = 0, sum1 = 0;
    for (int i = 1; i <= x / 2; i++) {
        if (x % i == 0) {
            sum += i;
        }
    }

    for (int i = 1; i <= y / 2; i++) {
        if (y % i == 0) {
            sum1 += i;
        }
    }
    if (x == sum1 && y == sum) return true;
    return false;
}

int main() {
    int x = 220, y = 284;

    if (amicablePair(x, y)) {
        cout << x << " and " << y << " are an amicable pair." << endl;
    } else {
        cout << x << " and " << y << " are not an amicable pair." << endl;
    }

    return 0;
}