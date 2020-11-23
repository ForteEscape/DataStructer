#include<iostream>
using namespace std;

typedef struct dir {
	int x;
	int y;
}Dir;

Dir direction[8] = { {1, 0}, {1, 1}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1} };
int image[8][8] = {
	{1, 0, 0, 0, 0, 0, 0, 1},
	{0, 1, 1, 0, 0, 1, 0, 0},
	{1, 1, 0, 0, 1, 0, 1, 0},
	{0, 0, 0, 0, 0, 1, 0, 0},
	{0, 1, 0, 1, 0, 1, 0, 0},
	{0, 1, 0, 1, 0, 1, 0, 0},
	{1, 0, 0, 0, 1, 0, 0, 1},
	{0, 1, 1, 0, 0, 1, 1, 1}
};

int cell_count = 0;
void counting_blob(int x, int y);
bool isInside(int x, int y);

int main()
{
	int blob_cnt = 0;
	int size[4] = { 0, };

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (image[i][j] == 1) {
				cell_count = 0;
				counting_blob(j, i);
				size[blob_cnt] = cell_count;
				blob_cnt++;
			}
		}
	}

	cout << blob_cnt << endl;

	for (int i = 0; i < blob_cnt; i++) {
		cout << size[i] << " ";
	}
	cout << endl;
}

void counting_blob(int x, int y) {
	image[y][x] = 2;
	cell_count++;

	for (int i = 0; i < 8; i++) {
		int dx = x + direction[i].x;
		int dy = y + direction[i].y;

		if (isInside(dx, dy) && image[dy][dx] == 1) {
			counting_blob(dx, dy);
		}
	}
}

bool isInside(int x, int y) {
	return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

