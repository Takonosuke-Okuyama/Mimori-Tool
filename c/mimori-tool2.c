#include <stdio.h>
#include "mimori.h"

int main(int argc, char const *argv[])
{

	int num, dnum, digits = 0, size = 0;
	char *str, *data;

	//入力
	printf("何森?: ");
	if (scanf("%d",&num) != 1){
		printf("入力は 0 ~ 1000 の整数\n");
		return 1;
	}else if(num < 0 || 9999 < num){
		printf("入力は 0 ~ 1000の整数\n");
		return 1;
	}


	//メモリ確保
	dnum = num;
	while(dnum!=0){
		dnum = dnum / 10;
		digits++;
	}
	size += (digits * 2 * 3); //+ "三"
	if(num%3 != 0) size += 3; //端数分
	size += (num/3) * 3; // + "森"
	size += 3 * 4; // + "すずこ""
	str = malloc(size);


	//三森すずこ製造
	if (makeMimoriSuzuko(str, num) < 0){
		printf("三森すずこ製造失敗\n");
		free(str);
		return 1;
	}


	printf("%s\n", str);

	free(str);
	return 0;
}

char *makeMimoriSuzuko(char *arg_str, int arg_num){
	char *str = arg_str;
	int num = arg_num;
	int byte;

	byte = makeKansu(str, num);
	if(byte < 0){
		printf("漢数変換に失敗\n");
		return (char *)-1;
	}
	str = str + byte;

	byte =  makeMori(str, num);
	if(byte < 0){
		printf("森製造に失敗\n");
		return (char *)-1;
	}
	str = str + byte;

	num = (num + 9) % 46;
	byte = makeSuzuko(str, num);
	if(byte < 0){
		printf("すずこ製造に失敗\n");
		return (char *)-1;
	}
	str = str + byte;

	return arg_str;
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

	if(arg_num < 0) return -1;

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
