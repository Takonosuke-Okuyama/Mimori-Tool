#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int num2digits(int num);
int makeKansu(char *arg_str, int arg_num);
int num2Kansu(char *str, int num);
int makeMori(char *arg_str, int arg_num);

const char *suzuko[] = {"こごこ",
	"さざこ", "しじこ", "すずこ", "せぜこ", "そぞこ",
	"ただこ", "ちぢこ", "つづこ", "てでこ", "とどこ",
	"なな゛こ", "にに゛こ", "ぬぬ゛こ", "ねね゛こ", "のの゛こ",
	"はばこ", "ひびこ", "ふぶこ", "へべこ", "ほぼこ",
	"まま゛こ", "みみ゛こ", "むむ゛こ", "めめ゛こ", "もも゛こ",
	"やや゛こ", "ゆゆ゛こ", "よよ゛こ",
	"らら゛こ", "りり゛こ", "るる゛こ", "れれ゛こ", "ろろ゛こ",
	"わわ゛こ", "をを゛こ", "んん゛こ",
	"ああ゛こ", "いい゛こ", "うゔこ", "ええ゛こ", "おお゛こ",
	"かがこ", "きぎこ", "くぐこ", "けげこ"}; //len=46


struct fullchar{
	char a,b,c;
};

const struct fullchar fullcharNumList[] = {
	{-23, -101, -74}, //零
	{-28, -72, -128}, //一
	{-28, -70, -116}, //二
	{-28, -72, -119}, //三
	{-27, -101, -101}, //四
	{-28, -70, -108}, //五
	{-27, -123, -83}, //六
	{-28, -72, -125}, //七
	{-27, -123, -85}, //八
	{-28, -71, -99}, //九
	{-27, -115, -127}, //十
	{-25, -103, -66}, //百
	{-27, -115, -125}, //千
	};

const struct fullchar fullcharMoriList[] = {
	{-26, -100, -88}, //木
	{-26, -98, -105}, //林
	{-26, -93, -82}, //森
	};

int main(int argc, char const *argv[])
{

	int num, size = 0, byte;
	char *str, *data;

	printf("何森?: ");
	if (scanf("%d",&num) != 1){
		printf("入力は 0 ~ 1000 の整数\n");
		return 1;
	}else if(num < 0 || 1000 < num){
		printf("入力は 0 ~ 1000の整数\n");
		return 1;
	}

	size += (num2digits(num) * 2 * 3); //+ "三"
	if(num%3 != 0) size += 3; //端数分
	size += (num/3) * 3; // + "森"
	size += 3 * 4; // + "すずこ""
	str = malloc(size);
	data = str;

	byte = makeKansu(data, num);
	if(byte < 0){
		printf("漢数変換に失敗\n");
		return 1;
	}
	data = data + byte;

	byte =  makeMori(data, num);
	if(byte < 0){
		printf("森製造に失敗\n");
		return 1;
	}
	data = data + byte;

	num = num % 46;
	strcpy(data, suzuko[num]);
	printf("%s\n", str);

	free(str);
	return 0;
}

int num2digits(int num){
	if(num < 0) return -1;
	int digits = 0;
	while(num!=0){
		num = num / 10;
		++digits;
	}
	return digits;
}



int makeKansu(char *arg_str, int arg_num){
	int digits = num2digits(arg_num);
	int byte = 0;
	int num = arg_num;
	int tenten = 1;
	int pre_kansu;
	char *str = arg_str;
	if(digits < 0) return -1;
	else if(digits == 0){
		if (num2Kansu(str, num) < 0) return -1;
		byte += 3;
	}else{
		int i = 1;
		while(i != digits){
			tenten = tenten * 10;
			i++;
		}

		while(1){
			pre_kansu = num / tenten;
			if(tenten == 1){
				if(num2Kansu(str, pre_kansu) < 0) return -1;
				byte += 3;
				str += 3;
			}
			else if(pre_kansu == 1);
			else{
				if(num2Kansu(str, pre_kansu) < 0) return -1;
				byte += 3;
				str += 3;
			}


			if(tenten == 1) break;
			else{
				if(num2Kansu(str, tenten) < 0) return -1;
				byte += 3;
				str += 3;
			}

			num = num % tenten;
			if(num == 0) break;
			else{
				digits = num2digits(num);
				i = 1;
				tenten = 1;
				while(i != digits){
					tenten = tenten * 10;
					i++;
				}
			}
		}
	}

	return byte;
}


int num2Kansu(char *str, int num){
	if(num < 0) return -1;
	switch(num){
		case 100:
			str[0] = fullcharNumList[11].a;
			str[1] = fullcharNumList[11].b;
			str[2] = fullcharNumList[11].c;
			break;
		case 1000:
			str[0] = fullcharNumList[12].a;
			str[1] = fullcharNumList[12].b;
			str[2] = fullcharNumList[12].c;
			break;
		default:
			str[0] = fullcharNumList[num].a;
			str[1] = fullcharNumList[num].b;
			str[2] = fullcharNumList[num].c;
			break;
	}
	return 3;
}


int makeMori(char *arg_str, int arg_num){
	int byte = 0;
	int num = arg_num;
	char * str = arg_str;

	if(num != 0){
		while(1){
			if(num == 4){
				str[0] = fullcharMoriList[1].a;
				str[1] = fullcharMoriList[1].b;
				str[2] = fullcharMoriList[1].c;
				byte += 3;
				str += 3;
				str[0] = fullcharMoriList[1].a;
				str[1] = fullcharMoriList[1].b;
				str[2] = fullcharMoriList[1].c;
				byte += 3;
				break;
			}else if(num == 3){
				str[0] = fullcharMoriList[2].a;
				str[1] = fullcharMoriList[2].b;
				str[2] = fullcharMoriList[2].c;
				byte += 3;
				break;
			}else if(num == 2){
				str[0] = fullcharMoriList[1].a;
				str[1] = fullcharMoriList[1].b;
				str[2] = fullcharMoriList[1].c;
				byte += 3;
				break;
			}else if(num == 1){
				str[0] = fullcharMoriList[0].a;
				str[1] = fullcharMoriList[0].b;
				str[2] = fullcharMoriList[0].c;
				byte += 3;
				break;
			}else{
				str[0] = fullcharMoriList[2].a;
				str[1] = fullcharMoriList[2].b;
				str[2] = fullcharMoriList[2].c;
				byte += 3;
			}

			num -= 3;
			str += 3;
		}
	}

	return byte;
}


// int num2Mori(char *str, int num){
// 	if(num < 0) return -1;
// 	str[0] = fullcharMoriList[num].a;
// 	str[1] = fullcharMoriList[num].b;
// 	str[2] = fullcharMoriList[num].c;

// 	return 3;
// }
