/*#include <stdio.h>
void shiftzeros(int arr[], int n){
    int index = 0, arp[n];
    for(int i = 0; i < n ; i++)
    {
        if (arr[i]!= 0)
        {
            arp[index] = arr[i];
            index++;
        }
    }
while (index<n)
{
    arp[index] = 0;
    index++;
}
for (int i = 0; i < n; i++)
    {
        printf("%d", arp[i]);
    }
    
}
int main(void){
    int n,x, arr[50],arp[50];
    scanf("%d %d", &n, &x);
    int index = 0;
    // for (int i = 0; i < n; i++)// by this digits will store in reverse order;
    for(int i = n-1; i >= 0 ; i--)
    {
        arr[i]= x%10;
        x=x/10;
    }
    shiftzeros(arr, n);
    return 0;
   
}*/
#include <stdio.h>// chatgpt version ..kintu amr ta work kortese na in cf but exact same code

void shiftZerosToRight(int arr[], int n) {
    int index = 0; // Position to place non-zero elements

    // Move non-zero elements to the front
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[index++] = arr[i];
        }
    }

    // Fill remaining positions with zeros
    while (index < n) {
        arr[index++] = 0;
    }
}

int main(void) {
    int n;
    scanf("%d", &n); // Read number of elements

    int arr[n]; // Array to store the input

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Shift all zeros to the right
    shiftZerosToRight(arr, n);

    // Print the modified array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n"); // Ensure new line at the end (important for Codeforces)

    return 0;
}
