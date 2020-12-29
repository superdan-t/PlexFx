#pragma once

#include "effect.hpp"

namespace PlexFx {

class Controller {
public:
	virtual void run() = 0;
	virtual Effect& getEffect(PLEXFX_TYPE_FXID i) = 0;
	virtual void removeEffect(PLEXFX_TYPE_FXID i) = 0;
	virtual Effect& addEffect() = 0;
	virtual ~Controller() { };
	inline Effect& operator[](size_t id) {
		return getEffect(id);
	}
};

class LinkedController : public Controller {
public:
	void run() override;	// O(n)
	Effect& getEffect(PLEXFX_TYPE_FXID i) override;	// O(n)
	void removeEffect(PLEXFX_TYPE_FXID i) override;	// O(n)
	Effect& addEffect() override;	// O(1)
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
