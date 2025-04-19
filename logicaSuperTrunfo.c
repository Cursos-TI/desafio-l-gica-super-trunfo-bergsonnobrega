/*
 * Super Trunfo - Comparador de Cidades
 * 
 * Programa que compara duas cidades brasileiras baseado em seus atributos.
 * Nivel: Mestre - Comparacao com dois atributos e soma de valores.
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
#define TOTAL_ATRIBUTOS 5

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

// Funcao para exibir o menu de opcoes, excluindo atributo ja escolhido
int exibirMenu(int atributoJaEscolhido) {
    int opcao;
    
    printf("\n=== Menu de Comparacao ===\n");
    if (atributoJaEscolhido != OPCAO_POPULACAO)
        printf("1. Populacao\n");
    if (atributoJaEscolhido != OPCAO_AREA)
        printf("2. Area\n");
    if (atributoJaEscolhido != OPCAO_PIB)
        printf("3. PIB\n");
    if (atributoJaEscolhido != OPCAO_PONTOS_TURISTICOS)
        printf("4. Pontos Turisticos\n");
    if (atributoJaEscolhido != OPCAO_DENSIDADE)
        printf("5. Densidade Populacional\n");
    
    printf("\nEscolha o atributo para comparacao: ");
    do {
        scanf("%d", &opcao);
        if (opcao == atributoJaEscolhido || opcao < 1 || opcao > TOTAL_ATRIBUTOS) {
            printf("Opcao invalida! Escolha outro atributo: ");
        }
    } while (opcao == atributoJaEscolhido || opcao < 1 || opcao > TOTAL_ATRIBUTOS);
    
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

// Funcao que retorna o valor normalizado do atributo escolhido
float obterValorAtributo(Cidade cidade, int atributo) {
    switch(atributo) {
        case OPCAO_POPULACAO:
            return (float)cidade.populacao;
        case OPCAO_AREA:
            return cidade.area;
        case OPCAO_PIB:
            return cidade.pib;
        case OPCAO_PONTOS_TURISTICOS:
            return (float)cidade.pontosTuristicos;
        case OPCAO_DENSIDADE:
            return cidade.densidadePopulacional;
        default:
            return 0;
    }
}

// Funcao que retorna o nome do atributo
const char* obterNomeAtributo(int atributo) {
    switch(atributo) {
        case OPCAO_POPULACAO:
            return "Populacao";
        case OPCAO_AREA:
            return "Area";
        case OPCAO_PIB:
            return "PIB";
        case OPCAO_PONTOS_TURISTICOS:
            return "Pontos Turisticos";
        case OPCAO_DENSIDADE:
            return "Densidade Populacional";
        default:
            return "Desconhecido";
    }
}

// Funcao que compara as cidades usando dois atributos
void compararCidades(Cidade cidade1, Cidade cidade2, int atributo1, int atributo2) {
    float valor1_atr1 = obterValorAtributo(cidade1, atributo1);
    float valor2_atr1 = obterValorAtributo(cidade2, atributo1);
    float valor1_atr2 = obterValorAtributo(cidade1, atributo2);
    float valor2_atr2 = obterValorAtributo(cidade2, atributo2);
    
    // Normaliza os valores para densidade populacional (menor é melhor)
    if (atributo1 == OPCAO_DENSIDADE) {
        valor1_atr1 = 1.0f / valor1_atr1;
        valor2_atr1 = 1.0f / valor2_atr1;
    }
    if (atributo2 == OPCAO_DENSIDADE) {
        valor1_atr2 = 1.0f / valor1_atr2;
        valor2_atr2 = 1.0f / valor2_atr2;
    }
    
    // Calcula a soma dos valores normalizados
    float soma1 = valor1_atr1 + valor1_atr2;
    float soma2 = valor2_atr1 + valor2_atr2;
    
    // Exibe os valores de comparacao
    printf("\n=== Comparacao de Atributos ===\n");
    printf("\nCarta 1 - %s (%s):\n", cidade1.nome, cidade1.estado);
    printf("%s: %.2f\n", obterNomeAtributo(atributo1), valor1_atr1);
    printf("%s: %.2f\n", obterNomeAtributo(atributo2), valor1_atr2);
    printf("Soma: %.2f\n", soma1);
    
    printf("\nCarta 2 - %s (%s):\n", cidade2.nome, cidade2.estado);
    printf("%s: %.2f\n", obterNomeAtributo(atributo1), valor2_atr1);
    printf("%s: %.2f\n", obterNomeAtributo(atributo2), valor2_atr2);
    printf("Soma: %.2f\n", soma2);
    
    // Determina o vencedor
    printf("\nResultado: ");
    if (soma1 > soma2) {
        printf("Carta 1 (%s) venceu!\n", cidade1.nome);
    } else if (soma2 > soma1) {
        printf("Carta 2 (%s) venceu!\n", cidade2.nome);
    } else {
        printf("Empate!\n");
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    Cidade cidade1, cidade2;
    int atributo1, atributo2;
    
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
    
    // Escolha dos dois atributos
    printf("\nEscolha o primeiro atributo para comparacao:");
    atributo1 = exibirMenu(0);
    
    printf("\nEscolha o segundo atributo para comparacao:");
    atributo2 = exibirMenu(atributo1);
    
    // Realiza a comparacao com os dois atributos
    compararCidades(cidade1, cidade2, atributo1, atributo2);
    
    return 0;
}
