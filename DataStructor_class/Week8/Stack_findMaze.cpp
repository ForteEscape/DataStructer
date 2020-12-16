#include<stdio.h>
#include<stack>
using namespace std;

#define VISIT 2
#define BACKTRACK 3

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

stack<Dir> mazeStack;
int mazeSize = 8;

bool findMaze(int x, int y);
void print_maze();

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
	Dir currentPos = { x, y };
	mazeStack.push(currentPos);
	map[y][x] = VISIT;

	while (1) {
		bool foward = false;
		if (currentPos.x == mazeSize - 1 && currentPos.y == mazeSize - 1) {
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nextX = currentPos.x + direction[i].x;
			int nextY = currentPos.y + direction[i].y;

			if (nextX >= 0 && nextX < mazeSize && nextY >= 0 && nextY < mazeSize && !map[nextX][nextY]) {
				map[nextX][nextY] = VISIT;
				currentPos.x = nextX;
				currentPos.y = nextY;
				mazeStack.push(currentPos);
				foward = true;

				printf("X : %d,  Y : %d\n", currentPos.x, currentPos.y);
				break;
			}
		}

		if (!foward) {
			printf("backtracked\n");
			map[currentPos.x][currentPos.y] = BACKTRACK;
			if (mazeStack.empty()) {
				return false;
			}

			currentPos = mazeStack.top();
			mazeStack.pop();
		}

		print_maze();
	}

	return true;
}

void print_maze() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%d ", map[j][i]);
		}
		printf("\n");
	}
	printf("\n\n");
}