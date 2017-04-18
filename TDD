#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Conversor.h"

// Converte um caracter para inteiro.
int CharPraInt(char caracter){
	int numero = 0;

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

// Testa regras de negócio para confirmar validade de uma string.
bool StringValida(char str[30]){
	int cont, cont2 = 0;
	bool validador = true;

	cont = strlen(str);
	while(cont2 < cont){
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

// Converte uma string para inteiro.
int ConverteString(char str[30]){
	int cont, cont2 = 0, num, num2, NumeroConvertido = 0;
	bool valido;

	cont = strlen(str);
	while(cont2 < cont){
		num = CharPraInt(str[cont2]);
		num2 = CharPraInt(str[cont2+1]);
		if(num < num2){
			NumeroConvertido+= num2 - num;
		}
		else{
			NumeroConvertido+= num + num2;
		}
			cont2+= 2;
	}
	valido = StringValida(str);
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
