FLAGS= -ggdb -std=c++11 -Wall -Wextra

all: Assignment.x listManager.x

Assignment.x: Assignment.o AssignmentMeta.o Student.o Comment.o main.o keyWord.o
	g++ $(FLAGS) Assignment.o AssignmentMeta.o Student.o Comment.o main.o keyWord.o -o Assignment.x

listManager.x: listManager.o keyWord.o 
	g++ $(FLAGS) listManager.o  keyWord.o -o listManager.x

listManager.o: listManager.cpp keyWord.hpp
	g++ $(FLAGS) -c listManager.cpp -o listManager.o

Assignment.o: Assignment.cpp Assignment.hpp AssignmentMeta.hpp Student.hpp keyWord.hpp
	g++ $(FLAGS) -c Assignment.cpp -o Assignment.o

AssignmentMeta.o: AssignmentMeta.cpp AssignmentMeta.hpp
	g++ $(FLAGS) -c AssignmentMeta.cpp -o AssignmentMeta.o

Student.o: Student.cpp Student.hpp keyWord.hpp
	g++ $(FLAGS) -c Student.cpp -o Student.o

Comment.o: Comment.cpp Comment.hpp
	g++ $(FLAGS) -c Comment.cpp -o Comment.o

keyWord.o: keyWord.cpp keyWord.hpp
	g++ $(FLAGS) -c keyWord.cpp -o keyWord.o

main.o: main.cpp Assignment.hpp
	g++ $(FLAGS) -c main.cpp -o main.o

run:
	make
	./Assignment.x

manage:
	make
	./listManager.x

clean:
	rm *.o *.x
