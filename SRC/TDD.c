#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Conversor.h"

//Funcao que converte um caracter para inteiro, recebendo como parâmetro o caracter que vai ser convertido
//Retorna um inteiro, se o caracter representar um numero romano valido
//O valor retornado eh o numero arabico que representa o numero romano representado pelo caracter enviado como parametro, caso contrario o valor retornado eh 0.
int CharPraInt(char caracter){
	int numero = 0;
	// Ifs que convertem um caracter, representando um numero romano conhecido, em um inteiro que representa um numero arábico.
	if(caracter == 'X' || caracter == 'x'){
		numero = 10;
	}
	if(caracter == 'V' || caracter == 'v'){
		numero = 5;
	}
	if(caracter == 'I' || caracter == 'i'){
		numero = 1;
	}
	if(caracter == 'L' || caracter == 'l'){
		numero = 50;
	}
	if(caracter == 'C' || caracter == 'c'){
		numero = 100;
	}
	if(caracter == 'D' || caracter == 'd'){
		numero = 500;
	}
	if(caracter == 'M' || caracter == 'm'){
		numero = 1000;
	}
	return numero;
}

//Funcao que verifica se um vetor de caracteres representa um numero romano valido
//recebendo um vetor de caracteres como parametro que representa a palavra que tera a validade testada
//Retorna True para um vetor de caracteres valido e False caso contrario.
bool StringValida(char str[30]){
	int cont, cont2 = 0;
	bool validador = true;

	cont = strlen(str);
	while(cont2 < cont){
		// Ifs que testam as possibilidades de uma string ser valida, atribuindo a uma validador um valor booleano.
		if(CharPraInt(str[cont2]) == 0){
			validador = false;
		}
		if(CharPraInt(str[cont2]) == 5 || CharPraInt(str[cont2]) == 50 || CharPraInt(str[cont2]) == 500){
			if(CharPraInt(str[cont2+1]) >= (CharPraInt(str[cont2]) * 2)){
				validador = false;
			}
			if(CharPraInt(str[cont2+1]) == CharPraInt(str[cont2])){
				validador = false;
			}
		}
		if(CharPraInt(str[cont2]) == 1 || CharPraInt(str[cont2]) == 10 || CharPraInt(str[cont2]) == 100 || CharPraInt(str[cont2]) == 1000){
			if(CharPraInt(str[cont2+1]) > (CharPraInt(str[cont2]) * 10)){
				validador = false;
			}
			if(CharPraInt(str[cont2+1]) == CharPraInt(str[cont2]) && CharPraInt(str[cont2]) == CharPraInt(str[cont2+2]) 
				&& CharPraInt(str[cont2+3]) == CharPraInt(str[cont2])){
				validador = false;
			}
		}
		cont2++;
	}
	return validador;
}

//Funcao que converte um vetor de caracteres que representam numeros romanos em um inteiro
//recebendo um vetor de caracteres como parametro que representa a palavra que sera convertida.
//Retorna -1 para palavras invalidas ou um inteiro que representara o vetor de caracteres convertido em numeros arabicos.
int ConverteString(char str[30]){
	int cont, cont2 = 0, num, num2, NumeroConvertido = 0;
	bool valido;

	cont = strlen(str);
	while(cont2 < cont){
		//As atribuicoes abaixo atribuem a variaveis um inteiro que convertido de um caracter.
		num = CharPraInt(str[cont2]);
		num2 = CharPraInt(str[cont2+1]);
		//As condicoes abaixo definem regras usadas na converção de um numero romano para arabico.
		if(num < num2){
			NumeroConvertido+= num2 - num;
		}
		else{
			NumeroConvertido+= num + num2;
		}
			cont2+= 2;
	}
	//A atribuicao abaixo atribui a uma variavel um booleano que representa se um vetor de caracter eh valido ou nao.
	valido = StringValida(str);
	//As condicoes abaixo servem para saber se o vetor de caracteres e o numero convetido sao validos.
	if(valido){
		if(NumeroConvertido < 1 || NumeroConvertido > 3000){
			return -1;
		}
		else{
			return NumeroConvertido;
		}
	}
	else{
		return -1;
	}
}