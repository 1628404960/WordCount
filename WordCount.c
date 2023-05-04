#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(int argc, char* argv[]) {
	
	if(argc != 3) {
		printf("请输入'-c'或'-w'！");
	} //检查用户是否输入了判断标识
	
	FILE *fp; //定义文件指针
	char ch; //定义字符变量
	int wordCount = 0, charCount = 0, judge = 0; //定义单词数，字符数和用于断定单词起始位置的变量
	
	fp = fopen("input.txt", "r"); //打开文件，将文本文件内容赋给文件指针
	
	if (fp == NULL) {
		printf("查询的文件不存在！");
		return 0;
	} //判断文本文件是否存在
	
	while ((ch = fgetc(fp)) != EOF) {
		charCount ++;
		if (isalpha(ch)) {
			if (!judge) {
				wordCount ++;
				judge = 1;
			}
		}
		else {
			judge = 0;
		}
	} /*
	    1.逐字读取文本文件内容，每读取一个字符就使字符数自增1；
	    2.当判断量judge为字母时断定为一个单词的起始，使单词数加1且在judge下一次变为非字母时单词数不再增加
	 */
	
	fclose(fp); //关闭文件
	
	if(strcmp(argv[1], "-c") == 0){
		printf("单词数: %d\n", wordCount);
	} else {
		printf("字符数：%d\n", charCount);
	} //为判断符所指示的需求输出相应的数目
	
	return 0;
}

