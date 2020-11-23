#include<iostream>
using namespace std;

typedef struct dir {
	int x;
	int y;
}Dir;

int map[8][8] = {
	{0, 0, 0, 0, 0, 0, 0, 1},
	{0, 1, 1, 0, 1, 1, 0, 1},
	{0, 0, 0, 1, 0, 0, 0, 1},
	{0, 1, 0, 0, 1, 1, 0, 0},
	{0, 1, 1, 1, 0, 0, 1, 1},
	{0, 1, 0, 0, 0, 1, 0, 1},
	{0, 0, 0, 1, 0, 0, 0, 1},
	{0, 1, 1, 1, 0, 1, 0, 0}
};

bool visit[8][8] = { 0, };

Dir direction[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool find_path(int x, int y);
bool isInside(int x, int y);

int main()
{
	map[0][0] = 2;
	find_path(0, 0);

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

bool find_path(int x, int y) {
	map[y][x] = 2;
	if (x == 7 && y == 7) { // if current location is exit
		return true;
	}
	visit[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int dx = x + direction[i].x;
		int dy = y + direction[i].y;

		if (isInside(dx, dy) && map[dy][dx] == 0 && !visit[dy][dx]) {
			if (find_path(dx, dy)) return true; // if this way have a path
		}
	}
	map[y][x] = 3;
	return false;
}

bool isInside(int x, int y) {
	return (x >= 0 && x < 8 && y >= 0 && y < 8);
}