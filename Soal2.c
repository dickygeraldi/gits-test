#include <stdio.h>

int MAX_SIZE = 100000;

// Fungsi mencari nilai maksimum
int max(int after, int before){
    int max = before;
    if(after > before){
        max = after;
    }
    return max;
}

// Fungsi mencari count pairs
int countPairs(int array[], int n, int target){
    int sum = 0;
    int counter, maxcounter = 0;
    
    for (int i = 0; i < n; i++){
        if((sum + array[i] <= target) && counter < n){
            sum += array[i];
            counter++;
        }else if (sum != 0){
            sum = sum - array[i - counter] + array[i];
        }
        maxcounter = max(counter, maxcounter);
    }
    return maxcounter;
}

int main()
{
    int temp;
    int array[MAX_SIZE];
    int uang,n;
    printf("Masukkan uang yang dimiliki : ");
    scanf("%d", &uang);
    printf("Jumlah mainan : "); 
    scanf("%d", &n);
    
    if (n == 0)
        printf("Tidak ada data mainan\n");
    
    for (int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    
    // Sort array first using bubble Sort
    for (int i = 0; i < n; i++){
        for (int j = 0; j < (n - i - 1); j++){
            if(array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    
    
    int hasil = countPairs(array, n, uang);
    printf("%d Mainan yang bisa dibeli\n", hasil);
}
