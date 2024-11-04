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
     
      *Used to create different types of buildings and their subcategories*
       
        AbstractFactory:  `BuildingFactory`
       
        ConcreteFactories: `ResidentialFactory`, `CommercialFactory`, etc.
       
        AbstractProducts: `ResidentialBuilding`, `CommercialBuilding`, etc.
       
        ConcreteProducts: `Houses`, `Warehouses`, `Plants`, etc.
       
       **Random Abstract Factory Snippet**:
       ```c++
         class CommercialBuilding : public Building {
          public:
              virtual ~CommercialBuilding() = default;
              virtual float getBuildCost() const = 0;
              virtual std::string getAddress() const = 0;
              virtual void print() const = 0;
          };
       ```

  3. State
     
     *Each plant has states representing different operational levels.*
     
     States: `PowerPlantState`, `WaterPlantState`, etc.
     
     Context: `PowerPlant`, `WaterPlant`, etc.
     
     ConcreteStates: `Overload`, `Operational`, etc.

     **Random State Snippet**:
     ```c++
       void Plant::attachManager(PlantsManager* manager) {
          if (std::find(managers.begin(), managers.end(), manager) == managers.end()) {
              managers.push_back(manager);
              std::cout << "Manager " << manager->getName() << " attached to plant " << getPlantDetails() << std::endl;
          }
      }
     ```

 5. Mediator
    
    *Centralizes communication between plants and city departments.*
    
    Mediator: `CityManager`
    
    ConcreteMediator: `PlantsManager`
    
    Colleague: `BuildingsIterator`

    **Random Mediator Snippet**:
    ```c++
      void adjustFaultProbability(double factor) {
          faultProbability *= factor;
          if (faultProbability < 0.0) faultProbability = 0.0;
          if (faultProbability > 1.0) faultProbability = 1.0;
      }
    ```

  7. Observer
   
     *Tracks changes in plant states and notifies relevant parties.*
     
      Observers: `PlantsManager`, `Citizens`
     
      Subjects: `Plants`, `CityManager`

     **Random Observer Snippet**:
     ```c++
      virtual ~CityManager() = default;
      virtual void reportStatus() const = 0;
      std::string getName() const { return name; }
     ```

   9. Façade
      
      *Provides a simplified interface to interact with city services.*
        
      Facade: `CityManager`
  
      SubSystems: Various city services (e.g., `SecurityService`, `HealthService`).

      **Random Facade Snippet**:
      ```c++
        void EducationServices::scheduleClass(const std::string& className) {
        classes.push_back(className);
        std::cout << "Scheduling class: " << className << std::endl;
        }
        
        void EducationServices::recruitTeacher(const std::string& teacherName) {
            teachers.push_back(teacherName);
            std::cout << "Recruiting teacher: " << teacherName << std::endl;
        }
      ```

  11. Iterator
      
       *Enables iteration over completed buildings and sends information to the City Manager*
       
       Iterator: `BuildingsIterator`
  
       **Random Iterator Snippet**:
        ```c++
          void CityManager::manageServices() {
            for (auto service : services) {
                service->provideService();
              }
          }
        ```

  11. Command
      
       *Implements government commands such as policy notifications.*
       
       Invoker: `Government`
       
       Commands: `payLevies`, `payTaxes`, etc.
       
       Receiver: `CityManager`

      **Random Command Snippet**:
      ```c++
        void Government::increaseTaxesAndLevies() {
            taxRate += 0.05; // Example increase
            levyRate += 5; // Example increase
            updateEconomicSituation(0, -5, -5); // Negative effect on economic situation
        }
      ```

  13. Chain of Responsibility (Chartreuse)
      
       *Manages plant state changes through a chain of handlers.*
       
       Handler: `PlantsStateHandler`
       
       Request: Change in plant state

      **Random CoF Snippet**:
      ```c++
        public:
            /**
             * @brief Default constructor for the Operational class.
             */
            Operational();
        
            /**
             * @brief Destructor for the Operational class.
             */
            ~Operational();
        };
      ```

  15. Builder
      
       *Modularly constructs city materials, with factories directing the builder class.*
       
       Director: `Factories`
       
       Builder: `MaterialsHub`
       
       Concrete Builders: `SteelBuilder`, `ConcreteBuilder`, `WoodMaker`
       
       Products: `Steel`, `Concrete`, `Wood`
       
       Storage: `Warehouse`

      **Random Builder Snippet**:
      ```c++
        void Warehouses::construct() {
            std::cout << "Constructing new warehouse: " << warehouseName << "...\n";
            std::cout << "Setting up storage areas...\n";
            std::cout << "Installing inventory management systems...\n";
            std::cout << "Setting up loading docks...\n";
            isOperational = true;
            std::cout << "Warehouse construction completed. Status: Operational\n";
        }
      ```

  17. Strategy
      
      *Defines strategies in response to population growth and citizen satisfaction levels.*
      
      Context: `Government`
      
      Strategies: Various policies or plans related to citizen welfare.

      **Random Strategy Snippet**:
      ```c++
        void SocialWelfareStrategy::executeStrategy(Government* government) {
            // Provide free food hampers and money to citizens
            std::vector<Citizen> citizens = government->getCitizens();
            for (auto& citizen : citizens) {
                citizen.receiveFoodHamper();
                citizen.receiveMoney(500.0); // Example amount
        		citizen.updateSatisfaction();
            }
        }
      ```
# Unit Testing
 ## Commercial Unit Testing
   **Test Cases**:
   1. Unit Creation and Initialization Tests
   2. Financial Calculations Tests
   3. Capacity Management Tests
   4. Emergency System Tests
   5. Property Management Tests
   6. Data Validation Tests
   7. Building-Specific Features
```c++
    static void printTestResult(const std::string& testName, bool passed) {
        std::cout << (passed ? "[PASS] " : "[FAIL] ") << testName << std::endl;
    }

    // Mall Tests
    static void testMallShopCreation() {
        MallShop shop("Test Shop", "Retail", 100.0, 1000.0);
        bool passed = shop.isVacant() && 
                     shop.calculateMonthlyRevenue() == -1000.0;
        printTestResult("Mall Shop Creation", passed);
    }
```

## Industrial Unit Testing
  **Test Cases**:
  1. Basic factory tests (creation and construction)
  2. Worker management tests
  3. Production cycle tests
  4. Maintenance tracking and repair tests
  5. Job allocation tests
```c++
    static void printTestResult(const std::string& testName, bool passed) {
        std::cout << (passed ? "[PASS] " : "[FAIL] ") << testName << std::endl;
    }

    // Basic Factory Tests
    static void testFactoryCreation() {
        MaterialHub* hub = new SteelBuilder();  // Changed from MaterialHub to SteelBuilder
        Factories factory(hub, "Test Factory");
        bool passed = !factory.isFactoryOperational() && 
                     factory.getNumberOfWorkers() == 0 &&
                     factory.getMaintenanceCount() == 0;
        printTestResult("Factory Creation", passed);
    }
```
    
  
