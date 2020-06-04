#include "mimori.h"

const char *hiraganaList[] = {
	"あ", "い", "う", "え", "お",
	"か", "き", "く", "け", "こ",
	"さ", "し", "す", "せ", "そ",
	"た", "ち", "つ", "て", "と",
	"な", "に", "ぬ", "ね", "の",
	"は", "ひ", "ふ", "へ", "ほ",
	"ま", "み", "む", "め", "も",
	"や", "ゆ", "よ",
	"ら", "り", "る", "れ", "ろ",
	"わ", "を", "ん"}; //len=46

const char *kansuList[] = {
	"零", "一", "二", "三", "四",
	"五", "六", "七", "八", "九"}; //len=13

const char dakuten[4] = {-29, -126, -103, '\0'}; //濁点

int main(void){
    return 0;
}

Suzuko makeMimoriSuzuko(int arg_num){
	Suzuko m;
	char *str = m.mimoriSuzuko;
	int num = arg_num;
	int byte;

	if(num < 0) num = 0;
	else if(1000 < num) num = 1000;

	byte = makeKansu(str, num);
	if(byte < 0){
		printf("漢数変換に失敗\n");
		return m;
	}
	str = str + byte;

	byte =  makeMori(str, num);
	if(byte < 0){
		printf("森製造に失敗\n");
		return m;
	}
	str = str + byte;

	num = (num % 46) + 9;
	byte = makeSuzuko(str, num);
	if(byte < 0){
		printf("すずこ製造に失敗\n");
		return m;
	}
	str = str + byte;

	return m;
}



int makeKansu(char *arg_str, int arg_num){
	char *str = arg_str;
	int byte = 0;
	int num = arg_num, one, ten, hundred, thousand;

	if(arg_num < 0) return -1;

	thousand = num / 1000;
	num = num % 1000;
	hundred = num / 100;
	num = num % 100;
	ten = num / 10;
	num = num % 10;
	one = num / 1;

	if(arg_num == 0){
		strcpy(str, kansuList[0]);
		byte += 3;
		str += 3;
	}else{
		if(thousand){
			if(thousand - 1){
				strcpy(str, kansuList[thousand]);
				byte += 3;
				str += 3;
			}
			strcpy(str, "千");
			byte += 3;
			str += 3;
		}
		if(hundred){
			if(hundred - 1){
				strcpy(str, kansuList[hundred]);
				byte += 3;
				str += 3;
			}
			strcpy(str, "百");
			byte += 3;
			str += 3;
		}
		if(ten){
			if(ten - 1){
				strcpy(str, kansuList[ten]);
				byte += 3;
				str += 3;
			}
			strcpy(str, "十");
			byte += 3;
			str += 3;
		}
		if(one){
			strcpy(str, kansuList[one]);
			byte += 3;
			str += 3;
		}
	}

	return byte;
}


int makeMori(char *arg_str, int arg_num){
	int byte = 0;
	int num = arg_num, mori = 0, hayashi = 0, ki = 0;
	char * str = arg_str;
	int i;

	if(arg_num < 0) return -1;

	mori = num / 3;
	num = num % 3;
	if(num == 1 && arg_num != 1){
		mori -= 1;
		hayashi = 2;
	}else if(num == 2){
		hayashi = 1;
	}else if(num == 1){
		ki = 1;
	}

	for (i = 0; i < mori; ++i){
		strcpy(str, "森");
		byte += 3;
		str += 3;
	}
	for (i = 0; i < hayashi; ++i){
		strcpy(str, "林");
		byte += 3;
		str += 3;
	}
	if(ki){
		strcpy(str, "木");
		byte += 3;
		str += 3;
	}

	return byte;
}

int makeSuzuko(char *arg_str, int arg_num){
	char *str = arg_str;
	int byte = 0;

	if(arg_num == 0) return -1;

	strcpy(str,hiraganaList[arg_num]);
	byte += 3;
	str += 3;

	strcpy(str,hiraganaList[arg_num]);
	byte += 3;
	str += 3;

	strcpy(str,dakuten);
	byte += 3;
	str += 3;

	strcpy(str,"こ");
	byte += 3;
	str += 3;

	return byte;
}
