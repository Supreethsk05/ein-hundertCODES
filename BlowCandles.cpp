#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int blowCandles(vector<int>& heights) {
    int max_height = *max_element(heights.begin(), heights.end());
    int count = 0;
    for (int height : heights) {
        if (height == max_height) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<int> heights = {2, 5, 3, 5, 6, 5, 1, 5};
    cout << "The number of candles that can be blown out is " << blowCandles(heights) << endl;

    return 0;
}
