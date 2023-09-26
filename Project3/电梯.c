#include<stdio.h>
void PRINT_1(int f, int t, int n);
void PRINT_2(int f, int t, int n);

int main(void)
{
	int a[11], b[11], c[11], d[11];
	int x, y, i;
	int t = 0;
	int n = 0, f = 1;
	int ele = 1;
	arrInitial(a, sizeof(a) / sizeof(a[0]));
	arrInitial(b, sizeof(b) / sizeof(b[0]));
	arrInitial(c, sizeof(c) / sizeof(c[0]));
	arrInitial(d, sizeof(d) / sizeof(d[0]));
	//输入楼层
	do {
		printf(" Where does he get on the elevator:");
		scanf("%d", &x);
		if (x <= 0 || x > 10) {
			break;
		}
		else {
			a[x] = 1;
			printf("Where will he get off:");
			scanf("%d", &y);
			b[x] = y;
			printf("Is there somebody else wanting to get on?\n");
			printf("If so,input the floor.If not,input 0\n");
			printf("\n");
		}
	} while (x != 0);

	while (peo(a, sizeof(a) / sizeof(a[0])) || peo_2(b, sizeof(b) / sizeof(b[0]))) {//不能检测是否还有人没上电梯，检测b[]是否为0........能不能删掉peo???
		if (f <= low(a, sizeof(a) / sizeof(a[0]))) {
			ele = 1;
		}
		if (ele == 1) {
			i = f;
			while ((up(i, a) == 1) || (peo_2(b, sizeof(b) / sizeof(b[0])) == 1)) {//楼上是否有人或电梯是否仍在运行
				i = f;
				if (a[1] == 1) {
					a[1] = 0;
					c[1] = 1;
					n++;
					d[1] == b[1];
					PRINT_1(f, t, n);
				}
				if ((up(i, a) == 1) || (upjud(f, i, d, sizeof(d) / sizeof(d[0]) == 1))) {//楼上是否有人或电梯中是否有人要上行
					f++;
					t++;
					if (n < 4) {
						if (a[f] == 1) {//未满载电梯上人
							a[f] = 0;
							c[f] = 1;
							n++;
							PRINT_1(f, t, n);
							for (i = 1;i <= 11;i++) {
								if (c[i] == 1) {
									d[i] = b[i];//d[x]为电梯上x层的人的目标楼层
								}
							}
						}
						//未满载电梯下人
						for (i = 1;i <= 11;i++) {
							if ((c[i] == 1) && (f == b[i])) {
								b[i] = 0;
								c[i] = 2;
								d[i] = 0;
								n--;
								PRINT_2(f, t, n);
							}
						}
					}
					else {//满载电梯下人
						for (i = 1;i <= 11;i++) {
							if ((c[i] == 1) && (b[i] == f)) {
								b[i] = 0;
								c[i] = 2;
								d[i] = 0;
								n--;
								PRINT_2(f, t, n);
							}
						}
					}
				}
				else {
					ele = 0;//转为下行
				}
				break;
			}

		}

		while (ele == 0) {
			i = f;
			while ((down(i, a) == 1) || (peo_2(b, sizeof(b) / sizeof(b[0])) == 1)) {//楼下是否有人或电梯是否仍在运行
				i = f;
				if ((down(i, a) == 1) || (downjud(f, i, d, sizeof(d) / sizeof(d[0]) == 1))) {//楼下是否有人或电梯中是否有人要下行
					f--;
					t++;
					if (n < 4) {
						if (a[f] == 1) {
							a[f] = 0;
							c[f] = 1;
							n++;//未满载电梯上人
							PRINT_1(f, t, n);
							for (i = 1;i <= 11;i++) {
								if (c[i] == 1) {
									d[i] = b[i];
								}
							}
						}
						//未满载电梯下人
						for (i = 1;i <= 11;i++) {
							if ((c[i] == 1) && (b[i] == f)) {
								b[i] = 0;
								c[i] = 2;
								d[i] = 0;
								n--;
								PRINT_2(f, t, n);
							}
						}
					}
					else {//满载电梯下人
						for (i = 1;i <= 11;i++) {
							if ((c[i] == 1) && (b[i] == f)) {
								b[i] = 0;
								c[i] = 2;
								d[i] = 0;
								n--;
								PRINT_2(f, t, n);
							}
						}
					}
				}
				else {
					ele = 1;//转为上行
				}
				break;
			}
		}
	}
	return 0;
}

//检测楼上是否有人
int up(int i, int a[]) {
	int up = 0;
	for (;i <= 11;i++) {
		if (a[i] == 1) {
			up = 1;//楼上有人
			break;
		}
		else {
			up = 0;//楼上没人
		}
	}

	return up;
}

//检测楼下是否有人
int down(int i, int a[]) {
	int down = 0;
	for (;i >= 1;i--) {
		if (a[i] == 1) {
			down = 1;//楼下有人
			break;
		}
		else {
			down = 0;//楼下没人
		}
	}
	return down;
}

//检测所有楼层是否有人上
int peo(int a[], int leng)
{
	int i = 1;
	int peo = 0;
	for (i = 1;i <= leng;i++) {
		if (a[i] == 1) {
			peo = 1;
			break;
		}
	}
	return peo;
}

//检测请求序列中最低楼层
int low(int a[], int leng)
{
	int lowest = 0;
	int l;
	for (l = 1;l <= 10;l++) {
		if (a[l] == 1) {
			lowest = l;
			break;
		}
	}
	return lowest;
}

//检测b[]中是否有为0
int peo_2(int b[], int leng)
{
	int anybody = 0;
	int p;
	for (p = 1;p <= 10;p++) {
		if (b[p] != 0) {
			anybody = 1;//b[]有非0
			break;
		}
	}
	return anybody;
}

//数组初始化
int arrInitial(int a[], int leng)
{
	int q;
	for (q = 0;q <= leng;q++) {
		a[q] = 0;
	}
	return 0;
}

//检测电梯中是否有人要上行
int upjud(int f, int i, int d[], int leng)
{
	int upjud = 0;
	for (i = 1;i <= 11;i++) {
		if (d[i] > f) {
			upjud = 1;
			break;
		}
	}
	return upjud;
}

//检测电梯中是否有人要下行
int downjud(int f, int i, int d[], int leng) {
	int downjud = 0;
	for (i = 1;i <= 11;i++) {
		if ((d[i] < f) && (d[i] != 0)) {
			downjud = 1;
			break;
		}
	}
	return downjud;
}
//打印有人上电梯时楼层、时间、人数
void PRINT_1(int f, int t, int n) {
	printf("有人上电梯\n");
	printf("The elevator is on the F%d\n", f);
	printf("having ran for %d units of time\n ", t);
	printf("with %d people on it\n", n);
	printf("\n");
}
//打印有人下电梯时楼层、时间、人数
void PRINT_2(int f, int t, int n) {
	printf("有人下电梯\n");
	printf("The elevator is on the F%d\n", f);
	printf("having ran for %d units of time\n ", t);
	printf("with %d people on it\n", n);
	printf("\n");
}