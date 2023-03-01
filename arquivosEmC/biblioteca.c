#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int exa()
{
    setlocale(LC_ALL,"portuguese");
    printf("\na) Fazer um programa com um menu para gravar em um arquivo os 64 primeiros valores da s�rie:  1 1 2 3 5 8 13 21 34...\n\n");
    FILE *fibonacci;
    unsigned long long aux, a=0, b=1;
    if ((fibonacci=fopen("fibonacci.txt","w"))==NULL)
        printf("Erro de abertura!\n");
    else
    {
        for(int i=0; i<64; i++)
        {
            aux=a+b;
            fprintf(fibonacci,"%llu\n",aux);
            b=a;
            a=aux;

        }
        fclose(fibonacci);
    }
    system("pause");
    return 0;
}
int exb()
{
    setlocale(LC_ALL,"portuguese");
    printf("\nb) Fazer um programa com um menu para ler o arquivo letra a e armazenar os valores pares em um arquivo e os impares em outro arquivo\n");
    unsigned long long n;
    FILE *fibonacci=fopen("fibonacci.txt","r"), *pares=fopen("pares.txt","w"),*impares=fopen("impares.txt","w");
    if (fibonacci==NULL)
        printf("Erro de abertura\n");
    else
    {
        while (fscanf(fibonacci,"%llu\n",&n)!=EOF)
        {
            if (n%2==0)
            {
                fprintf(pares, "%llu\n",n);
            }
            else
            {
                    fprintf(impares,"%llu\n",n);
            }
        }
        fclose(fibonacci);
        fclose(pares);
        fclose(impares);
    }
    system("pause");
    return 0;
}
int exc()
{
    setlocale(LC_ALL,"portuguese");
    printf("\nc) ler o arquivo letra a e armazenar apenas os primos em um arquivo");
    unsigned long long n,i;
    int qd;
    FILE *fibonacci=fopen("fibonacci.txt","r"), *primos=fopen("primos.txt","w");
    if (fibonacci==NULL)
        printf("Erro de abertura\n");
    else
    {
        while (fscanf(fibonacci,"%llu\n",&n)!=EOF)
        {
            qd=0;
            printf("\n%llu\n",n);
            for(i=2; i<n; i++)
            {
                if (n%i==0)
                {
                    qd++;
                    break;
                }
            }
            if(qd==0&&n!=1)
                fprintf(primos,"%llu\n",n);
        }
        fclose(fibonacci);
        fclose(primos);
    }
    system("pause");
    return 0;
}
int exd()
{
    setlocale(LC_ALL,"portuguese");
    printf("\nd) leia um conjunto de valores (flag -1) e verifique para cada valor se ele se encontra ou n�o no arquivo gravado na letra a. Caso n�o exista dever� mostrar o valor anterior e o posterior a esse valor. Exemplo: caso seja lido o valor 8 � dever� ser mostrada a informa��o o valor 8 est� no arquivo na posi��o 6, caso o valor lido seja o 17 � dever� ser mostrada a informa��o o valor 17 n�o est� no arquivo, valores mais pr�ximos: 13 e 21.\n");
    FILE *fibonacci=fopen("fibonacci.txt","r");
    unsigned long long n,a,anterior,proximo;
    int i;
    if(fibonacci==NULL)
        printf("Erro de abertura\n");
    else
    {
        printf("\nDigite um valor: ");
        scanf("%llu",&a);
        while (a!=-1)
        {
            i=0;
            while (fscanf(fibonacci,"%llu\n",&n)!=EOF)
            {
                if(a>10610209857723||a<1) //Os unsigned long n�o armazena valores negativos!
                {
                    printf("O valor %llu n�o est� no arquivo e n�o est� no intervalo entre n�meros do arquivo fibonacci",a);
                    break;
                }
                if(a==n)
                {
                    printf("\nO valor %llu est� no arquivo e na posi��o %d\n",a,i);
                    break;
                }
                if (n>a)
                {
                    proximo=n;
                    printf("\nO valor %llu n�o est� no arquivo, valores mais pr�ximos: %llu e %llu\n",a,anterior,proximo);
                    break;
                }
                i++;
                anterior=n;
            }
            printf("\nDigite um valor: ");
            scanf("%llu",&a);
            fclose(fibonacci);
            fibonacci=fopen("fibonacci.txt","r");
        }
        fclose(fibonacci);
    }
    system("pause");
    return 0;
}
