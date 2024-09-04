#include <bits/stdc++.h>
using namespace std;

int findDuplicateNumber(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] == arr[j]) {
                return arr[i];  // Return the duplicate number
            }
        }
    }
    return -1;  // If no duplicate is found, return -1 or any other appropriate value
}

int main() {
    vector<int> arr = {1, 3, 4, 2, 2}; // Example input
    int duplicate = findDuplicateNumber(arr);
    cout << "The duplicate number is: " << duplicate << endl;
    return 0;
}
