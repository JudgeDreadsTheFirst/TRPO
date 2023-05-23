#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> parseLine(std::string Line,char delimeter){
    std::stringstream ss(Line);
    std::vector<std::string> tokens;

    std::string val;
    int cnt = 0;
    while(std::getline(ss, val,delimeter)){
            //val.erase(remove_if(val.begin(), val.end(), ::isspace), val.end());
        if(!val.empty()){
            tokens.push_back(val);
        }
        else{
            throw std::invalid_argument("[ERROR]: empty string");// тут тоже на пустую строчку лучше выкинуть ошибку
        }
    }
    return tokens;
}

void print(std::vector<std::string> a){
    std::cout << "vector:";
    for (std::vector<std::string>::iterator it = a.begin(); it != a.end(); ++it){
        
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int checkLetters(std::vector<std::string> str){
    int num = 0;
    for (auto i =0; i <= str.size();i++){
        for(auto v = i+1; v<= str.size()-1;v++){
            if((str[i][0]==str[v][0]) && (str[i][str[i].size()-1] == str[v][str[v].size()-1]))
                num++;
        }
    }

    return num;
}
    
int main(){
    std::string str = "abobus cat dog god cant as";
    char delim=' ';
    std::vector<std::string> vec = parseLine(str,delim);
    print(vec);
    std::cout << "number of words in string:" << vec.size() << std::endl;
    std::cout << "number of words with equal first and last letter:" << checkLetters(vec) << std::endl;
    return 0;
}