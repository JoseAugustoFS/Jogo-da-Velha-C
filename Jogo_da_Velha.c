#include<stdio.h>

int testar_ganhador(char tabela[][3],int linha, int coluna, char ganhador)
{
    int variavel_controle, repeticao=0;
    for(variavel_controle=0;variavel_controle<2;variavel_controle++)
    {
        if(tabela[variavel_controle][coluna]==tabela[variavel_controle+1][coluna])
        {
            repeticao++;
        }
    }

    if(repeticao!=2)
    {
        repeticao=0;
        for(variavel_controle=0;variavel_controle<2;variavel_controle++)
        {
            if(tabela[linha][variavel_controle]==tabela[linha][variavel_controle+1])
            {
                repeticao++;
            }
        }
    }
    if(repeticao!=2)
    {
        repeticao=-1;
        for(variavel_controle=0;variavel_controle<3;variavel_controle++)
        {
            if(tabela[variavel_controle][variavel_controle]==tabela[linha][coluna])
            {
                repeticao++;
            }
        }
    }
    if(repeticao!=2)
    {
        repeticao=-1;
        for(variavel_controle=0;variavel_controle<3;variavel_controle++)
        {
            if(tabela[variavel_controle][2-variavel_controle]==tabela[linha][coluna])
            {
                repeticao++;
            }
        }
    }
    if(repeticao==2)
    {
        ganhador=tabela[linha][coluna];
    }
    return ganhador;
}

void anunciar_ganhador(char ganhador)
{
    if(ganhador!=' '){
		printf("\n\n\n-------> O jogador '%c' ganhou! <-------",ganhador);
	}
	else
	printf("\n\n\n-------> Ninguem ganhou! <-------");
}

void preencher_tabela(char tabela[][3])
{
    int linha,coluna;
    for(linha=0;linha<3;linha++)
	{
		for(coluna=0;coluna<3;coluna++)
		{
			tabela[linha][coluna]=' ';
		}
	}
}

void imprimir_tabela(char tabela[][3])
{
    printf("  0  1  2 \n");
    printf("0 %c| %c |%c\n",tabela[0][0],tabela[0][1],tabela[0][2]);
    printf(" --+---+--\n");
    printf("1 %c| %c |%c\n",tabela[1][0],tabela[1][1],tabela[1][2]);
    printf(" --+---+--\n");
    printf("2 %c| %c |%c\n\n\n",tabela[2][0],tabela[2][1],tabela[2][2]);
}


int main()
{
	int linha, coluna, alternar_jogadores=0, etapas=9, erro=0;
	char tabela[3][3], ganhador=' ';
	preencher_tabela(tabela);
    imprimir_tabela(tabela);
	while((etapas>0)&&(ganhador==' '))
	{
		alternar_jogadores=1 - alternar_jogadores;
        if(alternar_jogadores==1)
	{
		printf("Digite o local do O (linha, coluna):\n");
		scanf("%i%i",&linha,&coluna);
		if((tabela[linha][coluna]==' ')&&(linha> -1)&&(linha<3)&&(coluna> -1)&&(coluna<3))
		{
		tabela[linha][coluna]='O';
		}
		else
        {
        erro++;
        }

        }
	if(alternar_jogadores==0)
	{
		printf("Digite o local do X (linha, coluna):\n");
		scanf("%i%i",&linha,&coluna);
		if((tabela[linha][coluna]==' ')&&(linha> -1)&&(linha<3)&&(coluna> -1)&&(coluna<3))
		{
		tabela[linha][coluna]='X';
		}
		else
        {
		erro++;
        }
        }
        printf("\n\n");

	if(erro==0){
		etapas++;
		imprimir_tabela(tabela);
	}
	else
    alternar_jogadores=1 - alternar_jogadores;
	ganhador=testar_ganhador(tabela,linha,coluna,ganhador);

}
	anunciar_ganhador(ganhador);
    return 0;
}
