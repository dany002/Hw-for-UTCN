#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <any>

int main() {
    int intValue;
    float floatValue;
    double doubleValue;
    std::string stringValue;
    bool boolValue;
    std::vector<std::any> values;
    std::cout << "Give me the int value:\n";
    std::cin >> intValue;
    std::cout << "Give me the float value:\n";
    std::cin >> floatValue;
    std::cout << "Give me the double value:\n";
    std::cin >> doubleValue;
    std::cout << "Give me the string value:\n";
    std::cin >> stringValue;
    std::cout << "Give me the bool value:\n";
    std::cin >> boolValue;

    // Let s populate the vector :D
    values.push_back(intValue);
    values.push_back(floatValue);
    values.push_back(doubleValue);
    values.push_back(stringValue);
    values.push_back(boolValue);

    std::cout << std::setw(15) << "Values entered(decimal):" << std::endl;
    std::cout << std::left << std::setw(15) << std::setfill(' ') << "Integer: " << std::dec << std::any_cast<int>(values[0]) << std::endl;
    std::cout << std::left << std::setw(15) << std::setfill(' ') << "Float: " << std::fixed << std::setprecision(4) << std::any_cast<float>(values[1]) << std::endl;
    std::cout << std::left << std::setw(15) << std::setfill(' ') << "Double: " << std::fixed << std::setprecision(8) << std::any_cast<double>(values[2]) << std::endl;
    std::cout << std::left << std::setw(15) << std::setfill(' ') << "String: " << std::any_cast<std::string>(values[3]) << std::endl;
    std::cout << std::left << std::setw(15) << std::setfill(' ') << "Boolean: " << std::boolalpha << std::any_cast<bool>(values[4]) << std::endl;


    return 0;
}
