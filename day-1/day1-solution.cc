// 0-99 are nums on the lock
// L means turn left (decrease), R means turn right (increase)
// Following numbers are how many ticks to turn in that direction

#include <iostream>
#include <fstream>
#include <string>

int main(){

    std::string path = "input.txt";
    std::ifstream file{path};
    std::string line;
    
    int dialPosition = 50;
    int zeroCountPart1 = 0;
    int zeroCountPart2 = 0;

    // Part 1
    while (std::getline(file, line)) {
    
        char direction = line[0];
        int distance = std::stoi(line.substr(1));

        if (direction == 'L') {
            dialPosition = (dialPosition - distance + 100) % 100;
        } else if (direction == 'R') {
            dialPosition = (dialPosition + distance) % 100;
        }

        if (dialPosition == 0) {
            zeroCountPart1++;
        }
    }

    // Part 2
    file.clear();
    file.seekg(0);
    dialPosition = 50;

    while (std::getline(file, line)) {
    
        char direction = line[0];
        int distance = std::stoi(line.substr(1));

        for (int i = 1; i <= distance; i++) {
            if (direction == 'L') {
                dialPosition = (dialPosition - 1 + 100) % 100;
            } else if (direction == 'R') {
                dialPosition = (dialPosition + 1) % 100;
            }

            if (dialPosition == 0) {
                zeroCountPart2++;
            }
        }
    }

    std::cout << "Part 1" << zeroCountPart1 << std::endl;
    std::cout << "Part 2" << zeroCountPart2 << std::endl;

}