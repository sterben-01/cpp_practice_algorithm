#include <stdio.h>

void func(int* s){
    if(*s > 0){
        (*s)--;
    }
    printf("ecev");
}
int main(){
    int pa = 1;
    for(int i = 0; i < 10; i++){
        int b = 200;
    }
    cout << b << endl;
    func(&pa);
    return 0;
}