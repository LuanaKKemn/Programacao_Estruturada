# include <stdio.h>

int main() {
    int n, i, bandeira = 0;
    printf("Digite um numero: \n");
    scanf("%d", &n);

    if (n <= 1){
        printf("%d nao eh um numero primo", n);
    } else {
        for (i = 2; i<=n/2; i++){
            if (n%2 == 0){
                bandeira = 1;
                break;
            }
        }
        if (bandeira == 0)
            printf("O numero %d eh primo", n);
        else
            printf("o numero %d nao eh primo", n);
    }


    return 0;
}