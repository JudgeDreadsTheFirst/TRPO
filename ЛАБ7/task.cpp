#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>

void print(std::vector<int> a){
    std::cout << "vector:";
    for (std::vector<int>::iterator it = a.begin(); it != a.end(); ++it){
        
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::vector<int> vec(23);
    std::iota(vec.begin(),vec.end(),12);

    print(vec);

    std::random_shuffle(vec.begin(),vec.end());
    
    std::cout << "shuffled ";
    print(vec);

    std::sort(vec.begin(),vec.end(),[](int a,  int b){
        if ((a % 3 != 0) and (b % 3 ==0)) return true;
        return false;
    });

    std::cout << "sorted ";
    print(vec);

    return 0;
}