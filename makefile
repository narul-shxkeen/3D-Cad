CXX = g++
CXXFLAGS = -Wall -std=c++11
SRC_DIR = src
OBJ = $(SRC_DIR)/Polyhedron.o $(SRC_DIR)/Translate.o $(SRC_DIR)/Rotate.o $(SRC_DIR)/Scale.o

all: polyhedron_program

polyhedron_program: main.o $(OBJ)
	$(CXX) $(CXXFLAGS) -o polyhedron_program main.o $(OBJ)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

$(SRC_DIR)/Polyhedron.o: $(SRC_DIR)/Polyhedron.cpp $(SRC_DIR)/Polyhedron.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Polyhedron.cpp -o $(SRC_DIR)/Polyhedron.o

$(SRC_DIR)/Translate.o: $(SRC_DIR)/Translate.cpp $(SRC_DIR)/Translate.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Translate.cpp -o $(SRC_DIR)/Translate.o

$(SRC_DIR)/Rotate.o: $(SRC_DIR)/Rotate.cpp $(SRC_DIR)/Rotate.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Rotate.cpp -o $(SRC_DIR)/Rotate.o

$(SRC_DIR)/Scale.o: $(SRC_DIR)/Scale.cpp $(SRC_DIR)/Scale.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Scale.cpp -o $(SRC_DIR)/Scale.o

# Clean target to remove object files and the compiled binary
clean:
	rm -f polyhedron_program main.o $(OBJ)
