#pragma once

#include "definitions.hpp"

namespace PlexFx {

// Virtual class for selecting indices for effects
class Set {
public:
	class Iterator {
	public:
		Iterator(Set& set, Index init);
		inline Iterator& operator++() { i += 1; return *this; }
		inline Iterator operator++(int) { Iterator temp = *this; ++*this; return temp; }
		inline bool operator==(Index other) { return i == other; }
		inline bool operator!=(Index other) { return i != other; }
		inline Index operator*() { return i; }
	private:
		Set& set;
		Index i;
	};
	virtual Index at(Index) = 0;
	virtual Index size() = 0;

	inline Iterator begin() { return Iterator(*this, 0); }
	inline Index end() { return size(); }

	inline Index operator[](Index i) {
		return at(i);
	}

	virtual ~Set() { }

};

// Simple range from x to y as a set
class Range : public Set {
public:
	Range(Index start, Index end);
	Index at(Index) override;
	Index size() override;
private:
	Index start;
	Index end;
};

}	//end namespace PlexFx
