#include "controller.hpp"

PlexFx::LinkedController::~LinkedController() {
	// Free memory by repeatedly removing head
	while (head) {
		Node* del = head;
		head = head->next;
		delete del;
	}
}

void PlexFx::LinkedController::run() {
	Node* prev = nullptr;
	Node* curr = head;
	while (curr != nullptr) {
		bool terminate = !curr->effect.update();
		if (terminate) {
			if (prev != nullptr) {
				prev->next = curr->next;
				delete curr;
				curr = prev->next;
			} else {
				head = curr->next;
				delete curr;
				curr = head;
			}
		} else {
			prev = curr;
			curr = curr->next;
		}
	}
}

PlexFx::Effect& PlexFx::LinkedController::getEffect(ID i) {
	Node* e = head;
	while (e) {
		if (e->effect.id != i) {
			e = e->next;
		} else break;
	}
	return e->effect;
}

void PlexFx::LinkedController::removeEffect(ID i) {
	Node* e = head;
	Node* p = nullptr;
	while (e) {
		if (e->effect.id != i) {
			p = e;
			e = e->next;
		} else {
			if (p) {
				p->next = e->next;
			} else {
				head = e->next;
			}
			if (e == tail) {
				tail = p;
			}
			delete e;
			break;
		}
	}
}

PlexFx::Effect& PlexFx::LinkedController::addEffect() {
	Node* newNode = new Node();
	if (head) {
		tail->next = newNode;
		newNode->effect.id = tail->effect.id + 1;
		tail = newNode;
	} else {
		head = newNode;
		tail = newNode;
		newNode->effect.id = 0;
	}
	return newNode->effect;
}
