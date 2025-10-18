#include <stdio.h>

int main() {
    //     * 
    //   * * 
    //   * * * 
    //  * * * * 
    // * * * * * 
    //  * * * * 
    //   * * * 
    //   * * 
    //     * 
    int n=5;
    for(int i=0; i<n; i++){
        // spaces
        for(int j=1; j<n-i; j++){
            printf(" ");
        }
        // stars
        for(int j=1; j<=i+1; j++){
            printf("* ");
        }
        printf("\n");
    }
    
    for(int i=0; i<n; i++){
        // stars
        for(int j=1; j<=i+1; j++){
            printf(" ");
        }
        // spaces
        for(int j=1; j<n-i; j++){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
