#include <iostream>
#include <curl/curl.h>

using namespace std;

size_t callback(const char* in, size_t size, size_t num, string* out) {
    const size_t totalBytes(size * num);
    out->append(in, totalBytes);
    return totalBytes;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        cerr << "Invalid number of arguments!";
        exit(1);
    }

    CURL *curl;

    curl = curl_easy_init();

    long httpCode(0);
    unique_ptr<string> httpData(new string());

    if (curl) {
        try {
            curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());
            curl_easy_perform(curl);
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
            curl_easy_cleanup(curl);
        } catch (exception& e){
            cerr << "Failed to perform curl operations" << endl << e.what() << endl;
            exit(2);
        }
    } else {
        cerr << "Failed to init curl" << endl;
        exit(2);
    }

    if (httpCode == 200) {
        cout << httpData->c_str();
    } else {
        cerr << "HTTP response code not 200 OK. Got " << httpCode << "instead" << endl;
        exit(2);
    }

    return 0;
}
