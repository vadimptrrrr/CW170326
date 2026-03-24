CXXFLAGS += -Wall -Wextra -std=c++14 -MMD

main: main.o
	clang++ $^ -o $@

-include main.d
