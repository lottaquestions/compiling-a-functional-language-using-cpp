bison -o parser.cpp -d parser.y
flex -o scanner.cpp scanner.l
g++ -g -c -o scanner.o scanner.cpp
g++ -g -c -o parser.o parser.cpp
g++ -g -c -o langtypes.o langtypes.cpp
g++ -g -c -o env.o env.cpp
g++ -g -c -o ast.o ast.cpp
g++ -g -c -o definition.o definition.cpp
g++ -g main.cpp parser.o scanner.o langtypes.o env.o ast.o definition.o -o scanner_parser.bin
