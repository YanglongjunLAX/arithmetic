object = main.o RBTree.o
edit:$(object)
	cc -o edit $(object)
main.o:main.cpp RBTree.h
	cc -c main.cpp
XORList.o:RBTree.cpp RBTree.h
	cc -c RBTree.cpp
clean:
	rm edit $(object)
