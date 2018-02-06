# Makefile for DoubleArrayBag
# 
#
run_exam : BagExam.class DoubleArrayBag.class
	java BagExam

BagExam.class : BagExam.java
	javac BagExam.java

DoubleArrayBag.class : DoubleArrayBag.java
	javac DoubleArrayBag.java

docs	:  DoubleArrayBag.java
	javadoc   -d javadocs \
		  -version \
		  -author \
		  -tag note.:a:"Note" \
	          -tag pre.:a:"Precondition" \
	          -tag post.:a:"Postcondition" \
		  DoubleArrayBag.java
	firefox javadocs/index.html

clean	:
	rm -rf javadocs *.class

