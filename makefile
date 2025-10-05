CXX = g++
CXXFLAGS = -Wall -std=c++17
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRC = main.cpp Headers/status.cpp Headers/buttons.cpp Headers/files.cpp
OBJ = $(SRC:.cpp=.o)
OUT = main

$(OUT): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ) $(OUT)
