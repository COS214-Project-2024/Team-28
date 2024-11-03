# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Target executable
TARGET = main

# Source files
SOURCES = Factorymain.cpp Factories.cpp Warehouses.cpp LandMarks.cpp CommercialBuildings.cpp ResidentialBuildings.cpp # List your .cpp files here

# Header files (no need to compile, but you can add them here for reference)
HEADERS = Building.h BuildingFactory.h CommercialBuildingFactory.h CommercialBuildings.h LandMarkFactory.h LandMarks.h ResidentialBuildingFactory.h ResidentialBuildings.h

# Object files (one object per source file)
OBJECTS = $(SOURCES:.cpp=.o)

# Default rule
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile each source file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove compiled files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Add more header files as needed:
# If you add more header files, they should be included in your .cpp files.
# Example:
# If you create a new file called "NewHeader.h", include it in your 
# source files where necessary, but you don't need to mention it in 
# the Makefile.