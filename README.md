# Small Compiler

Applying the theory from Engineering a Compiler, Thompson's construction,
subset construction, table-driven scanning, to a hand-built C++ compiler
front-end, built incrementally. Currently just the scanner, parser is next.

## Scanner

Hand-derived DFAs for ~10 token types (see [Scanner/explanations/RE.md](Scanner/explanations/RE.md)
for the REs, NFAs, and subset construction work), compiled into a table-driven
scanner in C++. Handles maximal-munch tokenization with rollback for cases
where the DFA overshoots a valid token boundary.

Token types:

| TokenType | Meaning                 | Matches                       |
|-----------|-------------------------|-------------------------------|
| `Ident`   | identifier              | `x`, `foo`, `count`           |
| `IntLit`  | integer literal         | `5`, `42`, `1000`             |
| `Plus`    | addition operator       | `+`                           |
| `Minus`   | subtraction operator    | `-`                           |
| `Star`    | multiplication operator | `*`                           |
| `Slash`   | division operator       | `/`                           |
| `Assign`  | assignment              | `=`                           |
| `Eq`      | equality comparison     | `==`                          |
| `Le`      | less-than-or-equal      | `<=`                          |
| `Ge`      | greater-than-or-equal   | `>=`                          |
| `Lt`      | less-than               | `<`                           |
| `Gt`      | greater-than            | `>`                           |
| `If`      | keyword                 | `if`                          |
| `While`   | keyword                 | `while`                       |
| `Return`  | keyword                 | `return`                      |
| `Eof`     | end-of-input marker     | emitted once at end of stream |

## Building

\`\`\`
cmake -B build
cmake --build build
./build/main
\`\`\`

Writes token output to `output/logx.log`.