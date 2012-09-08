
CPPUTEST_HOME = ../cpputest
CPPUTEST_INCLUDE = -I $(CPPUTEST_HOME)/include
CPPUTEST_LIB = $(CPPUTEST_HOME)/lib/libCppUTest.a

CXXFLAGS += $(CPPUTEST_INCLUDE)
CXXFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorMallocMacros.h


all: dummy
	./dummy

dummy: main.o oneTest.o
	$(CXX) $(CPPUTEST_LIB) $^ -o $@ 

clean:
	@-rm -f *.o
	@-rm -f dummy