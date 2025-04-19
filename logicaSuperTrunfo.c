/*
 * Super Trunfo - Comparador de Cidades
 * 
 * Programa que compara duas cidades brasileiras baseado em seus atributos.
 * Nivel: Aventureiro - Comparacao com menu interativo.
 */

#include <stdio.h>
#include <string.h>
#include <locale.h>

// Tamanho maximo para strings
#define TAM_STRING 100

// Opcoes do menu de comparacao
#define OPCAO_POPULACAO 1
#define OPCAO_AREA 2
#define OPCAO_PIB 3
#define OPCAO_PONTOS_TURISTICOS 4
#define OPCAO_DENSIDADE 5
#define OPCAO_SAIR 6

// Estrutura que representa uma cidade no jogo
typedef struct {
    char estado[TAM_STRING];          // Ex: SP, RJ, MG
    char codigo[TAM_STRING];          // Identificador da carta
    char nome[TAM_STRING];            // Nome da cidade
    int populacao;                    // Numero de habitantes
    float area;                       // Area em km2
    float pib;                        // PIB em milhoes
    int pontosTuristicos;            // Quantidade de pontos turisticos
    float densidadePopulacional;     // Calculado: populacao / area
    float pibPerCapita;              // Calculado: pib / populacao
} Cidade;

// Funcao para exibir o menu de opcoes
int exibirMenu() {
    int opcao;
    
    printf("\n=== Menu de Comparacao ===\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Pontos Turisticos\n");
    printf("5. Densidade Populacional\n");
    printf("6. Sair\n");
    printf("\nEscolha o atributo para comparacao: ");
    scanf("%d", &opcao);
    
    return opcao;
}

// Funcao para cadastrar os dados de uma cidade
void cadastrarCidade(Cidade *cidade) {
    printf("\n=== Cadastro de Cidade ===\n");
    
    printf("Digite o estado: ");
    scanf(" %[^\n]s", cidade->estado);
    
    printf("Digite o codigo da cidade: ");
    scanf(" %[^\n]s", cidade->codigo);
    
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]s", cidade->nome);
    
    printf("Digite a populacao: ");
    scanf("%d", &cidade->populacao);
    
    printf("Digite a area (km2): ");
    scanf("%f", &cidade->area);
    
    printf("Digite o PIB (em milhoes): ");
    scanf("%f", &cidade->pib);
    
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &cidade->pontosTuristicos);
    
    // Calcula indicadores
    cidade->densidadePopulacional = cidade->populacao / cidade->area;
    cidade->pibPerCapita = (cidade->pib * 1000000) / cidade->populacao;
}

// Funcao para exibir os dados de uma cidade
void exibirCidade(Cidade cidade) {
    printf("\n=== Dados da Cidade ===\n");
    printf("Estado: %s\n", cidade.estado);
    printf("Codigo: %s\n", cidade.codigo);
    printf("Nome: %s\n", cidade.nome);
    printf("Populacao: %d habitantes\n", cidade.populacao);
    printf("Area: %.2f km2\n", cidade.area);
    printf("PIB: %.2f milhoes\n", cidade.pib);
    printf("Pontos Turisticos: %d\n", cidade.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km2\n", cidade.densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", cidade.pibPerCapita);
}

// Funcao que compara as cidades pelo atributo escolhido
void compararCidades(Cidade cidade1, Cidade cidade2, int atributo) {
    printf("\nComparacao de cartas\n");
    
    // Define qual atributo sera comparado
    switch(atributo) {
        case OPCAO_POPULACAO:
            printf("\nAtributo: Populacao\n");
            printf("Carta 1 - %s (%s): %d habitantes\n", 
                   cidade1.nome, cidade1.estado, cidade1.populacao);
            printf("Carta 2 - %s (%s): %d habitantes\n", 
                   cidade2.nome, cidade2.estado, cidade2.populacao);
            
            printf("\nResultado: ");
            if (cidade1.populacao > cidade2.populacao) {
                printf("Carta 1 (%s) venceu!\n", cidade1.nome);
            } else if (cidade2.populacao > cidade1.populacao) {
                printf("Carta 2 (%s) venceu!\n", cidade2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
            
        case OPCAO_AREA:
            printf("\nAtributo: Area\n");
            printf("Carta 1 - %s (%s): %.2f km2\n", 
                   cidade1.nome, cidade1.estado, cidade1.area);
            printf("Carta 2 - %s (%s): %.2f km2\n", 
                   cidade2.nome, cidade2.estado, cidade2.area);
            
            printf("\nResultado: ");
            if (cidade1.area > cidade2.area) {
                printf("Carta 1 (%s) venceu!\n", cidade1.nome);
            } else if (cidade2.area > cidade1.area) {
                printf("Carta 2 (%s) venceu!\n", cidade2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
            
        case OPCAO_PIB:
            printf("\nAtributo: PIB\n");
            printf("Carta 1 - %s (%s): %.2f milhoes\n", 
                   cidade1.nome, cidade1.estado, cidade1.pib);
            printf("Carta 2 - %s (%s): %.2f milhoes\n", 
                   cidade2.nome, cidade2.estado, cidade2.pib);
            
            printf("\nResultado: ");
            if (cidade1.pib > cidade2.pib) {
                printf("Carta 1 (%s) venceu!\n", cidade1.nome);
            } else if (cidade2.pib > cidade1.pib) {
                printf("Carta 2 (%s) venceu!\n", cidade2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
            
        case OPCAO_PONTOS_TURISTICOS:
            printf("\nAtributo: Pontos Turisticos\n");
            printf("Carta 1 - %s (%s): %d pontos\n", 
                   cidade1.nome, cidade1.estado, cidade1.pontosTuristicos);
            printf("Carta 2 - %s (%s): %d pontos\n", 
                   cidade2.nome, cidade2.estado, cidade2.pontosTuristicos);
            
            printf("\nResultado: ");
            if (cidade1.pontosTuristicos > cidade2.pontosTuristicos) {
                printf("Carta 1 (%s) venceu!\n", cidade1.nome);
            } else if (cidade2.pontosTuristicos > cidade1.pontosTuristicos) {
                printf("Carta 2 (%s) venceu!\n", cidade2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
            
        case OPCAO_DENSIDADE:
            printf("\nAtributo: Densidade Populacional\n");
            printf("Carta 1 - %s (%s): %.2f hab/km2\n", 
                   cidade1.nome, cidade1.estado, cidade1.densidadePopulacional);
            printf("Carta 2 - %s (%s): %.2f hab/km2\n", 
                   cidade2.nome, cidade2.estado, cidade2.densidadePopulacional);
            
            printf("\nResultado: ");
            // Para densidade, menor valor vence
            if (cidade1.densidadePopulacional < cidade2.densidadePopulacional) {
                printf("Carta 1 (%s) venceu!\n", cidade1.nome);
            } else if (cidade2.densidadePopulacional < cidade1.densidadePopulacional) {
                printf("Carta 2 (%s) venceu!\n", cidade2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    Cidade cidade1, cidade2;
    int opcao;
    
    printf("=== Super Trunfo - Cidades ===\n");
    
    printf("\nCadastre a primeira cidade:");
    cadastrarCidade(&cidade1);
    
    printf("\nCadastre a segunda cidade:");
    cadastrarCidade(&cidade2);
    
    printf("\n=== Cidades Cadastradas ===");
    printf("\nCidade 1:");
    exibirCidade(cidade1);
    printf("\nCidade 2:");
    exibirCidade(cidade2);
    
    // Loop do menu de comparacao
    do {
        opcao = exibirMenu();
        
        if (opcao >= OPCAO_POPULACAO && opcao <= OPCAO_DENSIDADE) {
            compararCidades(cidade1, cidade2, opcao);
        } else if (opcao != OPCAO_SAIR) {
            printf("\nOpcao invalida! Tente novamente.\n");
        }
        
    } while (opcao != OPCAO_SAIR);
    
    printf("\nObrigado por jogar!\n");
    
    return 0;
}
