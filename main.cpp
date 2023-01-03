#include <stdio.h>
#include <string>
#include <vector>


class obj{
private:
public:
    obj(){}
    ~obj(){}

    const std::string operator=(const obj& rhs){
        return "test01_eq";
    }
};

std::string& operator<<=(std::string& lhs, const obj& rhs){
    return lhs="test01";
}

/*
Impossible case:

> This is global operator, = cannot be global:
> ref: https://stackoverflow.com/questions/12848171/error-while-overloading-operator-must-be-a-nonstatic-member-function

const std::string& operator=(const std::string& lhs, const obj& rhs){
    return lhs="test01_eq";
}
*/

int& operator<<=(int& lhs, const obj& rhs){
    return lhs=12345;
}

int main(){
    printf("hello\n");

    class obj o;
//    std::string s <<= o;
    std::string s; s <<= o;
//    std::string s = o;
    printf("%s\n", s.c_str());

    int i; i <<= o;
    printf("%d\n", i);

    //---

    std::vector<std::string> v;
    v.push_back(std::string(""));
    v[0] <<= o;
    
    return 0;
}

