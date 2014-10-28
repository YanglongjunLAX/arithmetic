object = main.o XORList.o
edit:$(object)
	cc -o edit $(object)
main.o:main.cpp XORList.h
	cc -c main.cpp
XORList.o:XORList.cpp XORList.h
	cc -c XORList.cpp
clean:
	rm edit $(object)
