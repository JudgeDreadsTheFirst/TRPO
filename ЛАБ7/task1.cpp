#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <ctime>

void print(std::vector<char> a){
    std::cout << "vector:";
    for (std::vector<char>::iterator it = a.begin(); it != a.end(); ++it){
        
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

bool consecutive_values(std::vector<char> c, int count, char a)
{
    return std::search_n(c.begin(), c.end(), count, a) != c.end();
}

int main(){
    std::srand(std::time(0));

    std::vector<char> s(1000);
    s[0] = 'a';

    std::vector<char> alph = {'a'};
    std::cout << "making array" << std::endl;
    for(auto i=1;i<=s.size();i++){
        s[i] = 'a' + rand()%24;
    }
    print(s);

    for(std::vector<char>::iterator its=s.begin(); its!=s.end();its++){
        int cnt = 0;
        for(std::vector<char>::iterator ita=alph.begin(); ita!=alph.end();ita++){
            if(*its == *ita){
                cnt++;
            }  
        }
        if(cnt==0){
            alph.insert(alph.end(), *its);
        }
        cnt = 0;
    }
    std::cout << "ALPHABET" << std::endl;
    print(alph);

    
    int max =0;
    for(auto i=2;i<=s.size();i++){
        for(std::vector<char>::iterator ita=alph.begin(); ita!=alph.end();ita++){
            for(std::vector<char>::iterator its=s.begin(); its!=s.end();its++){
                if(consecutive_values(s,i,*ita)){
                    if(i>max){
                        max = i;
                    }
                }
            }
        }
    }
    std::cout << "biggest symbol sequence:" << max << std::endl; 
    return 0;
}