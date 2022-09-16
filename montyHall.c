/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void estatisticas (long long unsigned int partidaAtual, 
                    long long unsigned int trocadorVitorias, 
                    long long unsigned int trocadorDerrotas, 
                    long long unsigned int bundaoVitorias, 
                    long long unsigned int bundaoDerrotas);

int main()
{
    long long unsigned int trocadorVitorias = 0, trocadorDerrotas = 0;
    long long unsigned int bundaoVitorias = 0, bundaoDerrotas = 0;
    int portaPremio;
    int acertou, chuteInicial;
    float porcentagem;
    long long unsigned int maxPartidas, printarACada;
    
    printf("Digite a quantidade de partidas a serem testadas: ");
    scanf("%llu", &maxPartidas);
    
    printf("Digite a porcentagem das partidas para exibição do resultado: ");
    scanf("%f", &porcentagem);
    
    printarACada = (maxPartidas * porcentagem / 100);
    
    for (long long unsigned int partidaAtual = 1; partidaAtual < maxPartidas; partidaAtual++){
    
        portaPremio = rand() % 3;
        
        // Trocador
        chuteInicial = rand() % 3;
        acertou =  (chuteInicial == portaPremio);
        
        if (acertou){
            trocadorDerrotas++;
        } else {
            trocadorVitorias++;
        }
        
        
        // Bundao
        chuteInicial = rand() % 3;
        acertou =  (chuteInicial == portaPremio);
        
        if (acertou){
            bundaoVitorias++;
        } else {
            bundaoDerrotas++;
        }
        
        
        if (partidaAtual % printarACada == 0){
            estatisticas(partidaAtual, trocadorVitorias, trocadorDerrotas, bundaoVitorias, bundaoDerrotas);    
        }
           
    }
    
    
    return 0;
}


void estatisticas (long long unsigned int partidaAtual, 
                    long long unsigned int trocadorVitorias, 
                    long long unsigned int trocadorDerrotas, 
                    long long unsigned int bundaoVitorias, 
                    long long unsigned int bundaoDerrotas){
                        
    long double pVitoriaTrocador = ((long double) trocadorVitorias / partidaAtual) * 100;
    long double pVitoriaBundao = ((long double) bundaoVitorias / partidaAtual) * 100;
    
    printf("Numero de partidas testadas:      %llu\n", partidaAtual);
    printf("Porcentagem de vitórias trocador: %Lf%%\n", pVitoriaTrocador);
    printf("Porcentagem de vitórias bundão  : %Lf%%\n\n", pVitoriaBundao);
    
}
