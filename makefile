CXX = g++
CXXFLAGS = -std=c++11

SOURCES = sudoku.cpp transform.cpp
HEADERS = sudoku.h
TARGET = transform
SOLVER = sudoku_solve

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

$(SOLVER): sudoku_solve.cpp
	$(CXX) $(CXXFLAGS) sudoku_solve.cpp -o $(SOLVER)

clean:
	rm -f $(TARGET) $(SOLVER)

run: $(TARGET)
	.\$(TARGET)

solve: $(SOLVER)
	.\$(SOLVER)

help:
	@echo "Usage: make [target]"
	@echo "Targets: $(TARGET)"
	@echo "  run         - Run executable"
	@echo "  $(TARGET)   - Build the executable"
	@echo "  clean       - Remove the executable"
	@echo "  help        - Show this help message"

.PHONY: clean
