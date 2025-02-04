#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_LENGTH 50

// Função para calcular a distância de Levenshtein
int levenshtein(const char *s1, const char *s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int matrix[len1 + 1][len2 + 1];
    
    for (int i = 0; i <= len1; i++) matrix[i][0] = i;
    for (int j = 0; j <= len2; j++) matrix[0][j] = j;
    
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            matrix[i][j] = fmin(fmin(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1), matrix[i - 1][j - 1] + cost);
        }
    }
    return matrix[len1][len2];
}

// Banco de palavras em diferentes idiomas
const char *portuguese_words[MAX_WORDS] = {"casa", "carro", "computador", "livro", "amizade"};
const char *english_words[MAX_WORDS] = {"house", "car", "computer", "book", "friendship"};
const char *spanish_words[MAX_WORDS] = {"casa", "coche", "ordenador", "libro", "amistad"};

// Função para sugerir correção e detectar idioma
const char* suggest_correction(const char *word, const char **dictionary, int dict_size) {
    int min_distance = MAX_LENGTH;
    const char *best_match = NULL;
    
    for (int i = 0; i < dict_size; i++) {
        int distance = levenshtein(word, dictionary[i]);
        if (distance < min_distance) {
            min_distance = distance;
            best_match = dictionary[i];
        }
    }
    return (min_distance <= 2) ? best_match : word;
}

void check_and_correct(const char *word) {
    printf("Palavra digitada: %s\n", word);
    printf("Sugestões de correção:\n");
    printf("Português: %s\n", suggest_correction(word, portuguese_words, 5));
    printf("Inglês: %s\n", suggest_correction(word, english_words, 5));
    printf("Espanhol: %s\n", suggest_correction(word, spanish_words, 5));
}

int main() {
    char input[MAX_LENGTH];
    printf("Digite uma palavra: ");
    scanf("%s", input);
    check_and_correct(input);
    return 0;
}