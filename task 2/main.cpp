#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
    if (argc != 3) {
        cerr << "Incorrect number of arguments!" << endl;
        exit(1);
    }

    int n = stoi(argv[1]);
    string str = string(argv[2]);

    cout << n << endl << str << endl;

    string result;

    if (n >= str.size()) {
        result = string(n - str.size(), ' ') + str;
    } else {
        result = str.substr(str.size() - n, n);
    }

    cout << result << endl;

    return 0;
}
