#include <iostream>
#include <map>
#include <nlohmann/json.hpp>


int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Invalid number of arguments!" << std::endl;
        exit(1);
    }

    std::string json_str = std::string(argv[1]);

    std::string progname, url;

    try {
        std::map<std::string, std::string> mymap = nlohmann::json::parse(json_str);
        progname = mymap["progname"];

        if (mymap.find("url") != mymap.end()) {
            url = mymap["url"];
        } else {
            std::cout << "Could not find value for \"url\" key. Using default value(https://www.ya.ru) instead"
                      << std::endl;
            url = "https://www.ya.ru";
        }
    } catch (std::exception &e) {
        std::cerr << "Failed to parse input json string" << std::endl;
        exit(1);
    }

    popen()





    return 0;
}
