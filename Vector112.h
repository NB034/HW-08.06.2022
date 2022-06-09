#pragma once
#include <iostream>

using namespace std;

class Vector112 {
	int* arr = nullptr;
	int len = 0;
public:
	Vector112() = default;
	Vector112(int len, int val = 0);
	Vector112(const int* arr, int size);
	
	Vector112(const Vector112& vec);
	Vector112& operator=(const Vector112& vec);
	~Vector112();

	// Добавляет элемент в конец массива;
	void push_back(int val);
	// Удаляет последний элемент массива;
	void pop_back();
	// Добавляет элемент в начало массива;
	void push_front(int val);
	// Удаляет первый элемент массива;
	void pop_front();
	// Выводит массив на экран;
	void print() const;
	// Выводит максимальный элемент;
	void printMaxElem() const;
	// Выводит минимальный элемента;
	void printMinElem() const;
	// Вставляет элемент val в позицию index;
	void insert(int index, int val);
	// Удаляет элемент по указанному индексу;
	void erase(int index);
	// Удаляет все вхождения значения val;
	void remove(int val);
	// Очищает массив;
	void clear();
	// Возвращает размер массива;
	inline int size() const { return this->len; }
	// Проверяет, пустой ли массив;
	inline bool empty() const { return this->arr == nullptr; }
	// Возвращает ссылку на элемент по индексу;
	inline int operator[](int index) const { return this->arr[index]; }
	inline int& operator[](int index) { return this->arr[index]; }

	friend ostream& operator<<(ostream& out, const Vector112& arr);
	friend istream& operator>>(istream& in, Vector112& arr);
};
