// SAOD_SECTION_1_2_TASK_7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <regex>
#include <windows.h>

using namespace std;

struct QueueNode {
    char data;
    QueueNode* next;
}*First, * Last;

void initQueue() {
	First = new QueueNode;
	First->next = NULL;
	Last = First;
}

bool isEmpty() {
	return First -> next == NULL;
}

void print() {
	if (isEmpty()) {
		cout << "ОЧЕРЕДЬ ПУСТАЯ" << endl;
		return;
	}
	QueueNode* temp = First->next;
	int index = 0;
	while (temp != NULL) {
		cout << index++ << ") " << temp->data << endl;
		temp = temp->next;
	}
}

void push(char data) {
	QueueNode* newNode = new QueueNode;
	newNode->data = data;
	newNode->next = NULL;
	Last->next = newNode;
	Last = newNode;
}

void pop() {
	if (isEmpty()) {
		cout << "ОЧЕРЕДЬ ПУСТАЯ - НЕЧЕГО УДАЛЯТЬ" << endl;
		return;
	}
	QueueNode* temp = First->next;
	First->next = temp->next;
	if (isEmpty())Last = First;
	delete temp;
}

void clear() {
	cout << "ОЧИСТКА ОЧЕРЕДИ" << endl;
	while (!isEmpty()) pop();
	First = NULL;
	Last = NULL;
	delete First;
	delete Last;
}

int main(){
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	initQueue();
	srand(static_cast<unsigned int>(time(0)));
	cout << "Генератор чисел инициализирован" << endl;

	char input;
	do {
		int randNum = rand() % 100 + 1;
		int actionType = randNum % 2;
		int action = rand() % 3 + 1;

		if (actionType == 0){
			cout << "Операция: Добавление " << action << " элементов." << endl;
			for (int i = 0; i < action; i++){
				char newElement = char(rand() % 26 + 65);
				push(newElement);
			}
		}
		else {
			cout << "Операция: Удаление " << action << " элементов." << endl;
			for (int i = 0; i < action; i++) pop();
		}

		print();
		cout << "Для продолжения нажмите любую клавишу, для выхода нажмите 'q'" << endl;
		cin.get(input);
	} while (input != 'q');

	clear();
	
}

