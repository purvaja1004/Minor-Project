#include <iostream>
#include <vector>
#include <algorithm> // for sort()
using namespace std;

// Linear Search
int linearSearchVisualizer(vector<int>& arr, int target) {
    cout << "🔍 Linear Search Process:" << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << "Checking index " << i << " (value = " << arr[i] << ") 🧐" << endl;
        if (arr[i] == target) {
            cout << "🎉 Found at index " << i << "!" << endl;
            return i;
        }
    }
    cout << "🚫 Element not found." << endl;
    return -1;
}

// Binary Search
int binarySearchVisualizer(vector<int>& arr, int target) {
    cout << "🔍 Binary Search Process:" << endl;
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        cout << "Checking middle index " << mid << " (value = " << arr[mid] << ") 🔑" << endl;
        if (arr[mid] == target) {
            cout << "🎉 Found at index " << mid << "!" << endl;
            return mid;
        } else if (arr[mid] < target) {
            cout << "➡️ Target is greater than " << arr[mid] << ", moving right." << endl;
            left = mid + 1;
        } else {
            cout << "⬅️ Target is smaller than " << arr[mid] << ", moving left." << endl;
            right = mid - 1;
        }
    }
    cout << "🚫 Element not found." << endl;
    return -1;
}

int main() {
    int n, target, choice;
    vector<int> arr;
    
    cout << "🎯 Search Visualizer‍💻\n ";

    cout << "Enter number of elements: ";
    
    while (!(cin >> n) || n <= 0) {
        cout << "❌ Invalid input. Please enter a positive integer for the number of elements: ";
        cin.clear();
    }
    
    cout << "Enter elements: 📝" << endl;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    cout << "Enter target value to search: 🎯 ";
    cin >> target;

    cout << "\nChoose Search Method:\n1. Linear Search 🔍\n2. Binary Search 🔍\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        linearSearchVisualizer(arr, target);
    } else if (choice == 2) {
        sort(arr.begin(), arr.end());
        cout << "🔄 Array sorted for Binary Search." << endl;
        binarySearchVisualizer(arr, target);
    } else {
        cout << "🚫 Invalid choice!" << endl;
    }

    return 0;
}
