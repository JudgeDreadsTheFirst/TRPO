#include <iostream>
#include <algorithm>
#include <functional>
#include <list>
#include <math.h>

struct Func
{
    int sum = 0;
    void operator()(int x)
    {
        bool fl = true;
        int sq = sqrt(x);
        if(x == 1){
            return ;
        }else{
            for (auto i = 2; i <= sq; i++) {
                if (x % i == 0) {
                    fl = false;
                }
            
            }
            if(fl == true){
                sum+=x;
            }
        }
    } 
    
};

int main()
{
    std::list<int> l = {8, 4, 2, 0, 16, 5, 2, 7};

    Func s = std::for_each(l.begin(),l.end(), Func());
    std::cout << s.sum << " ";


    return 0;
}