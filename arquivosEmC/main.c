#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int exa();
int exb();
int exc();
int exd();

int main()
{
    setlocale(LC_ALL,"portuguese");
    char option;
    printf("Escolha  o exercicio:");
    scanf("%c",&option);
    switch (option)
    {
    case 'a':
        exa();
        break;
    case 'b':
        exb();
        break;
    case 'c':
        exc();
        break;
    case 'd':
        exd();
        break;
    default:
        printf("escolha inválida\n");
    }

    return 0;
}



