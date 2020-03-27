src = $(shell find -not -path '*/\.*' -type f -name '*.cpp')
obj = $(src:.cpp=.o)

chess.o: $(obj)
	g++ -g -o $@ $^

.PHONY: clean
clean:
	rm -f $(obj) chess
