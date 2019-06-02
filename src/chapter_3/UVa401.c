#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * 回文词
 * 输入一个字符串，判断它是否为回文串以及镜像串。 输入字符串保证不含数字0。 所谓
 * 回文串，就是反转以后和原串相同，如abba和madam。 所有镜像串，就是左右镜像之后和原
 * 串相同，如2S和3AIAE。 注意，并不是每个字符在镜像之后都能得到一个合法字符。 在本题
 * 中，每个字符的镜像如图3-3所示（空白项表示该字符镜像后不能得到一个合法字符）
 */

//返回transfer字符
char rev_func(char c, const char* rev){
	if(isalpha(c)){
		return *(rev + (c-'A'));
	} else return *(rev + (c - '0' + 25));
}
void palindromes(){
	//在方法内创建局部变量
	//起始于A的字符数组
	const char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
	const char* msg[] = {"not a palindrome", "a regular palindrome",
			"a mirrored string", "a mirrored palindrome"};
	char inputs[30];
	while(scanf("%s", inputs)==1){
		int len = strlen(inputs);
//		printf("input str len is : %d\n", len);
		//m标识镜像, r标识回文
		int m =1, r = 1;
		for(int i = 0; i<(len + 1)/2; i++){
			if(*(inputs+i) != *(inputs + len - i - 1)) r = 0;
			if(rev_func(*(inputs+i), rev) != *(inputs-1+len-i)) m = 0;
		}
		printf("%s -- is %s.\n\n", inputs, msg[m*2+r]);
	}
}

/**
 * 测试
 * 2A3MEAS -- is a mirrored string.

ATOYOTA
ATOYOTA -- is a mirrored palindrome.

NOTAPALINDROME
NOTAPALINDROME -- is not a palindrome.
 */
//int main(){
//	palindromes();
//	return 0;
//}
