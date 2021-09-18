#include <iostream>
#include <string>
#include <codecvt>
#include <locale.h>

using namespace std;

wstring utf8_to_wstring (const string& str)
{
    wstring_convert<codecvt_utf8<wchar_t>> conv;
    return conv.from_bytes(str);
}

string wstring_to_utf8 (const wstring& str)
{
    wstring_convert<codecvt_utf8<wchar_t>> conv;
    return conv.to_bytes(str);
}

int main(int argc, char **argv) {
    locale::global(locale(""));

    if (argc != 3) {
        cerr << "Incorrect number of arguments!" << endl;
        exit(1);
    }

    int n = stoi(argv[1]);
    string str = string(argv[2]);
    wstring wstr = utf8_to_wstring(str);

    wstring result;

    if (n >= wstr.size()) {
        result = wstring(n - wstr.length(), ' ') + wstr;
    } else {
        result = wstr.substr(wstr.length() - n, n);
    }

    transform(result.begin(), result.end(), result.begin(), towupper);

    cout << wstring_to_utf8(result) << endl;

    return 0;
}
