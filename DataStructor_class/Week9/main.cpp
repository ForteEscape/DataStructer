#include "myQueue.h"

int main()
{
	queue myQueue = init();

	push(myQueue, 1);
	push(myQueue, 3);
	push(myQueue, 2);
	push(myQueue, 4);
	push(myQueue, 5);

	while (!isEmpty(myQueue)) {
		cout << pop(myQueue) << endl;
	}
}