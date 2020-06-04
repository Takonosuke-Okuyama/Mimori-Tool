#ifndef __MIMORI_H__
#define __MIMORI_H__

#include <stdlib.h>
#include <string.h>

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

char *makeMimoriSuzuko(char *arg_str, int arg_num);
int makeKansu(char *arg_str, int arg_num);
int makeMori(char *arg_str, int arg_num);
int makeSuzuko(char *arg_str, int arg_num);

#endif // __MIMORI_H__
