textQuery:main.o cpp.o exercise_12.27.h
	g++ -o textQuery main.o cpp.o -std=c++11

main.o:./exercise_12.27_main.cpp
	g++ -c ./exercise_12.27_main.cpp -o main.o -std=c++11

cpp.o:./exercise_12.27.cpp
	g++ -c ./exercise_12.27.cpp -o cpp.o -std=c++11

clean:
	rm textQuery
	rm *.o
