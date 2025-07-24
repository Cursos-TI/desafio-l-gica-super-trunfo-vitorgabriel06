#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta de cidade
typedef struct {
    char estado[50];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib; // em bilhões
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para cadastrar os dados da carta
void cadastrarCarta(Carta *carta) {
    printf("\n--- Cadastro da Carta ---\n");

    printf("Estado: ");
    fgets(carta->estado, sizeof(carta->estado), stdin);
    carta->estado[strcspn(carta->estado, "\n")] = '\0';

    printf("Código da carta: ");
    fgets(carta->codigo, sizeof(carta->codigo), stdin);
    carta->codigo[strcspn(carta->codigo, "\n")] = '\0';

    printf("Nome da cidade: ");
    fgets(carta->nome, sizeof(carta->nome), stdin);
    carta->nome[strcspn(carta->nome, "\n")] = '\0';

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área (km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Limpa o buffer
    while (getchar() != '\n');

    // Evita divisão por zero
    if (carta->area > 0)
        carta->densidadePopulacional = carta->populacao / carta->area;
    else
        carta->densidadePopulacional = 0;

    if (carta->populacao > 0)
        carta->pibPerCapita = (carta->pib * 1e9) / carta->populacao; // PIB convertido para reais
    else
        carta->pibPerCapita = 0;
}

// Função para exibir os dados da carta
void exibirCarta(Carta carta) {
    printf("\n--- Dados da Carta ---\n");
    printf("Cidade: %s (%s)\n", carta.nome, carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", carta.pibPerCapita);
}

// Função para comparar cartas por atributo escolhido
void compararCartas(Carta c1, Carta c2) {
    char atributo[30];
    printf("\n--- Comparação de Cartas ---\n");
    printf("Escolha o atributo para comparar (populacao, area, pib, densidade, pibpercapita): ");
    fgets(atributo, sizeof(atributo), stdin);
    atributo[strcspn(atributo, "\n")] = '\0';

    if (strcmp(atributo, "populacao") == 0) {
        printf("Carta 1: %d hab | Carta 2: %d hab\n", c1.populacao, c2.populacao);
        if (c1.populacao > c2.populacao)
            printf("Resultado: %s venceu!\n", c1.nome);
        else if (c2.populacao > c1.populacao)
            printf("Resultado: %s venceu!\n", c2.nome);
        else
            printf("Resultado: Empate!\n");

    } else if (strcmp(atributo, "area") == 0) {
        printf("Carta 1: %.2f km² | Carta 2: %.2f km²\n", c1.area, c2.area);
        if (c1.area > c2.area)
            printf("Resultado: %s venceu!\n", c1.nome);
        else if (c2.area > c1.area)
            printf("Resultado: %s venceu!\n", c2.nome);
        else
            printf("Resultado: Empate!\n");

    } else if (strcmp(atributo, "pib") == 0) {
        printf("Carta 1: %.2f bilhões | Carta 2: %.2f bilhões\n", c1.pib, c2.pib);
        if (c1.pib > c2.pib)
            printf("Resultado: %s venceu!\n", c1.nome);
        else if (c2.pib > c1.pib)
            printf("Resultado: %s venceu!\n", c2.nome);
        else
            printf("Resultado: Empate!\n");

    } else if (strcmp(atributo, "densidade") == 0) {
        printf("Carta 1: %.2f hab/km² | Carta 2: %.2f hab/km²\n", c1.densidadePopulacional, c2.densidadePopulacional);
        if (c1.densidadePopulacional > c2.densidadePopulacional)
            printf("Resultado: %s venceu!\n", c1.nome);
        else if (c2.densidadePopulacional > c1.densidadePopulacional)
            printf("Resultado: %s venceu!\n", c2.nome);
        else
            printf("Resultado: Empate!\n");

    } else if (strcmp(atributo, "pibpercapita") == 0) {
        printf("Carta 1: R$ %.2f | Carta 2: R$ %.2f\n", c1.pibPerCapita, c2.pibPerCapita);
        if (c1.pibPerCapita > c2.pibPerCapita)
            printf("Resultado: %s venceu!\n", c1.nome);
        else if (c2.pibPerCapita > c1.pibPerCapita)
            printf("Resultado: %s venceu!\n", c2.nome);
        else
            printf("Resultado: Empate!\n");

    } else {
        printf("Atributo inválido!\n");
    }
}

int main() {
    Carta carta1, carta2;

    printf("Cadastro da primeira carta:\n");
    cadastrarCarta(&carta1);

    printf("\nCadastro da segunda carta:\n");
    cadastrarCarta(&carta2);

    exibirCarta(carta1);
    exibirCarta(carta2);

    compararCartas(carta1, carta2);

    return 0;
}
