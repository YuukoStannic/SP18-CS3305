# Makefile for the first C++ bag
#

run_exam : bagexam
	./bagexam

run_test : bagtest
	./bagtest

bagexam	: bag2.o bagexam.o
	g++ -g -o bagexam -std=c++14 bagexam.o bag2.o

bagexam.o  : bagexam.cxx bag2.h
	g++ -g -c -std=c++14 bagexam.cxx

bagtest : bag2.o bagtest.o
	g++ -g -o bagtest -std=c++14 bagtest.o bag2.o

bagtest.o : bagtest.cxx bag2.h
	g++ -g -c -std=c++14 bagtest.cxx

bag2.o : bag2.cxx bag2.h
	g++ -g -c -std=c++14 bag2.cxx

check	: bagexam .valgrindrc
	valgrind ./bagexam

doxydocs	: doxy.config
	doxygen doxy.config
	firefox doxyDocs/html/index.html &

clean :
	rm -rf *.o bagexam bagtest .*sw* doxyDocs


