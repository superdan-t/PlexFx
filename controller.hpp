#pragma once

#include "effect.hpp"

namespace PlexFx {

class Controller {
public:
	virtual void run() = 0;
	virtual Effect& getEffect(ID i) = 0;
	virtual void removeEffect(ID i) = 0;
	virtual Effect& addEffect() = 0;
	virtual ~Controller() { };
	inline Effect& operator[](ID id) {
		return getEffect(id);
	}
};

class LinkedController : public Controller {
public:
	void run() override;
	Effect& getEffect(ID i) override;
	void removeEffect(ID i) override;
	Effect& addEffect() override;
	~LinkedController();
private:
	class Node {
	public:
		Effect effect;
		Node* next = nullptr;
	};
	Node* head = nullptr;
	Node* tail = nullptr;
};

} // end namespace PlexFx
