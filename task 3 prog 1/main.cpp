#include <iostream>
#include <map>
#include <nlohmann/json.hpp>


std::pair<int, std::string> exec(std::string command) {
    char buffer[128];
    std::string result;

    FILE *pipe;
    try {
        pipe = popen(command.c_str(), "r");
    } catch (std::exception &e) {
        std::cerr << "Failed to execute create pipe for" + command << std::endl;
        exit(1);
    }
    if (!pipe) {
        std::cerr << "Failed to execute create pipe for" + command << std::endl;
        exit(1);
    }

    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }

    int st = pclose(pipe);
    return std::make_pair(st, result);
}


int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Invalid number of arguments!" << std::endl;
        exit(1);
    }

    std::string json_str = std::string(argv[1]);

    std::string progname, url;

    try {
        std::map<std::string, std::string> mymap = nlohmann::json::parse(json_str);
        if (mymap.find("progname") != mymap.end()) {
            progname = mymap["progname"];
        } else {
            std::cout << "Could not find value for \"progname\" key." << std::endl;
            exit(1);
        }

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

    auto f = std::fopen(progname.c_str(), "r");
    if (f) {
        fclose(f);
    } else {
        std::cerr << '\"' + progname + '\"' + " does not exist in the current directory" << std::endl;
        exit(1);
    }


    auto res = exec("./" + progname + " " + url + " 2>&1");

    nlohmann::json out;
    out["progname"] = progname;
    out["content"] = "";
    if (res.first == 0) {
        out["content"] = res.second;
    } else {
        if (res.second.empty()) {
            out["error"] = "No error description, only error code #" + std::to_string(res.first) + " was reported";
        } else {
            out["error"] = res.second;
        }
    }

    std::cout << out << std::endl;

    return 0;
}
