#include "pch.h"
#include <iostream>
using namespace std;

bool startHelper = 0;

struct Ring {
	int field;
	Ring *before, *next;
} *current;


bool add() {
	if (!startHelper) {
		cin >> current->field;
		startHelper = 1;
	}
	else {
		Ring * input = new Ring;
		cin >> input->field;
		input->next = current->next;
		current->next->before = current;
		current->next = input;
		input->before = current;
	}
	return startHelper;
}

Ring left() {
	current = current->before;

	return *current;
}

Ring right() {
	current = current->next;

	return *current;
}

void print() {
	Ring * ptr;
	ptr = current;
	for (int i = 0; i < 10; i++) {
		cout << ptr->field << " <-ELEM № " << i << endl;
		ptr = ptr->next;
		if (!ptr) {
			break;
		}
	}
}

int main() {
	current = new Ring;
	current->before = current;
	current->next = current;
	int o;

	while (true) {
		cout << "1-add\n2=>\n3<=\n4-print\n";
		cin >> o;

		switch (o) {
		case 1: add();
			break;
		case 2: right();
			break;
		case 3: left();
			break;
		case 4: print();
			break;
		}


	}
	return 0;
}