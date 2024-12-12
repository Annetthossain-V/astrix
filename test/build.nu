alias CC = clang

CC ../src/main.c ../src/source/data.c ../src/source/lexer.c ../src/source/sys.c ../src/source/parser.c ../src/source/vm.c -o astrix -g