#include <iostream>
#include <stdio.h>

using namespace std;

char game[20][20];
int h, w, test, ch;

int Lshape[4][3][2] = { //L�� ����� ����� ��
	{ { 0, 0 },{ 0, 1 },{ 1, 1 } }, // case 1 : (i, j), (i, j+1), (i+1, j+1) // �� ���
	{ { 0, 0 },{ 0, 1 },{ 1, 0 } }, // case 2 : (i, j), (i, j+1), (i+1, j)   // �¿���� �� ���
	{ { 0, 0 },{ 1, 0 },{ 1, 1 } }, // case 3 : (i, j), (i+1, j), (i+1, j+1) // �� ���
	{ { 0, 0 },{ 1, 0 },{ 1, -1 } } // case 4 : (i, j), (i+1, j-1), (i+1, j) //  �¿���� �� ���
};

int cover()
{
	int result = 0;
	int x = -1,y = -1;
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++)	{
			if (game[i][j] == 0) { //��ĭ �߰��ϸ� ��ġ�����ϰ� break
				x = j;
				y = i;
				break;
			}
		}
		if (x != -1)
			break;
	}
	if (x == -1)  //baseCase
		return 1;

	for (int type = 0; type < 4; type++) {
		int cx1 = x + Lshape[type][1][0];
		int cy1 = y + Lshape[type][1][1];
		int cx2 = x + Lshape[type][2][0];
		int cy2 = y + Lshape[type][2][1];

		if (cx1 >= 0 && cx1 < h && cy1 >= 0 && cy1 < w && cx2 >= 0 && cx2 < h && cy2 >= 0 && cy2 < w &&
			game[cx1][cy1] != '#' && game[cx2][cy2] != '#')	{
				result += cover();
		}
	}
	return result;
}
int main()
{
	scanf("%d", &test); //�׽�Ʈ���̽� �Է�.
	while (test--) {
		scanf("%d %d", &h, &w); // H X W �Է�
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				scanf(" %c", &game[i][j]);
			}
		}
		printf("%d \n", cover()); // L���� �� ĭ�� ��� ���� ����� �� ���
	}
	return 0;
}

