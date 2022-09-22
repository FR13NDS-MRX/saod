#pragma once
#include <memory>
#include <utility>
#include <iostream>

using namespace std;

struct Data_double {
	Data_double* next;
	Data_double* prev;
	int data;
};

template <typename T>
struct Data {
	Data<T>* next;
	T data;
};

template <typename T>
class List_base {
protected:
	Data<T>* head = NULL;
	int m_size;
public:
	static int amount;
	virtual void push(T& data) = 0;

	bool empty() {
		return m_size == 0;
	}

	virtual void pop() {
		if (head == NULL) throw head;

		Data<T>* p = head->next;
		delete[](head);
		head = p;
		m_size--;
	}

	T top() {
		if (head == NULL) throw head;
		return head->data;
	};

	int size() {
		return m_size;
	};
};

template<typename T>
int List_base<T>::amount(0);

template <class T>
class Queue :public List_base<T> {
	Data<T>* tail = (Data<T>*) & this->head;
public:
	Queue(int size = 0) {
		this->m_size = std::move(size);
		this->amount++;
	}
	~Queue() {
		if (this->m_size != 0) {
			Data<T>* p = this->head->next;

			while (p != this->tail->next) {
				delete[](this->head);
				this->head = p;
				p = p->next;
				this->m_size--;
			}
		}
	}

	T back() {
		if (this->tail == NULL) throw this->tail;
		return this->tail->data;
	}

	virtual void pop() {
		if (this->head == NULL) throw this->head;

		Data<T>* p = this->head->next;
		delete[](this->head);
		this->head = p;
		this->m_size--;
		if (this->tail->next == NULL)
			this->tail = (Data<T>*) & this->head;
	}

	virtual void push(T& data) {
		Data<T>* p = new Data<T>;

		p->data = move(data);

		this->tail->next = p;
		this->tail = p;
		this->tail->next = NULL;
		this->m_size++;
	}

};

template <class T>
class Stack :public List_base<T> {

public:
	Stack(int size = 0) {
		this->m_size = size;
		this->amount++;
	}
	~Stack() {
		if (this->m_size != 0) {
			Data<T>* p = this->head->next;
			while (p != NULL) {
				delete[](this->head);
				this->head = p;
				p = p->next;
				this->m_size--;
			}
		}
	}

	virtual void push(T& data) {
		Data<T>* p = new Data<T>;
		p->data = move(data);

		p->next = this->head;
		this->head = p;
		this->m_size++;
	}

};

template <typename T>
class List :public Queue<T> {
public:
	List(int size = 0) {
		this->m_size = size;
		this->amount++;
	}

	~List() {
		if (this->m_size != 0) {
			Data<T>* p = this->head->next;
			while (p != NULL) {
				delete[](this->head);
				this->head = p;
				p = p->next;
				this->m_size--;
			}
		}
	}

	void push_top(T& data) {
		Data<T>* p = new Data<T>;
		p->data = std::move(data);
		cout << data;
		p->next = this->head;
		this->head = p;
		this->m_size++;
	}
};
