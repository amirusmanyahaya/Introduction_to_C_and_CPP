#include <iostream>
#include <iomanip>

int main(){
    // define variables
    float currentPrice{};
    float lastPrice{};
    float stride{};
    float taxPercent{};
    int iterations{0};
    // get inputs for standard inputs and store in variables

    // First Price
    std::cout << "Enter First Price: " << std::flush;
    std::cin >> currentPrice;
    std::cin.ignore(1000,'\n');
    while(currentPrice < 0){
        std::cerr << "ERROR: First price must at least 0 (zero) sek" << std::endl;
        std::cout << "Enter First Price: " << std::flush;
        std::cin >> currentPrice;
        std::cin.ignore(1000,'\n');
    }

    // Last Price
    std::cout << "Enter Last Price: " << std::flush;
    std::cin >> lastPrice;
    std::cin.ignore(1000,'\n');
    while(lastPrice < 0){
        std::cerr << "ERROR: Last price must at least 0 (zero) sek" << std::endl;
        std::cout << "Enter Last Price: " << std::flush;
        std::cin >> lastPrice;
        std::cin.ignore(1000,'\n');
    }

    // Stride
    std::cout << "Enter Stride: " << std::flush;
    std::cin >> stride;
    std::cin.ignore(1000,'\n');
    while(stride < 0.01f){
        std::cout << stride - 0.01 << std::endl;
        std::cerr << "ERROR: stride must at least 0.01" << std::endl;
        std::cout << "Enter Stride: " << std::flush;
        std::cin >> stride;
        std::cin.ignore(1000,'\n');
    }

    // Tax Percentage
    std::cout << "Enter tax percentage: " << std::flush;
    std::cin >> taxPercent;
    std::cin.ignore(1000,'\n');
    while(taxPercent < 1){
        std::cerr << "ERROR: tax percent must be greater than 1" << std::endl;
        std::cout << "Enter tax percentage: " << std::flush;
        std::cin >> taxPercent;
        std::cin.ignore(1000,'\n');
    }

    // Displays tax table
    iterations = (lastPrice - currentPrice)/stride;
    if (iterations > 0) {
        std::cout << iterations << std::endl;
        std::cout << "TAX TABLE" << std::endl;
        std::cout << std::setfill('=') << std::setw(9) << "" << std::endl;
        std::cout << std::setfill(' ') << std::setw(10) << "Price" << std::setw(20) << "Tax" << std::setw(20) << "Price with tax" << std::endl;
        std::cout << std::setfill('-') << std::setw(50) << "" << std::endl;
        std::cout << std::setfill(' ') << std::fixed << std::flush;
        for(int i = 0; i <= iterations; ++i){
            std::cout <<std::setprecision(2)<< std::setw(10) << currentPrice << std::setw(20) << currentPrice * (taxPercent/100);
            std::cout << std::setw(20) << (currentPrice * (taxPercent/100)) + currentPrice << std::endl;
            currentPrice += stride;
        }
    }
    return 0;
}