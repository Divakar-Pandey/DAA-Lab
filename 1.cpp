#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<char, int> maxOccurrence(vector<char>& arr) {

    char maxChar = *max_element(arr.begin(), arr.end());
    int charRange = maxChar + 1;
    vector<int> count(charRange, 0);
    for (char c : arr) {
        count[c]++;
    }
    int maxCount = 0;
    bool isDuplicatePresent = false;
    for (int i = 0; i < charRange; ++i) {
        if (count[i] > maxCount) {
            maxChar = i;
            maxCount = count[i];
            isDuplicatePresent = true;
        } else if (count[i] == maxCount) {
            isDuplicatePresent = false;
        }
    }
    
    if (isDuplicatePresent)
        return make_pair(maxChar, maxCount);
    else
        return make_pair('\0', 0);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<char> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        pair<char, int> result = maxOccurrence(arr);
        if (result.first != '\0')
            cout << result.first << " " << result.second << endl;
        else
            cout << "No Duplicates Present" << endl;
    }
    return 0;
}
