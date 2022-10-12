#include <iostream>
#include <sstream>
#include <map>
using namespace std;


int main(void)
{
    map<string, string> dict;
    while (true) {
        string buffer;
        getline(cin, buffer);
        if (buffer.length() == 0) {
            break;
        }
        string key, value;
        stringstream(buffer) >> value >> key;
        dict[key] = value;
    }
    string word;
    while (cin >> word) {
        if (dict.find(word) != dict.end()) {
            cout << dict[word] << endl;
        } else {
            cout << "eh" << endl;
        }
    }
    return 0;
}

