#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <string>

void get_country_set(const std::string& confirmed_cases_file, std::set<std::string>& countries, std::map<std::string, std::map<std::string, int>>& map) {
    std::ifstream infile(confirmed_cases_file);

    if (infile.fail()) {
        std::cerr << "Cannot open file." << confirmed_cases_file << std::endl;
        return;
    }

    std::string line;
    std::getline(infile, line);

    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        std::string skip, province_state, country_region, confirmed;
        
        std::getline(ss, skip, ',');
        std::getline(ss, skip, ',');
        std::getline(ss, province_state, ',');
        std::getline(ss, country_region, ',');
        std::getline(ss, skip, ',');
        std::getline(ss, skip, ',');
        std::getline(ss, skip, ',');
        std::getline(ss, confirmed, ',');
        
        countries.insert(country_region);

        int confirmed_cases = std::stoi(confirmed);
        std::string state_or_country;

        if (province_state.empty()) {
            state_or_country = country_region;
        }
        state_or_country = province_state;

        map[country_region][state_or_country] += confirmed_cases;
    }

    infile.close();
}

void do_commands(const std::string& commands_file, const std::set<std::string>& countries, const std::map<std::string, std::map<std::string, int>>& map) {
    std::ifstream infile(commands_file);

    if (infile.fail()) {
        std::cerr << "Cannot open file." << commands_file << std::endl;
        return;
    }

    std::string line;

    while (std::getline(infile, line)) {
        if (line.find("set ") == 0) {
            std::string country = line.substr(4);
            std::cout << (countries.count(country) ? 1 : 0) << std::endl;
        }
        else if (line.find("map ") == 0) {
            std::string country_or_state = line.substr(4);
            size_t include_state = country_or_state.find(';');

            if (include_state == std::string::npos) {
                std::string country = country_or_state;

                if (map.find(country) != map.end()) {
                    int total_cases = 0;
                    for (auto& stateCasesPair : map.at(country)) {
                        total_cases += stateCasesPair.second;
                    }
                    std::cout << total_cases << std::endl;
                }
                else {
                    std::cout << -1 << std::endl;
                }
            }
            else {
                std::string country = country_or_state.substr(0, include_state);
                std::string state = country_or_state.substr(include_state + 1);

                if (map.find(country) != map.end() && map.at(country).find(state) != map.at(country).end()) {
                    std::cout << map.at(country).at(state) << std::endl;
                }

                else {
                    std::cout << -1 << std::endl;
                }
            }
        }
    }

    infile.close();
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Expected Command Line Arguments: " << argv[0] << " <dataset.csv> <commands.txt>" << std::endl;
        return 1;
    }

    std::string confirmed_cases_file = argv[1];
    std::string commands_file = argv[2];

    std::set<std::string> countries;
    std::map<std::string, std::map<std::string, int>> map;

    get_country_set(confirmed_cases_file, countries, map);
    do_commands(commands_file, countries, map);
}