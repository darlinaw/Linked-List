p6: main.o List.o LinkNode.o
        g++ -o p6 -std=c++11 main.o List.o LinkNode.o

main.o: main.cpp List.h
        g++ -c -std=c++11 main.cpp

List.o: List.cpp List.h LinkNode.h
        g++ -c -std=c++11 List.cpp

clean:
        rm -f p6 *.o *~

