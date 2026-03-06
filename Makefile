CXX = c++
CPPFLAGS = -O2
CXXFLAGS = -std=gnu++17 -Wall -Wextra -pedantic

PROGRAMS := $(patsubst %.cpp,%,$(wildcard *.cpp))

.PHONY: all clean

all: $(PROGRAMS)

%: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(PROGRAMS)
