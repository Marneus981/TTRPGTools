SRC=src
BUILD=build
OBJ=obj

#Build Tests
.DEFAULT_GOAL := master_tests_cleaned
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

#Stat Tests
stats_tests_cleaned: stats_tests
	rm *.o
stats_tests: stats_tests_verbose stats_class.o master.o stats_tests.o
	g++ stats_class.o master.o stats_tests.o -o stats_tests

stats_tests_verbose:
	@echo "Building Stats Tests..."
#Compile
stats_class.o:
	g++ -c src\stats\stats_class.cpp
stats_tests.o:
	g++ -c src\tests\stats_tests.cpp
master.o:
	g++ -c src\master.cpp