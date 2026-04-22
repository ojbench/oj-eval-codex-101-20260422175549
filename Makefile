CXX := g++
CXXFLAGS := -O2 -std=gnu++17 -Wall -Wextra -Wno-unused-result
LDFLAGS :=

SRC := main.cpp
BIN := code

all: $(BIN)

$(BIN): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(BIN) *.o

.PHONY: all clean
