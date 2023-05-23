#include <iostream>

using namespace std;

int log2(int a){
    if(a == 0){
        throw invalid_argument("[ERROR]: arg can not be zero");
    }
    int logValue = -1;
    while(a){
        logValue++;
        a>>=1;
    }
    return logValue;
}

int log(int a,int b){
    return log2(a)/log2(b);
}

int main(){
    int a = 4;
    int b = 1;

    try {
        cout << log(b,a) << endl;
    }
    catch(invalid_argument e){
        cerr << e.what() << endl;
    }

    try {
        cout << log(a,b) << endl;
    }
    catch(invalid_argument e){
        cerr << e.what() << endl;
    }
    return 0;
}