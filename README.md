# SmolComp
# Goal

The goal of this project is to apply the theory from Engineering a Compiler 
Thompson's construction, subset construction, table-driven scanning, to a concrete,
hand-built C++ scanner, implemented as the first stage 
of a compiler front-end I'm building incrementally, stage by stage.

# Table-driven Scanner

| TokenType | Meaning                 | Matches                               |
|-----------|-------------------------|---------------------------------------|
| `Ident`   | identifier              | `x`, `foo`, `count`                   |
| `IntLit`  | integer literal         | `5`, `42`, `1000`                     |
| `Plus`    | addition operator       | `+`                                   |
| `Minus`   | subtraction operator    | `-`                                   |
| `Star`    | multiplication operator | `*`                                   |
| `Slash`   | division operator       | `/`                                   |
| `Assign`  | assignment              | `=`                                   |
| `Eq`      | equality comparison     | `==`                                  |
| `Le`      | less-than-or-equal      | `<=`                                  |
| `Ge`      | greater-than-or-equal   | `>=`                                  |
| `Lt`      | less-than               | `<`                                   |
| `Gt`      | greater-than            | `>`                                   |
| `If`      | keyword                 | `if`                                  |
| `While`   | keyword                 | `while`                               |
| `Return`  | keyword                 | `return`                              |
| `Eof`     | end-of-input marker     | (none, emitted once at end of stream) |