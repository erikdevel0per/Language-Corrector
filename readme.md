# Corretor de Idioma

## Descrição
O usuário digita uma palavra, o programa verifica a semelhança desta palavra com palavras em português, inglês e espanhol utilizando a distância de Levenshtein. Se a palavra estiver incorreta, sugere uma correção no idioma correspondente.

## Linguagem e Tipos de Código
- **Linguagem:** O código foi escrito em **Linguagem C**

Tipos de Código:
Inclusão de bibliotecas:

- `#include <stdio.h>` A biblioteca padrão de entrada e saída, usada para funções como `printf` e `scanf` para exibição e leitura de dados no console.
- `#include <string.h>` A biblioteca que oferece funções para manipulação de strings, como `strlen`.
- `#include <stdlib.h>` Biblioteca padrão de utilitários, usada aqui para funções como `fmin`, que retorna o menor valor entre dois números.

Definições de constantes:
- `#define MAX_WORDS 100`: Define o número máximo de palavras que podem ser armazenadas nos dicionários. Esse valor pode ser alterado, mas serve para limitar o número de palavras em cada idioma.
- `#define MAX_LENGTH 50`: Define o comprimento máximo das palavras. Isso limita o tamanho máximo das palavras que podem ser inseridas ou armazenadas.

## Funções Utilizadas

Função `levenshtein(const char *s1, const char *s2)`:

**Objetivo**: Calcula a distância de Levenshtein entre duas palavras (`s1` e `s2`). A distância de Levenshtein é uma medida de diferença entre duas sequências de caracteres, representando o número mínimo de operações (inserções, exclusões e substituições de caracteres) necessárias para transformar uma sequência na outra.

Parâmetros:

- `const char *s1`: Um ponteiro para a primeira string.
- `const char *s2`: Um ponteiro para a segunda string.

- **Retorno**: Um valor inteiro, representando a distância de Levenshtein entre as duas palavras.

Detalhamento:
- A função usa uma matriz de distância para armazenar os cálculos intermediários entre os diferentes caracteres das palavras.
- Inicializa a primeira linha e a primeira coluna da matriz com valores correspondentes ao número de operações necessárias para converter uma string vazia em outra.
- Em seguida, preenche a matriz com os valores de distância, considerando substituições (se os caracteres das palavras forem diferentes) e as operações de inserção e exclusão.
- A matriz final contém a distância de Levenshtein no canto inferior direito, o que é retornado pela função.

Função `suggest_correction(const char *word, const char **dictionary, int dict_size)`:
- **Objetivo**: Sugere uma correção para a palavra fornecida, comparando-a com as palavras de um dicionário utilizando a distância de Levenshtein. Retorna a palavra que tem a menor distância de Levenshtein em relação à palavra fornecida.

Parâmetros:
- `const char *word`: A palavra digitada pelo usuário.
- `const char **dictionary`: Um ponteiro para o dicionário de palavras a ser comparado.
- `int dict_size`: O tamanho do dicionário (número de palavras).

Retorno: A palavra que é a melhor correspondência com base na distância de Levenshtein.

Detalhamento:
- A função percorre o dicionário e calcula a distância de Levenshtein entre a palavra fornecida e cada palavra do dicionário.
- A função armazena a palavra com a menor distância, se essa distância for menor ou igual a 2 (isto é, até 2 alterações). Caso contrário, retorna a palavra original.

Função `check_and_correct(const char *word)`:
- **Objetivo**: Verifica e sugere correções para a palavra fornecida em três idiomas: português, inglês e espanhol. Chama a função `suggest_correction` para cada idioma.

Função `main()`:
- *Objetivo**: Função principal que executa o programa.

Detalhamento:
- A função pede ao usuário para digitar uma palavra utilizando scanf.
- Chama a função `check_and_correct` para sugerir correções de acordo com os dicionários de palavras em português, inglês e espanhol.

## Estruturas de Dados Utilizadas

Array de Strings:

- Três arrays de palavras são definidos (`portuguese_words`, `english_words` e `spanish_words`), com um número máximo de palavras definido por `MAX_WORDS`. Cada array armazena uma lista de palavras em seu respectivo idioma.
- A função `suggest_correction` compara a palavra digitada com as palavras armazenadas nesses arrays.

Matriz (Matrix) para Levenshtein:

A função `levenshtein` usa uma matriz bidimensional para calcular as distâncias entre as palavras. Esta matriz tem dimensões `(len1+1) x (len2+1)`, onde `len1` e `len2` são os tamanhos das palavras comparadas.

## Tipos de Dados

- Strings `(const char*)`: O programa trabalha com strings em C, que são sequências de caracteres terminadas por um caractere nulo (`'\0'`).
- Inteiros `(int)`: Usados para armazenar valores como índices de arrays, distâncias de Levenshtein, e tamanho das palavras e matrizes.
- Constantes `(#define)`: O código usa definições de constantes para configurar o número máximo de palavras no dicionário e o comprimento máximo das palavras.

## Comportamento do Código

- O programa solicita ao usuário para digitar uma palavra.
- Para essa palavra, o programa tenta sugerir correções para três idiomas diferentes (português, inglês e espanhol), com base na distância de Levenshtein.
- A correção sugerida é a palavra mais próxima (com menor distância) no dicionário, caso a diferença seja pequena (distância <= 2). Caso contrário, a palavra digitada é mantida.

## Considerações Finais

O código é um exemplo simples de como usar a distância de Levenshtein para sugerir correções para palavras digitadas, com foco na comparação de palavras em diferentes idiomas. Isso pode ser útil para a construção de sistemas de correção ortográfica ou de reconhecimento de palavras em diferentes línguas.

## **Muito Obrigado pela sua atenção!**
