# main: *.o
# 	g++ -std=c++11 -o main *.o

# # Compile all .cpp files into .o files
# *.o: *.h *.cpp
# 	g++ -g -std=c++11 -c *.cpp

# # Run the main executable
# run:
# 	./main

# # Clean up object files and executable
# clean:
# 	del *.o main.exe

# # Check for memory leaks using Valgrind
# leak:
# 	valgrind --leak-check=full ./main

# # Debug using GDB
# debug:
# 	gdb ./main

##############################################################################################################

# CXX = g++
# CXXFLAGS = -Wall -g

# # List of source files
# SOURCES = main.cpp Government.cpp CityManager.cpp PayTaxes.cpp PayLevies.cpp \
#           EconomicGrowthStrategy.cpp SocialWelfareStrategy.cpp HighPopulationStrategy.cpp Citizen.cpp \
#           Services.cpp HealthServices.cpp EducationServices.cpp EntertainmentServices.cpp \
#           SecurityServices.cpp TransportationServices.cpp PublicTransit.cpp Trains.cpp Airports.cpp Roads.cpp \
# 			Worker.cpp Dependent.cpp \
# 			Factories.cpp Warehouses.cpp LandMarks.cpp CommercialBuildings.cpp ResidentialBuildings.cpp

# # Corresponding object files
# OBJECTS = $(SOURCES:.cpp=.o)

# # Final executable
# EXEC = program

# # Default target
# all: $(EXEC)

# $(EXEC): $(OBJECTS)
# 	$(CXX) $(CXXFLAGS) -o $@ $^

# # Rule to compile source files
# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $<

# # Clean up build artifacts
# clean:
# 	del *.o main.exe program.exe

# # Run the program
# run: $(EXEC)
# 	./$(EXEC)

####################################################################################################

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
