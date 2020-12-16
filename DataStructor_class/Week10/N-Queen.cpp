#include<iostream>
#include<cmath>
using namespace std;

int ans = 0;
int arr_size;
int arr[16] = { 0, }; // 말이 놓이는 곳의 열 번호

void queens(int level);
bool promise(int level);

int main()
{
	cin >> arr_size;

	queens(0);
	cout << ans << endl;
}

void queens(int level) {
	if (level == arr_size) { // pass the promise test and level is equal to board size -> success
		/*for (int i = 1; i <= arr_size; i++) {
			cout << "(" << i << ", " << arr[i] << ")" << endl;
		}*/
		ans++;
	}
	
	for (int i = 1; i <= arr_size; i++) { // i is colum
		arr[level + 1] = i;

		if (promise(level + 1)) {
			queens(level + 1);
		}
	}
}

bool promise(int level) { // promising test
	
	for (int i = 1; i < level; i++) {
		if (arr[i] == arr[level]) { // same colums
			return false;
		}
		else if ((level - i) == abs(arr[level] - arr[i])) { // 대각선 판별 - 대각선일 경우 열 간 차이와 행 간 차이가 같다는 것을 이용한다.
			return false;
		}
	}

	return true;
}

// 이미 promising test를 통과한 말들은 다시 promising test를 거칠 필요가 없다. 즉 새로 들어온 말만 검사하면 된다.