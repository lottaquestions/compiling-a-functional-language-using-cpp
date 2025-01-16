# compiling-a-functional-language-using-cpp
Following along the code examples in the blog series of the title "Compiling a Functional Language Using C++" by Daniel Fedorin

## Code organization
There is a directory for each complete post from the original blog. To compile the code in each directory, run the command:

```
./compile.sh
```

## Testing

### Posts 3 and 4
For posts 3 and 4, compile and then run the generated binary and then type out sample statements:

```
./scanner_parser.bin 
defn main = { add 320 6 }
defn add x y = { x + y }
ctrl + D
```

Type ctrl + D to view the generated AST.
