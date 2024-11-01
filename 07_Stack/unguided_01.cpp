#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

bool isPalindrome(string str) {
    stack<char> s;

    for (char c : str) {
        if (isalpha(c)) {
            s.push(tolower(c));
        }
    }

    for (char c : str) {
        if (isalpha(c)) {
            if (tolower(c) != s.top()) {
                return false;
            }
            s.pop();
        }
    }
    return true;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);
    
    if (isPalindrome(kalimat)) {
        cout << "Kalimat adalah palindrom." << endl;
    } else {
        cout << "Kalimat bukan palindrom." << endl;
    }
    
    return 0;
}
