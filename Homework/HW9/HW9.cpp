#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> findBuildingsWithOceanView(const vector<int>& heights) {
    int n = heights.size();
    vector<int> result; // Grabs the indices of buildings with ocean views
    int maxHeight = 0; // Looks for the tallest building
    
    // Loop to move through the array
    for (int i = n - 1; i >= 0; --i) {
        // If the height of selected building is taller than any to the right
        if (heights[i] > maxHeight) {
            result.push_back(i); // Adds the index to the result
            maxHeight = heights[i]; // Updates the tallest height to current building
        }
    }

    // Reverses the result so indices are in increasing order
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    // Example 1
    vector<int> heights1 = {4, 2, 3, 1};
    vector<int> result1 = findBuildingsWithOceanView(heights1);
    cout << "Example 1 Output: ";
    for (int index : result1) cout << index << " ";
    cout << endl;

    // Example 2
    vector<int> heights2 = {4, 3, 2, 1};
    vector<int> result2 = findBuildingsWithOceanView(heights2);
    cout << "Example 2 Output: ";
    for (int index : result2) cout << index << " ";
    cout << endl;

    // Edge case: One building
    vector<int> heights3 = {10};
    vector<int> result3 = findBuildingsWithOceanView(heights3);
    cout << "Edge Case (Single Building) Output: ";
    for (int index : result3) cout << index << " ";
    cout << endl;

    // Edge case: Same height buildings
    vector<int> heights4 = {5, 5, 5, 5};
    vector<int> result4 = findBuildingsWithOceanView(heights4);
    cout << "Edge Case (Same Height Buildings) Output: ";
    for (int index : result4) cout << index << " ";
    cout << endl;

    return 0;
}