# src = $(wildcard *.cpp)
src = $(shell find -type f -name '*.cpp')
obj = $(src:.cpp=.o)

chess: $(obj)
	g++ -o $@ $^

.PHONY: clean
clean:
	rm -f $(obj) chess
