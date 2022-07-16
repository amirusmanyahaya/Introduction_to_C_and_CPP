#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main(){
    // create an object of ifstream
    std::ifstream file{"psuedocode.txt"};
    if (!file){
        std::cerr << "File does not exist" << std::endl;
    }else{
        int numOfWords{0};
        int totalLetterCount{0};
        std::string word{};
        file >> word;
        std::string shortestWord{word};
        std::string longestWord{word};

        while (file >> word){

            if (word.length() < shortestWord.length()){
                shortestWord = word;
            }

            if (word.length() > longestWord.length()){
                longestWord = word;
            }

            numOfWords += 1;
            totalLetterCount += word.length();

        }

        std::cout << "There are " << numOfWords << " words in the file." << std::endl;
        std::cout << "The shortest word was \"" << shortestWord << "\" with " << shortestWord.length() << " characters(s)." << std::endl;
        std::cout << "The longest word was \"" << longestWord << "\" with " << longestWord.length() << " characters(s)." << std::endl;
        std::cout << "The average length was " << std::fixed << std::setprecision(2) << (double)(totalLetterCount/numOfWords) << " characters(s)." << std::endl; 
    }


    return 0;
}