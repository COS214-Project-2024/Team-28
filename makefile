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
		PlantStateHandler.cpp gtestMain.cpp

# Corresponding object files
OBJECTS = $(SOURCES:.cpp=.o)

# Final executable
EXEC = test_program

# Default target
all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ -lgtest -lgtest_main -pthread

# Rule to compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean up build artifacts
clean:
	rm -f *.o $(EXEC)

# Run the program
run: $(EXEC)
	./$(EXEC)