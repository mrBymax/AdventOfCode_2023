#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>

int main() {
    std::ifstream file("../input/day_02_input");
    std::string line;
    int p1 = 0, p2 = 0;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string word;

        // Extract game id
        std::getline(iss, word, ':');
        int gameid = std::stoi(word.substr(5));

        bool possible = true;
        std::map<std::string, int> mincnts;

        // Process each round
        while (std::getline(iss, word, ';')) {
            std::istringstream iss_round(word);
            std::map<std::string, int> cnts;

            // Process each color
            while (iss_round >> word) {
                int count = std::stoi(word);
                iss_round >> word;
                cnts[word] += count;
                mincnts[word] = std::max(mincnts[word], cnts[word]);
            }

            if (!(cnts["red"] <= 12 && cnts["green"] <= 13 && cnts["blue"] <= 14)) {
                possible = false;
            }
        }

        if (possible) {
            p1 += gameid;
        }
        p2 += mincnts["red"] * mincnts["green"] * mincnts["blue"];
    }

    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;

    return 0;
}