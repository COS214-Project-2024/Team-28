# Compiler
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
	PowerHandler.cpp \
	FaultHandler.cpp \
	SewagePlant.cpp \
	SewagePlantObserver.cpp \
	SewagePlantState.cpp \
	SewagePlantOperationalState.cpp \
	SewagePlantShutdownState.cpp \
	SewagePlantMaintenanceState.cpp \
	CityManager.cpp \
	WaterPlant.cpp \
	WaterPlantObserver.cpp \
	WaterPlantState.cpp \
	WaterPlantRunningState.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Executable
EXECUTABLE = main

# Default target
all: $(EXECUTABLE)

# Link the executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the executable
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Clean up build files
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

# Phony targets
.PHONY: all clean run
