#include <iostream>
#include <string>
#include <iomanip>

int main(){

    int intNum{0};
    double floatNum{0.0};
    char letter{};
    std::string word{};

    std::cout << "Enter one integer: " << std::flush;
    std::cin >> intNum;
    std::cin.ignore(1000,'\n');
    std::cout << "You entered the number: " << intNum << std::endl;
    
    std::cout << "Enter four integers: " << std::flush;
    std::cin >> intNum;
    std::cin.ignore(1000,' ');
    std::cout << "You entered the numbers: " << intNum << " ";
    std::cin >> intNum;
    std::cin.ignore(1000,' ');
    std::cout << intNum << " ";
    std::cin >> intNum;
    std::cin.ignore(1000,' ');
    std::cout << intNum << " ";
    std::cin >> intNum;
    std::cin.ignore(1000,'\n');
    std::cout << intNum << std::endl;
    
    std::cout << "Enter one integer and one real number: " << std::flush;
    std::cin >> intNum;
    std::cin >> floatNum;
    std::cin.ignore(1000,'\n');
    std::cout << "The real is: " << std::setw(10) << std::setprecision(4) << floatNum << std::endl;
    std::cout << "The integer is: " << std::setw(7) << intNum << std::endl;

    std::cout << "Enter one real and one integer number: " << std::flush;
    std::cin >> floatNum;
    std::cin >> intNum;
    std::cin.ignore(1000,'\n');
    std::cout << std::setfill('.');
    std::cout << "The real is: " << std::setw(11) << std::setprecision(4) << floatNum << std::endl;
    std::cout << "The integer is: " << std::setw(8) << intNum << std::endl;

    std::cout << "Enter a character: " << std::flush;
    std::cin >> letter;
    std::cin.ignore(1000,'\n');
    std::cout << "You entered: " << letter << std::endl;


    std::cout << "Enter a word: " << std::flush;
    std::cin >> word;
    std::cin.ignore(1000,'\n');
    std::cout << "The word " << "'" << word << "' has " << word.length() << " character(s)." << std::endl;

    std::cout << "Enter an integer and a word: " << std::flush;
    std::cin >> intNum;
    std::cin >> word;
    std::cin.ignore(1000,'\n');
    std::cout << "you entered " << "'" << intNum << "' and '" << word << "'." << std::endl;

    std::cout << "Enter an character and a word: " << std::flush;
    std::cin >> letter;
    std::cin >> word;
    std::cin.ignore(1000,'\n');
    std::cout << "You entered the string \"" << word << "\" and the character " << "'" << letter << "'." << std::endl;

    std::cout << "Enter a word and real number: " << std::flush;
    std::cin >> word;
    std::cin >> floatNum;
    std::cin.ignore(1000,'\n');
    std::cout << "You entered \"" << word << " and \"" << std::fixed << std::setprecision(3) << floatNum << "\"." << std::endl;

    std::cout << "Enter a text-line: " << std::flush;
    std::getline(std::cin,word);
    std::cout << "You entered: "<< "\"" << word << "\"" << std::endl;

    std::cout << "Enter a second line of text: " << std::flush;
    std::getline(std::cin,word);
    std::cout << "You entered: " << "\"" << word << "\"" << std::endl;

    std::cout << "Enter three words: " << std::flush;
    std::cin >> word;
    std::cout << "You entered: " << "'" << word << " ";
    std::cin >> word;
    std::cout << word << " ";
    std::cin >> word;
    std::cin.ignore(1000,'\n');
    std::cout << word << "'" << std::endl;




    return 0;
}