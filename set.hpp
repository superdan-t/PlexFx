#pragma once

#include "PlatformDefs.hpp"

#define PLEXFX_TYPE_SET std::shared_ptr<PlexFx::Set>

namespace PlexFx {

// Virtual class for selecting indices for effects
class Set {
public:
	class Iterator {
	public:
		Iterator(Set& set, PLEXFX_TYPE_BOUND init);
		inline Iterator& operator++() { i += 1; return *this; }
		inline Iterator operator++(int) { Iterator temp = *this; ++*this; return temp; }
		inline bool operator==(PLEXFX_TYPE_BOUND other) { return i == other; }
		inline bool operator!=(PLEXFX_TYPE_BOUND other) { return i != other; }
		inline PLEXFX_TYPE_BOUND operator*() { return i; }
	private:
		Set& set;
		PLEXFX_TYPE_BOUND i;
	};
	virtual PLEXFX_TYPE_BOUND at(PLEXFX_TYPE_BOUND) = 0;
	virtual PLEXFX_TYPE_BOUND size() = 0;

	inline Iterator begin() { return Iterator(*this, 0); }
	inline PLEXFX_TYPE_BOUND end() { return size(); }

	inline PLEXFX_TYPE_BOUND operator[](PLEXFX_TYPE_BOUND i) {
		return at(i);
	}

	virtual ~Set() { }

};

// Simple range from x to y as a set
class Range : public Set {
public:
	Range(PLEXFX_TYPE_BOUND start, PLEXFX_TYPE_BOUND end);
	PLEXFX_TYPE_BOUND at(PLEXFX_TYPE_BOUND) override;
	PLEXFX_TYPE_BOUND size() override;
private:
	PLEXFX_TYPE_BOUND start;
	PLEXFX_TYPE_BOUND end;
};

}	//end namespace PlexFx
