#include <stdio.h>
int main() {
    int A, B;
    char S;
    
    // Read input
    scanf("%d", &A);  
    getchar();        // Consume the newline character left in the buffer
    scanf("%c", &S);  
    scanf("%d", &B);  

    // Check conditions
    if (S == '=' && A == B) {
        printf("Right");
    } else if (S == '<' && A < B) {
        printf("Right");
    } else if (S == '>' && A > B) {
        printf("Right");
    } else {
        printf("Wrong");
    }

    return 0;
}
