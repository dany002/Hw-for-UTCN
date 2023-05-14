#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <any>
#include <random>
#include <math.h>

int getRandomIntegers(int min, int max){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}

double getSqrtOfRandomInteger(int min, int max){
    return std::sqrt(getRandomIntegers(min, max));
}

int main() {
    const int DEVICES = 10;
    const int MINIMUM_RANGE = 100;

    int threshold;
    std::cout << "Threshold = ";
    std::cin >> threshold;

    std::vector<double> values(DEVICES);

    // Enter random numbers:
    for(int i = 0; i < DEVICES; i++)
        values[i] = getSqrtOfRandomInteger(MINIMUM_RANGE,MINIMUM_RANGE*(i+1));

    int sum = 0;
    for(const auto& value : values){
        int integer = static_cast<int>(value);
        sum += integer;
        std::cout << "Value: " << integer << std::endl;
    }
    std::cout << "Average: " << sum / DEVICES << std::endl;

    if(sum / DEVICES > threshold){
        std::cout << "Detailed\n";
        for(const auto& value : values)
            std::cout << std::fixed << std::setprecision(3) << value << std::endl;
    }

    return 0;
}
