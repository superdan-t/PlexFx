CXX = g++
CFLAGS = -O2 -Wall -g
LDFLAGS = 
OBJS = \
	Tester.o \
	controller.o \
	set.o \
	target_set.o
tester:	$(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o tester

controller.o: controller.cpp controller.hpp effect.hpp PlatformDefs.hpp
	$(CXX) $(CFLAGS) -c $<

set.o: set.cpp set.hpp PlatformDefs.hpp
	$(CXX) $(CFLAGS) -c $<

target_set.o: target_set.cpp target_set.hpp
	$(CXX) $(CFLAGS) -c $<

Tester.o: examples/Tester.cpp effect.hpp
	$(CXX) $(CFLAGS) -c $<

all: tester
