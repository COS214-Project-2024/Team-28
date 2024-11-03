# Watch Rome get built in a day :)

## Overview
The City Builder Simulation is a program that models a dynamic urban environment, where various types of buildings, plants, and services interact under different design patterns to simulate city management. This project utilizes several object-oriented design patterns, each responsible for a specific aspect of the simulation, ensuring modularity and scalability.

### To get started, clone the repository:
```sh
gh repo clone COS214-Project-2024/Team-28
```

### Building and Running the Project
- Build the project:
  ```sh
  make
  ```
- Run the simulation:
  ```sh
  make run
  ```
- Clean up compiled files
  ```sh
  make clean
  ```
# Design Patterns
  1. Abstract Factory
     
    AbstractFactory:  `BuildingFactory`
    ConcreteFactories: `ResidentialFactory`, `CommercialFactory`, etc.
    AbstractProducts: `ResidentialBuilding`, `CommercialBuilding`, etc.
    ConcreteProducts: `Houses`, `Warehouses`, `Plants`, etc.

  3. State
     
     *Each plant has states representing different operational levels.*
     States: `PowerPlantState`, `WaterPlantState`, etc.
     Context: `PowerPlant`, `WaterPlant`, etc.
     ConcreteStates: `Overload`, `Operational`, etc.

 5. Mediator
    
    *Centralizes communication between plants and city departments.*
    Mediator: `CityManager`
    ConcreteMediator: `PlantsManager`
    Colleague: `BuildingsIterator`
    
  
