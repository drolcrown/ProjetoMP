#ifndef TEST

#include <stdio.h>
#include <stdlib.h>
#include "gtest/gtest.h"
#include "Conversor.h"


TEST(TestaValidade, TestPalavraValida){
	char str[30] = {"DDD"};
	printf("\n");
	ASSERT_TRUE(StringValida(str) == false);
	char str2[30] = {"III"};
	ASSERT_TRUE(StringValida(str2) == true);
	char str3[30] = {"LM"};
	ASSERT_TRUE(StringValida(str3) == false);
	char str4[30] = {"MC"};
	ASSERT_TRUE(StringValida(str4) == true);
}

TEST(TestaConversao, TestCaracterValido){
	printf("\n");
	ASSERT_TRUE(CharPraInt('X') == 10);
	ASSERT_FALSE(CharPraInt('V') == 1);
	ASSERT_TRUE(CharPraInt('I') == 1);
	ASSERT_TRUE(CharPraInt('V') == 5);
	ASSERT_FALSE(CharPraInt('M') == 1);
	ASSERT_TRUE(CharPraInt('M') == 1000);
	ASSERT_TRUE(CharPraInt('O') == 0);
}

TEST(TestaNumeroConvertido, TestInteiroPos){
	printf("\n");
	char str[30] = {"XI"};
	ASSERT_TRUE(ConverteString(str) == 11);
	char str2[30] = {"IX"};
	ASSERT_TRUE(ConverteString(str2) == 9);
	char str3[30] = {"XXXX"};
	ASSERT_TRUE(ConverteString(str3) == -1);
	char str4[30] = {"DCCCXLI"};
	ASSERT_TRUE(ConverteString(str4) == 841);
	char str5[30] = {"MMM"};
	ASSERT_TRUE(ConverteString(str5) == 3000);
	char str6[30] = {"MMMI"};
	ASSERT_TRUE(ConverteString(str6) == -1);
	char str7[30] = {"M"};
	ASSERT_FALSE(ConverteString(str7) == 10);
	ASSERT_TRUE(ConverteString(str7) == 1000);
	char str8[30] = {"O"};
	ASSERT_TRUE(ConverteString(str8) == -1);
}

int main(int argc, char **argv) {
  	::testing::InitGoogleTest(&argc, argv);

  	return RUN_ALL_TESTS();
}

#endif
