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

	// Äîáàâëÿåò ýëåìåíò â êîíåö ìàññèâà;
	void push_back(int val);
	// Óäàëÿåò ïîñëåäíèé ýëåìåíò ìàññèâà;
	void pop_back();
	// Äîáàâëÿåò ýëåìåíò â íà÷àëî ìàññèâà;
	void push_front(int val);
	// Óäàëÿåò ïåðâûé ýëåìåíò ìàññèâà;
	void pop_front();
	// Âûâîäèò ìàññèâ íà ýêðàí;
	void print() const;
	// Âûâîäèò ìàêñèìàëüíûé ýëåìåíò;
	void printMaxElem() const;
	// Âûâîäèò ìèíèìàëüíûé ýëåìåíòà;
	void printMinElem() const;
	// Âñòàâëÿåò ýëåìåíò val â ïîçèöèþ index;
	void insert(int index, int val);
	// Óäàëÿåò ýëåìåíò ïî óêàçàííîìó èíäåêñó;
	void erase(int index);
	// Óäàëÿåò âñå âõîæäåíèÿ çíà÷åíèÿ val;
	void remove(int val);
	// Î÷èùàåò ìàññèâ;
	void clear();
	
	// Âîçâðàùàåò ðàçìåð ìàññèâà;
	inline int size() const { return this->len; }
	// Ïðîâåðÿåò, ïóñòîé ëè ìàññèâ;
	inline bool empty() const { return this->arr == nullptr; }
	// Âîçâðàùàåò ññûëêó íà ýëåìåíò ïî èíäåêñó;
	inline int& operator[](int index) const { return this->arr[index]; }

	friend ostream& operator<<(ostream& out, const Vector112& arr);
	friend istream& operator>>(istream& in, Vector112& arr);
};
