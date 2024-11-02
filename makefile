# Compiler settings
CXX = g++
CXXFLAGS = -g -std=c++14

# Source files
SOURCES = main.cpp \
	Plant.cpp \
	PlantState.cpp \
	PlantsManager.cpp \
	WastePlant.cpp \
	WastePlantObserver.cpp \
	WastePlantState.cpp \
	WastePlantOperationalState.cpp \
	WastePlantShutdownState.cpp \
	WastePlantMaintenanceState.cpp \
	PowerPlant.cpp \
	PowerPlantObserver.cpp \
	PowerPlantState.cpp \
	PowerPlantOperationalState.cpp \
	PowerPlantShutdownState.cpp \
	PowerPlantOverloadState.cpp \
	SewagePlant.cpp \
	SewagePlantObserver.cpp \
	SewagePlantState.cpp \
	SewagePlantOperationalState.cpp \
	SewagePlantShutdownState.cpp \
	SewagePlantMaintenanceState.cpp \
	CityManager.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Target executable
TARGET = main

# Build rules
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Pattern rule for object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJECTS) $(TARGET)

# Run rule
run: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: clean run
