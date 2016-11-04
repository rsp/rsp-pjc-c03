# PJC C03 by Rafał Pocztarski
# https://github.com/rsp/rsp-pjc-c03
# https://gitlab.com/rsp/rsp-pjc-c03

CXXFLAGS = -g -std=c++1z -Wall -Wfatal-errors

ALL = z01 z02 z03 z04 z05

all: $(ALL)

z01: z01.cc Makefile
	$(CXX) $(CXXFLAGS) -o $@ $@.cc

z02: z02.cc Makefile
	$(CXX) $(CXXFLAGS) -o $@ $@.cc

z03: z03.cc Makefile
	$(CXX) $(CXXFLAGS) -o $@ $@.cc

z04: z04.cc Makefile
	$(CXX) $(CXXFLAGS) -o $@ $@.cc

z05: z05.cc Makefile
	$(CXX) $(CXXFLAGS) -o $@ $@.cc

clean:
	$(RM) $(ALL) *.o

test: all
	./test.sh
