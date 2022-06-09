#include "Vector112.h"

Vector112::Vector112(int len, int val) {
	if (len != 0) {
		this->len = len;
		this->arr = new int[this->len];
		for (int i = 0; i < this->len; i++)
			this->arr[i] = val;
	}
}
Vector112::Vector112(const int* arr, int size) {
	this->len = size;
	this->arr = new int[this->len];
	for (int i = 0; i < this->len; i++)
		this->arr[i] = arr[i];
}
Vector112::Vector112(const Vector112& vec) : Vector112(vec.arr, vec.len) {}
Vector112& Vector112::operator=(const Vector112& vec) {
	// Защита от самоприсваивания;
	if (this == &vec)
		return *this;
	// Проверка на совпадение длины и конструктор копирования;
	if (this->len != vec.len) {
		this->~Vector112();
		this->len = vec.len;
		this->arr = new int[this->len];
	}
	for (int i = 0; i < this->len; i++)
		this->arr[i] = vec.arr[i];
	return *this;
}
Vector112::~Vector112() {
	if (this->arr != nullptr) {
		delete[]this->arr;
		this->arr = nullptr;
		this->len = 0;
	}
}

void Vector112::push_back(int val) {
	if (this->arr == nullptr) {
		this->arr = new int[++this->len]{ val };
		return;
	}
	int* n_arr = new int[++this->len];
	for (int i = 0; i < this->len - 1; i++) {
		n_arr[i] = this->arr[i];
	}
	n_arr[this->len - 1] = val;
	delete[]this->arr;
	this->arr = n_arr;
}
void Vector112::pop_back() {
	if (this->arr == nullptr)
		return;
	if (this->len == 1) {
		this->~Vector112();
		return;
	}
	int* n_arr = new int[--this->len];
	for (int i = 0; i < this->len; i++) {
		n_arr[i] = this->arr[i];
	}
	delete[]this->arr;
	this->arr = n_arr;
}
void Vector112::push_front(int val) {
	if (this->arr == nullptr) {
		this->arr = new int[++this->len]{ val };
		return;
	}
	int* n_arr = new int[++this->len];
	for (int i = 0; i < this->len - 1; i++) {
		n_arr[i + 1] = this->arr[i];
	}
	n_arr[0] = val;
	delete[]this->arr;
	this->arr = n_arr;
}
void Vector112::pop_front() {
	if (this->arr == nullptr)
		return;
	if (this->len == 1) {
		this->~Vector112();
		return;
	}
	int* n_arr = new int[--this->len];
	for (int i = 0; i < this->len; i++) {
		n_arr[i] = this->arr[i + 1];
	}
	delete[]this->arr;
	this->arr = n_arr;
}
void Vector112::print() const {
	for (int i = 0; i < this->len; i++) {
		if (i != 0)
			cout << ' ';
		cout << this->arr[i];
	}
}
void Vector112::printMaxElem() const {
	int max = this->arr[0];
	for (size_t i = 1; i < this->len; i++)
		if (this->arr[i] > max)
			max = this->arr[i];
	cout << max;
}
void Vector112::printMinElem() const {
	int min = this->arr[0];
	for (size_t i = 1; i < this->len; i++)
		if (this->arr[i] < min)
			min = this->arr[i];
	cout << min;
}
void Vector112::insert(int index, int val) {
	if (index > this->len || index < 0)
		return;
	if (index == this->len) {
		this->push_back(val);
		return;
	}
	if (index == 0) {
		this->push_front(val);
		return;
	}
	int* n_arr = new int[this->len + 1];
	for (int i = 0; i < this->len; i++) {
		if (i < index) {
			n_arr[i] = this->arr[i];
		}
		else {
			n_arr[i + 1] = this->arr[i];
		}
	}
	n_arr[index] = val;
	this->len++;
	delete[]this->arr;
	this->arr = n_arr;
}
void Vector112::erase(int index) {
	if (index > this->len || index < 0)
		return;
	if (index == this->len - 1) {
		this->pop_back();
		return;
	}
	if (index == 0) {
		this->pop_front();
		return;
	}
	int* n_arr = new int[--this->len];
	for (int i = 0; i < this->len; i++) {
		if (i < index) {
			n_arr[i] = this->arr[i];
		}
		else {
			n_arr[i] = this->arr[i + 1];
		}
	}
	delete[]this->arr;
	this->arr = n_arr;
}
void Vector112::remove(int val) {
	if (this->arr == nullptr)
		return;
	if (this->len == 1) {
		if (this->arr[0] = val)
			this->pop_back();
		return;
	}
	int counter = 0;
	for (size_t i = 0; i < this->len; i++)
		if (this->arr[i] == val)
			counter++;
	if (counter == 0)
		return;
	if (counter == this->len) {
		this->~Vector112();
		return;
	}
	int* n_arr = new int[this->len - counter];
	for (size_t i = 0, j = 0; i < this->len; i++)
		if (this->arr[i] != val) {
			n_arr[j] = this->arr[i];
			j++;
		}
	delete[] this->arr;
	this->arr = n_arr;
	this->len -= counter;
}
void Vector112::clear() {
	this->~Vector112();
}

ostream& operator<<(ostream& out, const Vector112& arr) {
	arr.print();
	return out;
}
istream& operator>>(istream& in, Vector112& arr) {
	cout << "Enter the size: ";
	int size;
	in >> size;
	if (size < 0)
		return in;
	if (arr.arr == nullptr && size == 0)
		return in;
	if (size == 0) {
		arr.clear();
		return in;
	}
	if (arr.arr != nullptr)
		delete[] arr.arr;
	arr.arr = new int[size];
	arr.len = size;
	for (size_t i = 0; i < arr.len; i++) {
		cout << "Enter the element number " << i + 1 << ": ";
		in >> arr[i];
	}
	cout << "[Array filled]" << endl;
	return in;
}