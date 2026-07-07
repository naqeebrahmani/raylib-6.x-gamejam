#include <iostream>
#include <vector>

int x(char array[]){

    return sizeof(array)/sizeof(char);
}


int main(){


    char array[] = {'h', 'e', 'l', 'l', 'o'};

    std::cout << sizeof(array)/sizeof(char) << "\n";

    
    std::cout << x(array);



    return 0;
}