SRC=src
BUILD=build
OBJ=obj

#Build Tests
#Master Tests
master_tests_cleaned: master_tests
	rm *.o

master_tests: master_tests_verbose stats_class.o master.o master_tests.o
	g++ stats_class.o master.o master_tests.o -o master_tests

master_tests_verbose:
	@echo "Building Master Tests..."
#Compile
stats_class.o:
	g++ -c src\stats\stats_class.cpp
master_tests.o:
	g++ -c src\tests\master_tests.cpp
master.o:
	g++ -c src\master.cpp