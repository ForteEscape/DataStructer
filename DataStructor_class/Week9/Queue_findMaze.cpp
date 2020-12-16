#include<stdio.h>
#include<queue>
using namespace std;

#define VISIT 2;

typedef struct dir {
	int x;
	int y;
}Dir;

Dir direction[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
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
int mazeSize = 8;

bool findMaze(int x, int y);
void printMaze();

int main()
{
	bool pathFind = findMaze(0, 0);

	if (pathFind) {
		printf("find path\n");
	}
	else {
		printf("there is no path\n");
	}
}

bool findMaze(int x, int y) {
	queue<Dir> mazeQueue;
	Dir current = { x, y };

	mazeQueue.push(current);

	while (!mazeQueue.empty()) {
		int currentX = mazeQueue.front().x;
		int currentY = mazeQueue.front().y;
		mazeQueue.pop();

		map[currentX][currentY] = VISIT;

		if (currentX == mazeSize - 1 && currentY == mazeSize - 1) {
			return true;
		}
		
		for (int i = 0; i < 4; i++) {
			int nextX = currentX + direction[i].x;
			int nextY = currentY + direction[i].y;

			if (nextX >= 0 && nextX < mazeSize && nextY >= 0 && nextY < mazeSize && !map[nextX][nextY]) {
				current.x = nextX;
				current.y = nextY;

				mazeQueue.push(current);
			}
		}

		printMaze();
	}

	return false;
}

void printMaze() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%d ", map[j][i]);
		}
		printf("\n");
	}
	printf("\n\n");
}