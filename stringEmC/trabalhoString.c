#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
int ex01();
int ex02();
int ex03();
int ex04();
int ex05();
int ex06();
int ex07();
int ex08();
int ex09();
int ex10();
int main()
{
    setlocale(LC_ALL,"portuguese");
    int esc;
    printf("Escolha  o exercicio:");
    scanf("%i",&esc);
    switch (esc)
    {
    case 1:
        ex01();
        break;
    case 2:
        ex02();
        break;
    case 3:
        ex03();
        break;
    case 4:
        ex04();
        break;
    case 5:
        ex05();
        break;
    case 6:
        ex06();
        break;
    case 7:
        ex07();
        break;
    case 8:
        ex08();
        break;
    case 9:
        ex09();
        break;
    case 10:
        ex10();
        break;
    default:
        printf("escolha inválida\n");
    }

    return 0;
}
int ex01()
{
    setlocale(LC_ALL,"portuguese");
    printf("\nLeia um conjunto indeterminado de palavras e ao final (estipule você um flag) informe qual foi a maior palavra e a menor palavra digitada, em tamanho e lexicograficamente.\n");
    char palavra[20],maiorTamanho[20],menorTamanho[20],maiorLexi[20],menorLexi[20];
    printf("\n\nDigite uma palavra (caso queira encerrar, digite fim): ");
    fflush(stdin);
    scanf("%s",palavra);
    strcpy(maiorTamanho,palavra);
    strcpy(menorTamanho,palavra);
    strcpy(maiorLexi,palavra);
    strcpy(menorLexi,palavra);
    while(strcmp(palavra,"fim")!=0)
    {

        if(strlen(palavra)>strlen(maiorTamanho))
            strcpy(maiorTamanho,palavra);
        if (strlen(palavra)<strlen(menorTamanho))
            strcpy(menorTamanho,palavra);
        if(strcmp(palavra,maiorLexi)>0)
            strcpy(maiorLexi,palavra);
        if(strcmp(palavra,menorLexi)<0)
            strcpy(menorLexi,palavra);
        printf("\n\nDigite uma palavra: ");
        fflush(stdin);
        scanf("%s",palavra);
    }
    if(strcmp(maiorTamanho,"fim")!=0)
    {
      printf("a maior palavra em tamanho é %s e lexicograficamente é %s\n",maiorTamanho,maiorLexi);
      printf("\na menor palavra em tamanho é %s e lexicograficamente é %s\n",menorTamanho,menorLexi);
    }
    return 0;
}
int ex02()
{
    setlocale(LC_ALL,"portuguese");
    printf("Ler um string de no máximo 50 caracteres e contar quantas letras A essa palavra possui.\n");
    char letrasA[50];
    int i,count=0;
    printf("\n\nDigite uma palavra de no máximo 50 caracteres: ");
    fflush(stdin);
    gets(letrasA);
    for(i=0;letrasA[i]!=NULL;i++)
    {
        if(letrasA[i]=='a'||letrasA[i]=='A')
            count++;
    }
    printf("\n%s possui %d letras A\n",letrasA,count);
    return 0;
}
int ex03()
{
    setlocale(LC_ALL,"portuguese");
    printf("Ler uma string de no máximo 50 caracteres e indicar quais as posições da letra A nessa palavra.");
    char posicaoA[50];
    int i;
    printf("\n\nDigite uma string de no máximo 50 caracteres: ");
    fflush(stdin);
    gets(posicaoA);
    for(i=0;posicaoA[i]!=NULL;i++)
    {
        if(posicaoA[i]=='a'||posicaoA[i]=='A')
            printf("\n\nLetra A na posição %d\n\n",i);
    }
    return 0;
}
int ex04()
{
    setlocale(LC_ALL,"portuguese");
    printf("Ler uma string de no máximo 50 caracteres e em seguida um caractere, mostrar quais as posições esse caractere aparece na string lida e quantas vezes ele apareceu.\n");
    char string[50],caractere;
    int i,count=0;
    printf("\n\nDigite uma string de no máximo 50 caracteres: ");
    fflush(stdin);
    gets(string);
    printf("\n\nDigite um caractere: ");
    fflush(stdin);
    scanf("%c",&caractere);
    for(i=0;string[i]!=NULL;i++)
    {
        if(string[i]==caractere)
        {
            printf("\n\"%c\" aparece na posição %d\n",caractere,i);
            count++;
        }
    }
    printf("\n\nO número de vezes em que %c aparece é: %d\n",caractere,count);
    return 0;
}
int ex05()
{
    setlocale(LC_ALL,"portuguese");
    printf(" Ler uma string de no máximo 50 caracteres e em seguida um caractere (entre A e z - consista se o caracter esta nesse intervalo), mostrar quais as posições esse caractere (maiúscula ou minúscula) na string lida e quantas vezes ele apareceu.");
    char string[50],caractere;
    int i,count=0;
    printf("\nDigite uma palavra de no máximo 50 caracteres: ");
    fflush(stdin);
    gets(string);
    printf("\nDigite um caractere: ");
    fflush(stdin);
    scanf("%c",&caractere);
    if(caractere>='A'&&caractere<='z')
    {
        for(i=0;string[i]!=NULL;i++)
        {
            if(caractere==string[i]||tolower(caractere)==string[i]||toupper(caractere)==string[i])
            {
            printf("\n\"%c\" aparece na posição %d\n",caractere,i);
            count++;
            }
        }
        printf("\n\nO número de vezes em que %c aparece é: %d\n",caractere,count);
    }
    else
        printf("\ncaractere invalido\n");
    return 0;
}
int ex06()
{
    setlocale(LC_ALL,"portuguese");
    printf("\n\nLer uma string de no máximo 50 caracteres e mostrar quantas letras possui e quantos caracteres são números e quantos não são nem números nem letras.\n\n");
    char string[50];
    int i,numeros=0,letras=0,nemNumerosNemLetras=0;
    printf("Digite uma string de no máximo 50 caracteres: ");
    fflush(stdin);
    gets(string);
    for(i=0;string[i]!=NULL;i++)
    {
        if(string[i]>='0'&&string[i]<='9')
                numeros++;
        else if(string[i]>='A'&&string[i]<='Z'||string[i]>='a'&&string[i]<='z')
                letras++;
        else
            nemNumerosNemLetras++;

    }
    printf("\n\na string possui %d letras, %d caracteres que são números e %d caracteres que não são nem números e nem letras\n\n",letras,numeros,nemNumerosNemLetras);
    return 0;
}
int ex07()
{
    setlocale(LC_ALL,"portuguese");
    printf("\n\nLer uma string de no máximo 50 caracteres e criar uma nova string com seu inverso, isso é a ultima letra da primeira string será a primeira na nova string e assim sucessivamente.\n");
    char string[50],stringInverso[50];
    int i,j;
    printf("\nDigite um string de no máximo 50 caracteres: ");
    fflush(stdin);
    gets(string);
    for(j=0, i=strlen(string)-1; j<strlen(string), i>=0; j++, i--)
    {
        stringInverso[j]=string[i];
    }
    printf("\n\nO inverso de %s e: %s",string,stringInverso);
    return 0;
}
int ex08()
{
    setlocale(LC_ALL,"portuguese");
    printf("\n\nLer uma string de no máximo 50 caracteres e retire dessa string todos os espaços em branco. Utilize uma string auxiliar.\n\n");
    char string[50],auxiliar[50];
    int i,j;
    printf("\nDigite um string com espaços em branco: ");
    fflush(stdin);
    gets(string);
    for(i=0, j=0; j<strlen(string); j++, i++)
    {
        while(string[j]==' ')
        {
            j++;
            auxiliar[i]=string[j];          /*Note que o i não vai sofrer incremento enquanto estiver sendo executado no laço while*/
        }
        auxiliar[i]=string[j];          /*Note que quando ele encerrar o while, o auxiliar[i] vai ser igual a um caractere diferente de espaço em branco. Daí ele vai repetir o trabalho de armazenar string[j] em auxiliar[i] nessa linha*/
    }
    auxiliar[i]='\0';
    printf("string sem espaços em branco: %s",auxiliar);
    return 0;
}
int ex09()
{
    setlocale(LC_ALL,"portuguese");
    printf("\n\nLer uma string de no máximo 50 caracteres e retire dessa string todos os espaços em branco. Sem utilizar string auxiliar.\n\n");
    char string[50];
    int i,j;
    printf("\nDigite um string com espaços em branco: ");
    fflush(stdin);
    gets(string);
    for(i=0, j=0; string[j]!=NULL; j++, i++)
    {
        while(string[j]==' ')
        {
            j++;
            string[i]=string[j];
        }
        string[i]=string[j];
    }
    string[i]='\0';
    printf("\n\nstring sem espaços em branco: %s\n\n",string);
    return 0;
}
int ex10()
{
    setlocale(LC_ALL,"portuguese");
    printf("\n\nLer uma string de no máximo 50 caracteres em seguida leia outra string de no máximo 3 caracteres, informe quantas vezes a segunda string aparece na primeira string, e diga as posições iniciais em que ela aparece.");
    char string1[51],string2[4];
    int i,count=0,j=0;
    printf("\n\nDigite uma string de no máximo 50 caracteres: ");
    fflush(stdin);
    gets(string1);
    printf("\n\nDigite outra string de no máximo 3 caracteres: ");
    fflush(stdin);
    gets(string2);
    for(i=0;i<strlen(string1); i++)
    {
       if((string2[j]==string1[i])&&(string2[j+1]==string1[i+1])&&(string2[j+2]==string1[i+2]))
       {
           count++;
           printf("\n\nAparece na posição: %d\n\n",i);
       }

    }
    printf("\n\nNúmero de vezes que a segunda string aparece na primeira string: %d\n\n",count);
    return 0;
}

