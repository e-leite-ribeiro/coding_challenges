CXX = c++
CPPFLAGS = -O2
CXXFLAGS = -std=gnu++17 -Wall -Wextra -pedantic

SOURCES := $(shell find . -type f -name '*.cpp')
PROGRAMS := $(patsubst ./%.cpp,%,$(SOURCES))

.PHONY: all clean

all: $(PROGRAMS)

%: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(PROGRAMS)
