#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

void reverseEachWord(const string &str) {
    stringstream ss(str);
    string word;

    cout << "Data stack Array:\nData : ";
    while (ss >> word) {
        stack<char> s;

        for (char ch : word) {
            s.push(ch);
        }
        
        while (!s.empty()) {
            cout << s.top();
            s.pop();
        }

        cout << " ";
    }
    cout << endl;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    reverseEachWord(kalimat);
    return 0;
}
