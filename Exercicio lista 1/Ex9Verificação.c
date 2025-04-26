#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void desenharForca(int erros) {
    printf("\n");
    printf("  _______\n");
    printf(" |       |\n");
    printf(" |       %c\n", (erros >= 1) ? 'O' : ' ');
    printf(" |      %c%c%c\n", (erros >= 3) ? '/' : ' ', (erros >= 2) ? '|' : ' ', (erros >= 4) ? '\\' : ' ');
    printf(" |      %c %c\n", (erros >= 5) ? '/' : ' ', (erros >= 6) ? '\\' : ' ');
    printf(" |\n");
    printf("_|_\n");
}

// Fun��o para contar quantas letras ainda faltam ser descobertas
int letrasFaltando(char progresso[]) {
    int contador = 0;
    for (int i = 0; progresso[i] != '\0'; i++) {
        if (progresso[i] == '_') {
            contador++;
        }
    }
    return contador;
}

// Fun��o para verificar se a letra j� foi tentada antes
int letraJaTentada(char tentativas[], int totalTentativas, char letra) {
    for (int i = 0; i < totalTentativas; i++) {
        if (tentativas[i] == letra) {
            return 1; // Letra j� foi tentada
        }
    }
    return 0; // Letra ainda n�o foi tentada
}

int main() {
    int erros = 0, totalTentativas = 0;
    char palavra[] = "programa";
    char progresso[strlen(palavra) + 1]; // Para armazenar a palavra oculta
    char tentativas[26]; // Armazena as letras j� tentadas (m�ximo de 26 letras)
    char letra;

    // Inicializa progresso com '_'
    for (int i = 0; palavra[i] != '\0'; i++) {
        progresso[i] = '_';
    }
    progresso[strlen(palavra)] = '\0'; // Finaliza a string corretamente

    while (erros < 6 && letrasFaltando(progresso) > 0) {
        printf("\nPalavra: %s\n", progresso);
        printf("Tentativas erradas: %d/6\n", erros);
        printf("Digite uma letra: ");
        scanf(" %c", &letra);
        letra = tolower(letra); // Converte para min�scula

        // Verifica se a letra j� foi tentada antes
        if (letraJaTentada(tentativas, totalTentativas, letra)) {
            printf("Voc� j� tentou essa letra antes!\n");
            continue; // Pula para a pr�xima itera��o do loop
        }

        // Armazena a letra nas tentativas
        tentativas[totalTentativas] = letra;
        totalTentativas++;

        // Verifica se a letra est� na palavra
        int acertou = 0;
        for (int i = 0; palavra[i] != '\0'; i++) {
            if (tolower(palavra[i]) == letra) {
                progresso[i] = palavra[i]; // Substitui '_' pela letra correta
                acertou = 1;
            }
        }

        // Se n�o acertou, incrementa os erros
        if (!acertou) {
            erros++;
            printf("Letra errada!\n");
        }

        desenharForca(erros);
    }

    // Condi��o final do jogo
    if (letrasFaltando(progresso) == 0) {
        printf("\nParab�ns! Voc� descobriu a palavra: %s\n", palavra);
    } else {
        printf("\nVoc� perdeu! A palavra era: %s\n", palavra);
    }

    return 0;
}
