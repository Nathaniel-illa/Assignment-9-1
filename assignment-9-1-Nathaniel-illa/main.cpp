#include "main.hpp"

int main()
{
	struct Node *head;
	int N = 10;

	head = makeNumbers(N);
	printNumbers(head);
	cout << "The length of the list " << getLength(head) << endl;
	head = sortNumbers(head);
	printNumbers(head);
}
