#include <iostream>
#include <iomanip>

int main() {
    int value = 255;

    std::cout << "Left-aligned:" << std::endl;
    std::cout << std::left << std::setw(15) << std::setfill('*') << "Decimal: " << std::dec << std::setw(15) << std::setfill(' ') << std::left << value << std::endl;
    std::cout << std::left << std::setw(15) << std::setfill('*') << "Octal: " << std::oct << std::setw(15) << std::setfill(' ') << std::left << value << std::endl;
    std::cout << std::left << std::setw(15) << std::setfill('*') << "Hexadecimal: " << std::hex << std::setw(15) << std::setfill(' ') << std::left << value << std::endl;

    std::cout << "\nRight-aligned:" << std::endl;
    std::cout << std::right << std::setw(15) << std::setfill('*') << "Decimal: " << std::dec << std::setw(15) << std::setfill(' ') << std::right << value << std::endl;
    std::cout << std::right << std::setw(15) << std::setfill('*') << "Octal: " << std::oct << std::setw(15) << std::setfill(' ') << std::right << value << std::endl;
    std::cout << std::right << std::setw(15) << std::setfill('*') << "Hexadecimal: " << std::hex << std::setw(15) << std::setfill(' ') << std::right << value << std::endl;

    return 0;
}

