bison -o parser.cpp -d parser.y
flex -o scanner.cpp scanner.l
PATH=~/Software/gcc13.2/installation/bin/:$PATH

# Below does not work because stdlib for g++-13.2 cannot be found.
g++-13.2 -g -c -o scanner.o scanner.cpp
g++-13.2 -g -c -o parser.o parser.cpp
g++-13.2 -g -c -o type.o type.cpp
g++-13.2 -g -c -o env.o env.cpp
g++-13.2 -g -c -o ast.o ast.cpp
g++-13.2 -g -c -o definition.o definition.cpp
g++-13.2 -g main.cpp parser.o scanner.o type.o env.o ast.o definition.o -o scanner_parser.bin
