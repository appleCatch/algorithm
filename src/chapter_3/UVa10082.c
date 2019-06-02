#include <stdio.h>
#include <string.h>

/**
 * 错位输入
 * 输入一个错位后敲出的字符串（所有字母均
 * 大写），输出打字员本来想打出的句子。 输入保
 * 证合法，即一定是错位之后的字符串。 例如输入中不会出现大写字母A
 */
void wertyu(){
	//常量数组
	char charArray[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	int i, c;
	while((c = getchar()) != EOF) {
		for(i = 1; charArray[i] && charArray[i]!= c; i++);
		if (charArray[i]) putchar(charArray[i-1]); else putchar(c);
	}
}

/**
 * 测试
 * O S, GOMR YPFSU/
 * I AM FINE TODAY.
 */
//int main(){
//	wertyu();
//	return 0;
//}
