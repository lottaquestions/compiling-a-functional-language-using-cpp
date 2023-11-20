bison -o parser.cpp -d parser.y
flex -o scanner.cpp scanner.l
PATH=~/Software/gcc13.2/installation/bin/:$PATH
g++-13.2 -c -o scanner.o scanner.cpp
g++-13.2 -c -o parser.o parser.cpp
g++-13.2 main.cpp parser.o scanner.o -o scanner_parser.bin
