#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <math.h>
#include <typeinfo>

template <typename T> auto is_prime = [](T i){
            T sq = static_cast<T>(sqrt(i));
            if (i == static_cast<T>(1)){
                return false;
            }
            else{
                for (T k = 2; k <= sq; k++) {
                    if (i % k == 0) {
                        return false;
                    }
                }
                return true;
            }
        };

template <typename T> void find_simp(std::vector<T> v)
{
    auto res = std::find_if(v.begin(), v.end(), is_prime<T>);
    std::cout << "first simple:" << *res << std::endl;
}

template <typename T> void print(std::vector<T> v)
{
    std::cout << "vector:";
    for (typename std::vector<T>::iterator it = v.begin(); it != v.end(); it++){
        
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> v_int = {10,7,4,5,6,7,8};
    std::vector<short int> v_short = {1, 4, 66, 10, 3};
    std::vector<unsigned long int> v_u = {4, 8, 16,32,7,5};
    
    std::cout <<  typeid(v_int[0]).name() << std::endl;

    find_simp(v_int);

    std::cout << typeid(v_short[0]).name() << std::endl;

    find_simp(v_short);

    std::cout << typeid(v_u[0]).name() << std::endl;

    find_simp(v_u);


    return 0;
}