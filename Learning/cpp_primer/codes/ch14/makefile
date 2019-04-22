test_String:main.o cpp.o exercise_14.07.h
	g++ -o test_String main.o cpp.o -std=c++11

main.o:exercise_14.07.h  exercise_14.07_main.cpp 
	g++ -c ./exercise_14.07_main.cpp -o main.o -std=c++11

cpp.o:exercise_14.07.h exercise_14.07.cpp 
	g++ -c ./exercise_14.07.cpp -o cpp.o -std=c++11

clean:
	rm test_String
	rm *.o
