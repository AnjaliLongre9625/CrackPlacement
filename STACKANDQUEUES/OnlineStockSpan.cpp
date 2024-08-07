#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class StockSpanner {
public:
    // Stack to store pairs of (price, span)
    stack<pair<int, int>> st;
    
    // Constructor
    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;
        // While stack is not empty and the top element's price is less than or equal to the current price
        while (!st.empty() && st.top().first <= price) {
            // Add the span of the top element to the current span
            span += st.top().second;
            // Pop the top element
            st.pop();
        }
        // Push the current price and its calculated span to the stack
        st.push({price, span});
        // Return the span
        return span;
    }
};

int main() {
    StockSpanner stockSpanner;
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    for (int price : prices) {
        cout << "Next price: " << price << " -> Span: " << stockSpanner.next(price) << endl;
    }
    return 0;
}
