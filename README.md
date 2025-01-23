# compiling-a-functional-language-using-cpp
Following along the code examples in the blog series of the title "Compiling a Functional Language Using C++" by Daniel Fedorin

## Code organization
There is a directory for each complete post from the original blog. To compile the code in each directory, run the command:

```
./compile.sh
```

Alternatively, compilation and debugging can be done in vscode. Ensure to update the `launch.json` and `tasks.json` files in
`.vscode` with the appropriate path of the directory you want to compile and debug.

## Testing

### Posts 3 and 4
For posts 3 and 4, compile and then run the generated binary and then type out sample statements:

```
./scanner_parser.bin 
defn add x y = { x + y }
defn double x = { add x x }
defn main = { double 163 }
ctrl + D
```

For an example of an invalid program, try the below:

```
./scanner_parser.bin
defn main = { add 320 6 }
```

Type ctrl + D to view the generated AST.
