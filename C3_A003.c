/*
#include <stdio.h>

int main() {
    char s[100];
    int b[1000000], n, k;
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", &a);
        for (int i = 0; i <= strlen(a) - 1; i++) {
            switch(a[i]) {
                case 0 : b[i] += 6;
                          break;
                case 1 : b[i] += 2;
                          break;
                case 2 : b[i] += 5;
                          break;
                case 3 : b[i] += 5;
                          break;
                case 4 : b[i] += 4;
                          break;
                case 5 : b[i] += 5;
                          break;
                case 6 : b[i] += 6;
                          break;
                case 7 : b[i] += 3;
                          break;
                case 8 : b[i] += 7;
                          break;
                case 9 : b[i] += 6;
                          break;
                default  : b[i] += 0;
            };
        };
    };
    for (int i = 0; i <= n - 1; i++)
        printf("%d ", b[i]);

    scanf("%s", &s);
    printf("%s", s);
    return(0);
}
*/
#include <stdio.h>
#include <string.h>

char s[12];
int arr[1000000];

int test(){
    int sum = 0;
    char d[] = "6255456376";
    for(int i = 0; i < strlen(s); i++)
        sum = sum + (d[s[i] - 48] - 48);
    return sum;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", &s);
        arr[i] = test();
    }
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
