CXXFLAGS += -Wall -Wextra -std=c++14
main: main.cpp
	clang++ $^ -o $@