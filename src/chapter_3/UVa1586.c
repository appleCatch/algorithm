#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/**
 * 给出一种物质的分子式（不带括号），求分子量。 本题中的分子式只包含4种原子，分
 * 别为C, H, O, N，原子量分别为12.01, 1.008, 16.00, 14.01（单位：g/mol）。 例如，C6H5OH的
 * 分子量为94.108g/mol
 */

/**
 * 判断出指定位置开始连续的数字,并返回数字的值和位数
 */
int guess(char *ps, int start, int *pd){
	int len = strlen(ps);
//	printf("the length of ps is %d \n", len);
	int digitNum = 0;
	int number[20];//具体的数字位数
	memset(number, 0, sizeof(number));
	for(int i = start; i < len; i++){
		if(isalpha(*(ps+i))) break;
		if(isdigit(*(ps+i))){
			number[digitNum] = *(ps+i)-48;
			digitNum++;
		}
	}
	if(digitNum == 0)return 0;
	else{
		int res = 0;
		for(int i = 0; i < digitNum; i++){
			res += pow(10, digitNum - i - 1)*number[i];
		}
		*pd = digitNum;
		printf("res result is %d, digitNum is %d\n", res, digitNum);
		return res;
	}
}

void molarMass(){
	double cmass = 12.01, hmass = 1.008, omass = 16.00, nmass = 14.01;
	const int maxn = 30;
	char s[maxn];
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%s", s);
		int len = strlen(s);
		double totalMass;
		for(int i = 0; i < len;){
			char n = s[i];
			int digitNum = 0;
			switch(n){
			case 'C':{
				int cNums = guess(s, i+1, &digitNum);
				totalMass += cmass * (cNums==0 ? 1 : cNums);
				i += digitNum + 1;
				break;
			}

			case 'H':{
				int cNums = guess(s, i+1, &digitNum);
				totalMass += hmass * (cNums==0 ? 1 : cNums);
				i += digitNum + 1;
				break;
			}

			case 'O':{
				int cNums = guess(s, i+1, &digitNum);
				totalMass += omass * (cNums==0 ? 1 : cNums);
				i += digitNum + 1;
				break;
			}

			case 'N':{
				int cNums = guess(s, i+1, &digitNum);
				totalMass += nmass * (cNums==0 ? 1 : cNums);
				i += digitNum + 1;
				break;
			}

			}
		}
		printf("%.3fg/mol\n", totalMass);
	}
}


/**
 * test
 *
 * 1
 * C6H5OH
 * res result is 6, digitNum is 1
 * res result is 5, digitNum is 1
 * 94.108g/mol
 *
 *
 * 3
 * C6H5OH
 * res result is 6, digitNum is 1
 * res result is 5, digitNum is 1
 * 94.108g/mol
 * C62H511OH
 * res result is 62, digitNum is 2
 * res result is 511, digitNum is 3
 * 1370.824g/mol
 * C1162H511OH
 * res result is 1162, digitNum is 4
 * res result is 511, digitNum is 3
 * 15858.540g/mol
 */
//int main(){
//	molarMass();
//	return 0;
//}
