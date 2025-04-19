/*******************************************************************************
 * Super Trunfo - Comparador de Cidades
 * 
 * Descricao:
 * Este programa implementa um jogo de Super Trunfo com cartas de cidades brasileiras.
 * Permite cadastrar duas cidades e compara-las com base em seus atributos.
 * 
 * Funcionalidades:
 * - Cadastro de cidades com diversos atributos
 * - Calculo automatico de indicadores (densidade populacional e PIB per capita)
 * - Comparacao entre cidades baseada em atributos especificos
 * 
 * Autor: [Seu Nome]
 * Data: [Data atual]
 ******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <locale.h>

/* Definicao de constantes */
#define TAM_STRING 100  // Tamanho maximo para strings

/**
 * Estrutura que representa uma carta/cidade no jogo
 * Armazena tanto dados basicos quanto indicadores calculados
 */
typedef struct {
    char estado[TAM_STRING];          // Sigla do estado
    char codigo[TAM_STRING];          // Codigo identificador da carta
    char nome[TAM_STRING];            // Nome da cidade
    int populacao;                    // Numero de habitantes
    float area;                       // Area em km2
    float pib;                        // PIB em milhoes
    int pontosTuristicos;            // Quantidade de pontos turisticos
    float densidadePopulacional;     // Calculado: habitantes por km2
    float pibPerCapita;              // Calculado: PIB por habitante
} Cidade;

/**
 * Funcao responsavel pelo cadastro de uma cidade
 * 
 * @param cidade Ponteiro para a estrutura Cidade a ser preenchida
 * 
 * Fluxo:
 * 1. Solicita dados basicos do usuario
 * 2. Armazena os dados na estrutura
 * 3. Calcula indicadores derivados (densidade e PIB per capita)
 */
void cadastrarCidade(Cidade *cidade) {
    printf("\n=== Cadastro de Cidade ===\n");
    
    // Entrada de dados basicos
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
    
    // Calculo dos indicadores derivados
    cidade->densidadePopulacional = cidade->populacao / cidade->area;
    cidade->pibPerCapita = (cidade->pib * 1000000) / cidade->populacao;  // Convertendo PIB para valor absoluto
}

/**
 * Funcao que exibe todos os dados de uma cidade
 * 
 * @param cidade Estrutura Cidade a ser exibida
 * 
 * Exibe:
 * - Dados basicos inseridos pelo usuario
 * - Indicadores calculados automaticamente
 */
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

/**
 * Funcao que compara duas cidades com base no atributo populacao
 * 
 * @param cidade1 Primeira cidade a ser comparada
 * @param cidade2 Segunda cidade a ser comparada
 * 
 * Regra:
 * - A cidade com maior populacao vence
 * - Em caso de valores iguais, resulta em empate
 */
void compararCidades(Cidade cidade1, Cidade cidade2) {
    printf("\nComparacao de cartas (Atributo: Populacao):\n\n");
    
    // Exibe os valores do atributo comparado para ambas as cidades
    printf("Carta 1 - %s (%s): %d habitantes\n", 
           cidade1.nome, cidade1.estado, cidade1.populacao);
    printf("Carta 2 - %s (%s): %d habitantes\n", 
           cidade2.nome, cidade2.estado, cidade2.populacao);
    
    // Determina e exibe o resultado da comparacao
    printf("\nResultado: ");
    if (cidade1.populacao > cidade2.populacao) {
        printf("Carta 1 (%s) venceu!\n", cidade1.nome);
    } else if (cidade2.populacao > cidade1.populacao) {
        printf("Carta 2 (%s) venceu!\n", cidade2.nome);
    } else {
        printf("Empate!\n");
    }
}

/**
 * Funcao principal do programa
 * 
 * Fluxo de execucao:
 * 1. Configura o ambiente para caracteres em portugues
 * 2. Cadastra duas cidades
 * 3. Exibe os dados completos de ambas as cidades
 * 4. Realiza e exibe a comparacao entre elas
 */
int main() {
    // Configuracao para caracteres em portugues
    setlocale(LC_ALL, "Portuguese");
    
    // Declaracao das variaveis principais
    Cidade cidade1, cidade2;
    
    // Cabecalho do programa
    printf("=== Super Trunfo - Cidades ===\n");
    
    // Cadastro das cidades
    printf("\nCadastre a primeira cidade:");
    cadastrarCidade(&cidade1);
    
    printf("\nCadastre a segunda cidade:");
    cadastrarCidade(&cidade2);
    
    // Exibicao dos dados cadastrados
    printf("\n=== Cidades Cadastradas ===");
    printf("\nCidade 1:");
    exibirCidade(cidade1);
    printf("\nCidade 2:");
    exibirCidade(cidade2);
    
    // Comparacao das cidades
    compararCidades(cidade1, cidade2);
    
    return 0;
}
