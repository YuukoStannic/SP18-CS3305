#Makefile for the C++ implementation of lab 01
# by H. Paul Haiduk
#
stattest :	stattest.o statistician.o
	g++ -o stattest -std=c++14 stattest.o statistician.o

stattest.o :	stattest.cxx statistician.h
	g++ -c -std=c++14 stattest.cxx

statexam :	statexam.o statistician.o
	g++ -o statexam -std=c++14 statexam.o statistician.o

statexam.o :	statexam.cxx statistician.h
	g++ -c -std=c++14 statexam.cxx

statistician.o : statistician.cxx statistician.h
	g++ -c -std=c++14 statistician.cxx

run_test	: stattest
	./stattest

run_exam	: statexam
	./statexam

docs	: doxy.config
	doxygen doxy.config
	firefox doxyDocs/html/index.html &

clean	:
	rm -rf stattest statexam *.o .*.sw* doxyDocs

