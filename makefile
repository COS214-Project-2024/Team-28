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

###############################################################################

# CXX = g++
# CXXFLAGS = -Wall -g

# # List of source files
# SOURCES = main.cpp Government.cpp CityManager.cpp PayTaxes.cpp PayLevies.cpp \
#           EconomicGrowthStrategy.cpp SocialWelfareStrategy.cpp HighPopulationStrategy.cpp Citizen.cpp

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


CXX = g++
CXXFLAGS = -Wall -g

# List of source files
SOURCES = main.cpp Government.cpp CityManager.cpp PayTaxes.cpp PayLevies.cpp \
          EconomicGrowthStrategy.cpp SocialWelfareStrategy.cpp HighPopulationStrategy.cpp Citizen.cpp \
          Services.cpp HealthServices.cpp EducationServices.cpp EntertainmentServices.cpp \
          SecurityServices.cpp TransportationServices.cpp PublicTransit.cpp Trains.cpp Airports.cpp Roads.cpp \
		  Worker.cpp Dependent.cpp

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
	del *.o main.exe program.exe

# Run the program
run: $(EXEC)
	./$(EXEC)