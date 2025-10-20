#include <stdio.h>

int main() {
    float n=5, bill=0;

    scanf("%f", &n);
    
    if(n<=50){
        bill+=n*0.5;
    }else if(n<=100){
        bill= (50*0.5)+((n-50)*0.75);
    }else if(n<=250){
        bill= (50*0.5)+(100*0.75)+((n-150)*1.2);
    }else {
        bill= (50*0.5)+(100*0.75)+(100*1.2)+((n-250)*1.5);
    }
    bill+=bill*0.2;
    
    printf("Bill: %f\n", bill);
    
    return 0;
}
