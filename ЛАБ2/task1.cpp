#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <typeinfo>
#include <iterator>

void print(std::vector<int> a){
    std::cout << "vector:";
    for (std::vector<int>::iterator it = a.begin(); it != a.end(); ++it){
        
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::srand(std::time(0));

    std::vector<int> a;
    std::string s;
    std::cout << "enter size of the vector" << std::endl;
    std::getline(std::cin,s);

    for (auto i =0; i <=std::stoi(s);i++){
        a.push_back(std::rand() % 100);
    }

    print(a);
    
    std::vector<int> b;
    for (auto i = 0; i <= a.size(); i++){
        if(a[i]%2 != 0){
            b.insert(b.end(),a[i]);
        }
    }
    a.insert(a.begin(),b.begin(),b.end());
    print(a);
    return 0;
}