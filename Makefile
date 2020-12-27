CPLUSPLUS = g++ -std=c++11 -Wall -g -Werror

all:
	$(CPLUSPLUS) main.cpp
clean:
	rm a.out
