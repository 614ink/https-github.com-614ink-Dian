#include<stdio.h>
int main(void)
{
	int a[11], b[11], c[11], d[11];
	int x, y, i;
	int t = -1;
	int n = 0, f = 1;
	int ele = 1;
	arrInitial(a, sizeof(a) / sizeof(a[0]));
	arrInitial(b, sizeof(b) / sizeof(b[0]));
	arrInitial(c, sizeof(c) / sizeof(c[0]));
	arrInitial(d, sizeof(d) / sizeof(d[0]));
	//����¥��
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
		}
	} while (x != 0);

	while (peo(a, sizeof(a) / sizeof(a[0]))|| peo_2(b, sizeof(b) / sizeof(b[0]))) {//���ܼ���Ƿ�����û�ϵ��ݣ����b[]�Ƿ�Ϊ0
			if (f <= low(a, sizeof(a) / sizeof(a[0]))) {
				ele = 1;
			}
			if (ele == 1) {
				i = f;
				while ((up(i, a) == 1) || (peo_2(b, sizeof(b) / sizeof(b[0])) == 1)) {
					i = f;
					if(up(i,a)==1) {
						f++;
						t++;
						if (n < 4) {
							if (a[f] == 1) {//δ���ص�������
								a[f] = 0;
								c[f] = 1;
								n++;
								printf("�����ϵ���\n");
								printf("The elevator is on the F%d\n", f);
								printf("having ran for %d units of time\n ", t);
								printf("with %d people on it\n", n);
								printf("\n");
								for (i = 1;i <= 11;i++) {
									if (c[i] == 1) {
										d[i] = b[i];//d[x]Ϊ������x����˵�Ŀ��¥��
									}
								}
							}
							//δ���ص�������
							for (i = 1;i <= 11;i++) {
								if ((c[i] == 1) && (f == b[i])) {
									b[i] = 0;
									c[i] = 2;
									n--;
									printf("�����µ���\n");
									printf("The elevator is on the F%d\n", f);
									printf("having ran for %d units of time\n ", t);
									printf("with %d people on it\n", n);
									printf("\n");
								}
							}
						}
						else {//���ص�������
							for (i = 1;i <= 11;i++) {
								if ((c[i] == 1) && (b[i] == f)) {
									b[i] = 0;
									c[i] = 2;
									n--;
									printf("�����µ���\n");
									printf("The elevator is on the F%d\n", f);
									printf("having ran for %d units of time\n ", t);
									printf("with %d people on it\n", n);
									printf("\n");
								}
							}
						}
					}
					else {
						ele = 0;//תΪ����
					}
				}
				
			}

			if (ele == 0) {
				while (f > low(a, sizeof(a) / sizeof(a[0]))) {
					for (;(n < 4) && (f > low(a, sizeof(a) / sizeof(a[0])));f--) {//��������
						t++;
						if (n < 4) {
							if (a[f] = 1) {
								a[f] = 0;
								c[f] = 1;
								n++;//��������
								printf("�����ϵ���\n");
								printf("The elevator is on the F%d\n", f);
								printf("having ran for %d units of time\n ", t);
								printf("with %d people on it\n", n);
								printf("\n");
								for (i = 1;i <= 11;i++) {
									if (c[i] == 1) {
										d[i] = b[i];
									}
								}

								for (i = 1;i <= 11;i++) {
									if ((c[i] == 1) && (b[i] == f)) {
										b[i] = 0;
										c[i] = 2;
										n--;
										printf("�����µ���\n");
										printf("The elevator is on the F%d\n", f);
										printf("having ran for %d units of time\n ", t);
										printf("with %d people on it\n", n);
										printf("\n");
									}
								}
							}
						}
						else {
							for (i = 1;i <= 11;i++) {
								if ((c[i] == 1) && (b[i] == f)) {
									b[i] = 0;
									c[i] = 2;
									n--;
									printf("�����µ���\n");
									printf("The elevator is on the F%d\n", f);
									printf("having ran for %d units of time\n ", t);
									printf("with %d people on it\n", n);
									printf("\n");
								}
							}
						}
					}
				}
			}
			if (f == low(a, sizeof(a) / sizeof(a[0]))) {
				ele = 1;
			}
	}
	return 0;
}



//���¥���Ƿ�����
int up(int i, int a[]) {
	int up;
	for (;i <= 11;i++) {
		if (a[i] = 1) {
			up = 1;//¥������
		}
		else {
			up = 0;//¥��û��
		}
	}
	return up;
}


//���¥���Ƿ�����
int down(int i, int a[]) {
	int down;
	for (;i >= 1;i--) {
		if (a[i] == 1) {
			down = 1;//¥������
		}
		else {
			down = 0;//¥��û��
		}
	}
}



//������������ߵ�Ŀ��¥��
int maxi(int b[], int leng)
{
	int max = b[0];
	for (int i = 1; i < 11; i++) {
		if (b[i] > max) {
			max = b[i];
		}
	}
	return max;
}

//������������ߵ�������¥��
int high(int a[], int leng)
{
	int highest = 0;
	int h;
	for (h = 1;h <= 10;h++) {
		if (a[h] == 1) {
			highest = h;
		}
	}
	return highest;
}

//�������¥���Ƿ�������
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


//����������������¥��
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

//���b[]���Ƿ���Ϊ0
int peo_2(int b[], int leng)
{
	int anybody = 0;
	int p;
	for (p = 1;p <= 10;p++) {
		if (b[p] != 0) {
			anybody = 1;//b[]�з�0
			break;
		}
	}
	return anybody;
}

//�����ʼ��
int arrInitial(int a[], int leng)//////////
{
	int q;
	for (q = 0;q <= leng;q++) {
		a[q] = 0;
	}
	return 0;
}