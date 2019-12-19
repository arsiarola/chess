# src = $(wildcard *.cpp)
src = $(shell find -type f -name '*.cpp')
obj = $(src:.cpp=.o)

chess.o: $(obj)
	g++ -o $@ $^

.PHONY: clean
clean:
	rm -f $(obj) chess
