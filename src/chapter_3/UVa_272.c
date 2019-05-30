#include <stdio.h>
#include <string.h>

/**
 * 双引号替换问题, 题目详情:
 * 在TeX中，左双引号是“``”，右双引号是“''”。 输入一篇包含双引号的文章，你的任务是
 * 把它转换成TeX的格式
 */
void tex_quotes(){
	int c, q = 1;
	while((c = getchar()) != EOF) {
		if(c == '"'){
			printf("%s", q ? "``" : "''");
			q = !q;
		} else printf("%c", c);
	}
}

/**
 * "To be or not to be," quoth the Bard, "that is a question"
 * ``To be or not to be,'' quoth the Bard, ``that is a question''
 */
int main(){
	tex_quotes();
	return 0;
}
