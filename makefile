# Compiler and flags
CXX = g++
CXXFLAGS = -g -std=c++14

# List of all source files
SRCS = main.cpp Plant.cpp PlantsManager.cpp WastePlant.cpp \
       WastePlantObserver.cpp PowerPlant.cpp PowerPlantObserver.cpp \
       SewagePlantObserver.cpp WaterPlantObserver.cpp \
       PowerPlantOperationalState.cpp PowerPlantOverloadState.cpp \
       PowerPlantShutdown.cpp WastePlantState.cpp SewagePlantState.cpp \
       WaterPlantState.cpp

# Corresponding object files
OBJS = $(SRCS:.cpp=.o)

# Target executable
TARGET = main

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the executable normally
run: $(TARGET)
	@./$(TARGET)

# Debug the executable using gdb
debug: $(TARGET)
	gdb ./$(TARGET)

# Run the executable with valgrind for memory checking
valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

# Clean build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all run debug valgrind clean
