#include <stdio.h> 
#include <stdlib.h> 

int MatrixChainOrder(int p[], int n) 
{ 
    int m[n][n]; 
  
    for (int i = 1; i < n; i++) 
        m[i][i] = 0; 
  
    for (int L = 2; L < n; L++) 
    { 
        for (int i = 1; i < n - L + 1; i++) 
        { 
            int j = i + L - 1; 
            m[i][j] = __INT_MAX__; 
            for (int k = i; k <= j - 1; k++) 
            { 
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]; 
                if (q < m[i][j]) 
                    m[i][j] = q; 
            } 
        } 
    } 
  
    return m[1][n - 1]; 
} 

int main() 
{ 
    int n, i; 
    printf("Enter the number of matrices: "); 
    scanf("%d", &n); 
  
    int arr[n + 1]; 
  
    printf("Enter the dimensions of the matrices:\n"); 
    for (i = 0; i <= n; i++) 
    { 
        printf("Enter dimension %d: ", i); 
        scanf("%d", &arr[i]); 
    } 
  
    printf("Minimum number of multiplications is %d ", MatrixChainOrder(arr, n + 1)); 
  
    return 0; 
} 