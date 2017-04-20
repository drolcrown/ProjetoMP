#ifndef CONVERSOR
#define CONVERSOR

//Funcao que converte um caracter para inteiro, recebendo como parâmetro o caracter que vai ser convertido
//Retorna um inteiro, se o caracter representar um numero romano valido
//O valor retornado eh o numero arabico que representa o numero romano representado pelo caracter enviado como parametro, caso contrario o valor retornado eh 0.
int CharPraInt(char caracter);

//Funcao que verifica se um vetor de caracteres representa um numero romano valido
//recebendo um vetor de caracteres como parametro que representa a palavra que tera a validade testada
//Retorna True para um vetor de caracteres valido e False caso contrario.
bool StringValida(char *str);

//Funcao que converte um vetor de caracteres que representam numeros romanos em um inteiro
//recebendo um vetor de caracteres como parametro que representa a palavra que sera convertida.
//Retorna -1 para palavras invalidas ou um inteiro que representara o vetor de caracteres convertido em numeros arabicos.
int ConverteString(char *str);

#endif
