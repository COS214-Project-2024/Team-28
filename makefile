CXX = g++
CXXFLAGS = -Wall -w -std=c++14

# List of source files
SOURCES = main.cpp Government.cpp CityManager.cpp PayTaxes.cpp PayLevies.cpp \
          EconomicGrowthStrategy.cpp SocialWelfareStrategy.cpp HighPopulationStrategy.cpp Citizen.cpp \
          Services.cpp HealthServices.cpp EducationServices.cpp EntertainmentServices.cpp \
          SecurityServices.cpp TransportationServices.cpp PublicTransit.cpp Trains.cpp Airports.cpp Roads.cpp \
          Worker.cpp Dependent.cpp \
          Factories.cpp Warehouses.cpp LandMarks.cpp CommercialBuildings.cpp ResidentialBuildings.cpp \
          Plant.cpp PlantState.cpp PlantsManager.cpp WastePlant.cpp WastePlantObserver.cpp WastePlantState.cpp \
          WastePlantOperationalState.cpp WastePlantShutdownState.cpp WastePlantMaintenanceState.cpp \
          PowerPlant.cpp PowerPlantObserver.cpp PowerPlantState.cpp PowerPlantOperationalState.cpp \
          PowerPlantShutdownState.cpp PowerPlantOverloadState.cpp PowerHandler.cpp \
          SewagePlant.cpp SewagePlantObserver.cpp SewagePlantState.cpp SewagePlantOperationalState.cpp \
          SewagePlantShutdownState.cpp SewagePlantMaintenanceState.cpp \
          CityManager.cpp WaterPlant.cpp WaterPlantObserver.cpp WaterPlantState.cpp WaterPlantRunningState.cpp \
          PlantStateHandler.cpp

# Corresponding object files
OBJECTS = $(SOURCES:.cpp=.o)

# Final executable
EXEC = program

# Default target
all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean up build artifacts
clean:
	rm -f *.o program

# Run the program
run: $(EXEC)
	./$(EXEC)

#################################################################################################################


# /*# main: *.o
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
# 			Factories.cpp Warehouses.cpp LandMarks.cpp CommercialBuildings.cpp ResidentialBuildings.cpp\


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


########################################################################################################

# # Object files
# OBJS = main.o Plant.o PlantState.o PlantsManager.o WastePlant.o WastePlantObserver.o WastePlantState.o WastePlantOperationalState.o WastePlantShutdownState.o WastePlantMaintenanceState.o PowerPlant.o PowerPlantObserver.o PowerPlantState.o PowerPlantOperationalState.o PowerPlantShutdownState.o PowerPlantOverloadState.o PowerHandler.o SewagePlant.o SewagePlantObserver.o SewagePlantState.o SewagePlantOperationalState.o SewagePlantShutdownState.o SewagePlantMaintenanceState.o CityManager.o WaterPlant.o WaterPlantObserver.o WaterPlantState.o WaterPlantRunningState.o PlantStateHandler.o

# # Target executable
# TARGET = main

# # Default target
# all: $(TARGET)

# # Link the target executable
# $(TARGET): $(OBJS)
# 	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# # Compile source files to object files
# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# # Run the target executable
# run: $(TARGET)
# 	./$(TARGET)

# # Clean up
# clean:
# 	del *.o main.exe program.exe
