#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char titulo[50];
    char autor[50];
} Livro;

#define MAX_LIVROS 50  
Livro biblioteca[MAX_LIVROS]; 
int total_livros = 0;  


void adicionar_livro() {
    if (total_livros >= MAX_LIVROS) {
        printf("A biblioteca está cheia!\n");
        return;
    }

    Livro novo_livro;

    printf("Título: ");
    scanf(" %[^\n]", novo_livro.titulo); 

    printf("Autor: ");
    scanf(" %[^\n]", novo_livro.autor);

    biblioteca[total_livros] = novo_livro;
    total_livros++;

    printf("Livro adicionado com sucesso!\n");
}

void listar_livros() {
    if (total_livros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    printf("\n--- LIVROS CADASTRADOS ---\n");
    for (int i = 0; i < total_livros; i++) {
        printf("\nLivro %d:\n", i + 1);
        printf("Título: %s\n", biblioteca[i].titulo);
        printf("Autor: %s\n", biblioteca[i].autor);
    }
}
void buscar_por_titulo() {
    char titulo_busca[50];
    printf("Digite o título para buscar: ");
    scanf(" %[^\n]", titulo_busca);

    int encontrados = 0;

    for (int i = 0; i < total_livros; i++) {
        if (strstr(biblioteca[i].titulo, titulo_busca) != NULL) {
            printf("\nLivro encontrado:\n");
            printf("Título: %s\n", biblioteca[i].titulo);
            printf("Autor: %s\n", biblioteca[i].autor);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum livro encontrado com esse título.\n");
    }
}
int main() {
    int opcao;

    do {
        printf("\n---LISTA DE LIVROS---\n");
        printf("1. Adicionar livro\n");
        printf("2. Listar livros\n");
        printf("3. Buscar por título\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_livro();
                break;
            case 2:
                listar_livros();
                break;
            case 3:
                buscar_por_titulo();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
