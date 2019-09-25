#include <stdio.h>

int MAX_SIZE = 100000;

int countPasangan(int array[], int n){
    int pasangan = 0;
    if (n == 0 || n == 1) {
        return pasangan;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(array[i] == array[j]){
                pasangan++;
                break;
            }
        }
    }

    if (pasangan % 2 == 0)
        return pasangan/2;
    else
        return (pasangan/2) + 1;
}

int main()
{
    int array[MAX_SIZE];
    int n, temp;
    printf("Masukkan ada berapa data kaos kaki? ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i ++){
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
    
    int hasil = countPasangan(array, n);
    
    if (hasil != 0)
        printf("%d Pasang Kaos Kaki\n", hasil);
    else
        printf("Tidak ada data kaos kaki\n");
}
