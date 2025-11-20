#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include "Pattern.h"

std::string readFile(const std::string& filename){
    
    std::ifstream file(filename);
    if(!file.is_open()){
        std::cout<<"Error opening file: "<<filename<<std::endl;
        return "";
    }

    std::string result;
    std::string str;
    while(std::getline(file, str)){

        result += str;
        result.push_back('\n');
    }

    file.close();
    return result;

}

int main(){

    std::string trainingText = readFile("frankenstein.txt");

    if(trainingText.empty()){
        std::cerr << "Failed to read file or file is empty" << std::endl;
        return 1;
    }

    std::unordered_map<std::string, int> counts;
    std::unordered_map<std::string, std::vector<Pattern>> lookup;

    int length = 3;

    //gather patterns from training text
    for(size_t i = 0; i <= trainingText.size() - length; i++){

        std::string pattern = trainingText.substr(i, length);
        counts[pattern]++;

    }
    
    //Get the pattern prefixes, and pattern counts
    for(const auto& [pattern, count] : counts){

        std::string prefix = pattern.substr(0, pattern.size()-1);
        Pattern p(pattern, count);
        lookup[prefix].push_back(p);
    }

    for (auto& [prefix, vec] : lookup) {
    
    //Find total count for this prefix
    int total = 0;
    for (const Pattern& pat : vec) {
        total += pat.getCount();
    }

    //cumulative probability
    double cumulative = 0.0;
    for (auto& pat : vec) {
        double prob = static_cast<double>(pat.getCount()) / total;
        cumulative += prob;
        pat.setCumulative(cumulative);
    }
}

//Generate text
srand(time(NULL));

int prefixLength = length - 1;

std::string prefix = lookup.begin()->first;

std::string generated = prefix;


for (int i = 0; i < 300; i++) {

   
    if (lookup.find(prefix) == lookup.end()) break;

    double r = (double)rand() / RAND_MAX;

    char nextChar = '\0';
    for (const Pattern& pat : lookup[prefix]) {
        if (r <= pat.getCumulative()) {
            nextChar = pat.getPattern().back();  
            break;
        }
    }

    
    if (nextChar == '\0') break;

    
    generated.push_back(nextChar);

    
    prefix = generated.substr(generated.size() - prefixLength);
}

    std::cout << generated << std::endl;
    return 0;
}