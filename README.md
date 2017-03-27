#ProjetC-
#15/02/2017

### Class Cell : virtual pure class

### Constructors and destructors :
* **Cell()** : create a new cell without metabolites (all concentrations equal to 0) and with a fitness equal to 0.
* **Cell(vector<float> intra_metabolites)** : create a new cell with the concentration of metabolites given as argument by a vector that contain (a_, b_, c_).
* **~Cell()** : Delete the cell and update the cellular counter.

### Getters
* **intra_metabolites()** : Return the concentration of metabolites into the cell in a vector (glucose, acetate, ethanol).
* **WhatAmI** : Return the phenotype of the cell as a character 'a' or 'b'.
* **Pmut()** : Return the probabilty of mutation for the cell. It is the same for all the cells.
* **fitness()** : Return the fitness of one cell.
* **Pdeath()** : Return the probability of death of all the cells.
* **Get_nb()** : Return the number of cells created.

### Methods
* **Cell_division()** : divide by two all the metabolites of the cell to simule a cellular division.
* **metabolism** : Change the level of metabolites into the cell depending on the concentration available its box (given as argument) and the time step (dt). Return a vector containing the new concentration of metabolites available in the box after the reaction of the cell occure. 
* **Update_Fit** : Compute the fitness of the cell from its metabolites concentrations.


### Class Ga : inherite from cell
**Update_Fit** : Compute the fitness of the cell from its metabolite A concentration.
### Class Gb : inherite from cell
**Update_Fit** : Compute the fitness of the cell from its metabolites B concentrations.

### Class Box :

**empty_Box**: Test wether a box (given as coordinate x, y) is empty or not , if there is a cell into the box. Return 0 if no cell and 1 otherwise.
**Cellular_death** : Test wether the cell in the box is expected to die. If yes, this method release the cells metabolites into the box and destroy the cell and return 0 (the box is now empty). If not the method return 1 and do not change the cell.
**update_box** : change the concentration of metabolites into the box for the process of diffusion of the environment.



### Class Environment 
**Best_fit** : Find the neigboor with the best fitness around a box and return its coordinates into a vector.

**Run(float time, float T)** : This function run the cellular proliferation for a time (given as argument). Every T time the middle is refresh. The cycle function is called for every step dt. This function create a csv file containing the Ga and Gb number at each cycle.






#test

###test1 
  P_mut = 0
  T : de 1 en 1
  A : de 0.1 en 0.1

###test2
  P_mut = 0.0005
  T : de 1 en 1
  A : de 0.1 en 0.1

###test3
  P_mut = 0.001
  T : de 1 en 1
  A : de 0.1 en 0.1

###test4
  P_mut = 0.0001
  T : de 1 en 1
  A : de 0.1 en 0.1

###test5
  P_mut = 0.01
  T : de 1 en 1
  A : de 0.1 en 0.1



