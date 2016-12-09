#include <stdio.h>

int isExist(int a[], int n, int value) {
  
    int left = 0;
  	int right = n - 1;

  	while (left <= right) {
    		int mid = (left + right) / 2;
    		if (value == a[mid])
    			 return 1;
    		else if (value < a[mid])
    			 right = mid - 1;
    		else if (value > a[mid])
      			left = mid + 1;
  	}
  	return 0;
}

int main(void) {
    int m, b[100000], n, a[100000];
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n - 1; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i <= m - 1; i++) {
        scanf("%d", &b[i]);
        if (isExist(a, n, b[i]) == 1)
            printf("1");
        else
            printf("0");
        if (i != m - 1)
            printf(" ");
    }

    return 0;
}
