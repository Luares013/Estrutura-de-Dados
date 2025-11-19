#include <stdio.h>
#include <string.h>

#define MAX 5 //maximo de 5 alunos

typedef struct{
    char nome[50];
    float nota[3], media;
    int matricula;
} Aluno;

void cadastrarAlunos(Aluno *alunos, int *quantidade);
void calcularMedias(Aluno *alunos, int quantidade);
float calcularMediaTurma(Aluno *alunos, int quantidade);
void exibirRelatorio(Aluno *alunos, int quantidade); 

int main(){
    
    printf("===================================\n");
    printf("Bem Vindo ao Cadastro de Alunos.");
    printf("\n===================================\n");
    
    Aluno turma[MAX];
    int qtd =5;

    cadastrarAlunos(turma, &qtd);
    calcularMedias(turma, qtd);
    exibirRelatorio(turma, qtd);
    
    return 0;
}

//parte de cadastro dos alunos

void cadastrarAlunos(Aluno *alunos, int *quantidade){

    for (int i=0; i<*quantidade; i++){
        printf("\nAluno %d\n", i+1);

        printf("Digite o nome do aluno: ");
        fgets((alunos+i)->nome, 50, stdin);
        (alunos+i)->nome[strcspn((alunos+i)->nome, "\n")] = '\0';     //isso faz com que n quebre a linha

        printf("Digite a matricula do aluno: ");
        scanf("%d", &(alunos+i)->matricula);

        getchar();
        
        for (int n=0; n<3;n++){
            printf("Nota %d:", n+1);
            scanf("%f", &(alunos+i)->nota[n]);
        }
        
        getchar();
    }
}

//Calculo da média dos alunos de forma individual

void calcularMedias(Aluno *alunos, int quantidade){
    for (int i=0; i<quantidade; i++){
        float soma =0;
        for (int n=0; n<3; n++){
            soma += (alunos+i)->nota[n];
        }
        (alunos+i)->media = soma/3;
    }
}

//Cauculo da média geral da turma

float calcularMediaTurma(Aluno *alunos, int quantidade){
    float soma =0;

    for (int i=0; i<quantidade; i++){
        soma+=(alunos+i)->media;
    }

    return soma/quantidade;
}

// Aqui o relatório de médias maior e menor

void exibirRelatorio(Aluno *alunos, int quantidade){
    float maior = alunos[0].media;
    float menor = alunos[0].media;
    int aprovados = 0;

    printf("\n======================================\n");
    printf("Estatisticas inviduais de cada aluno.");
    printf("\n======================================\n");


    for (int i=0; i<quantidade; i++){
        printf("\nAluno: %s\n", alunos[i].nome);
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Média: %.2f\n", alunos[i].media);

        if (alunos[i].media > maior){
            maior = alunos[i].media;
        }
        if (alunos[i].media < menor){ 
            menor = alunos[i].media;
        }
        if (alunos[i].media >= 7){
            aprovados++;
        }
    }
// Esse proximo quadro irá mostrar os resultados agrupados dos 5 alunos.
    float mediaTurma = calcularMediaTurma(alunos, quantidade);

    printf("\n===================================\n");
    printf(" Analise da turma:");
    printf("\n===================================\n");
    
    printf("Maior média: %.2f\n", maior);
    printf("Menor média: %.2f\n", menor);
    printf("Média geral da turma: %.2f\n", mediaTurma);
    printf("Número de alunos aprovados: %d\n", aprovados);
    printf("\n===================================\n");
}
