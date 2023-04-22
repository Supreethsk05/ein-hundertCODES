#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> count;

    // Count the frequency of each character
    for (char c : s) {
        count[c]++;
    }

    // Find the first character with frequency 1
    for (int i = 0; i < s.length(); i++) {
        if (count[s[i]] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    string s1 = "leetcode";
    cout << "The first non-repeating character in \"" << s1 << "\" is at index " << firstUniqChar(s1) << endl;

    string s2 = "loveleetcode";
    cout << "The first non-repeating character in \"" << s2 << "\" is at index " << firstUniqChar(s2) << endl;

    string s3 = "aabbcdd";
    cout << "The first non-repeating character in \"" << s3 << "\" is at index " << firstUniqChar(s3) << endl;

    return 0;
}
