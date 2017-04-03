## Competition model between two bacteria of phenotype Ga or Gb
INSA Lyon, Departement Biosciences parcours BIM. 3rd year C++ Projet 
15/02/2017. Lea RIERA, Florian PERON, Lea DOUCHET

### Class Cell : virtual pure class

### Constructors and destructors :
* **Cell()** : create a new cell without metabolites (all concentrations
 equal to 0) and with a fitness equal to 0 and update the cellular 
 counter
* **Cell(vector<float> intra_metabolites)** : create a new cell with the
 concentration of metabolites given as argument by a vector that contain
 (glucose, acetate, ethanol) and update the cellular counter
* **~Cell()** : Delete the cell and update the cellular counter.

### Getters
* **intra_metabolites()** : Return the concentration of metabolites into
 the cell in a vector (glucose, acetate, ethanol).
* **WhatAmI()** : Return the phenotype of the cell as a character 'a' or 
'b'.
* **Pmut()** : Return the probabilty of mutation for the cell. It is the
 same for all the cells.
* **fitness()** : Return the fitness of one cell.
* **Pdeath()** : Return the probability of death of all the cells.
* **Get_nb()** : Return the number of cells created and still allocated.

### Methods
* **Cell_division()** : divide by two all the metabolites of the cell to
 simule a cellular division.
* **metabolism()** : Change the level of metabolites into the cell 
 depending on the concentration available its box (given as argument) and
 the time step (dt). Return a vector containing the new concentration of
 metabolites available in the box after the reaction of the cell 
 occure. 
* **Update_Fit()** : Compute the fitness of the cell from its metabolites 
 concentrations. The fitness is depending of the glucose for 'a' 
 phenotype and acetate for 'b'. 


### Class Ga : inherite from cell
#### Constructor and destructor: 
* **Ga()** : Construct a Ga cell using the cell default constructor and update
 the Ga counter
* **Ga(vector<float> intra_metabolites)** : Construct a Ga cell using 
the cell vector constructor and update the Ga counter.
* **~Ga()** : Delete the Ga cell using the cell destructor and update 
the Ga counter
#### Getters : 
* **WhatAmI()** : see cell class
* **Get_nb()** : Return the number of Ga type cells still allocated.
#### Methods :  
* **Update_Fit()** : see cell class
* **metabolism()** : see cell class


### Class Gb : inherite from cell
#### Constructor and destructor: 
* **Gb()** : Construct a Gb cell using the cell default constructor and update
 the Gb counter
* **Gb(vector<float> intra_metabolites)** : Construct a Gb cell using 
the cell vector constructor and update the Gb counter.
* **~Gb()** : Delete the Gb cell using the cell destructor and update 
the Gb counter
#### Getters  :
* **WhatAmI()** : see cell class
* **Get_nb()** : Return the number of Gb type cells still allocated.
#### Methods : 
* **Update_Fit()** : see cell class
* **metabolism()** : see cell class


### Class Box :

* **empty_Box()**: Test wether a box (given as coordinate x, y) is empty or 
 not , if there is a cell into the box. Return 0 if no cell and 1 
 otherwise.  
* **Cellular_death()** : Test wether the cell in the box is expected to die.
 If yes, this method release the cells metabolites into the box and 
 destroy the cell and return 0 (the box is now empty). If not the method
 return 1 and do not change the cell.  
* **update_diffusion()** : change the concentration of metabolites into the box 
after diffusion of the environment.  
* **refresh_box(float A_init)** : Reinitiate the box concentrations given an initial concentration of A.
* **metab_trade()** : The cell exchange metabolites with the box.  
* **newborn(Cell* sister)** : Given a cell, reproduce the same cell into the box.  
* **mutation()** : Decide if the cell should mutate or not and then divid its metabolites.




### Class Environment

#### Constructors and destructor : 
* **Environment()** : Environment default constructor : built an 
toroidal grid_ of W_*H_ size in wich each coordinate represents a box 
that host a cell. No metabolites are added into the environment. There 
are as much Ga phenotype cells as Gb and these are placed randomly into 
the environment.  

* **Environment(float A_init)** : Environment constructor based on the 
level of glucose placed into the environment. The environment is created
 with the default constructor but the initial level of glucose (A_init) 
 contained in each box is chosen by the user.  

* **~Environment()** : Destructor of environment : apply the box 
destructor for each box contained into the grid_.  

* **Best_fit()** : Find the neigboor with the best fitness around a box and 
return its coordinates into a vector.  

* **toroidal(vector<int> coord)** : This function ensure the toroidal behaviour of the environment. For a given coordinate, it return its coordinate into the environment so that it will never leave the space delimited.  

* **diffuse_metabolites()** : Run though the environment to make the metabolites diffuse into each box.  

* **diffuse_box(int x, int y)** : This function makes the metabolites diffuse into one box of the environment considering its neighboors. The new metabolites level of the box is updated.  

* **Cellular_killer()** : Run though the grid and for each box determine if the containig cell will die considering its probability of death.  

* **Cycle()** : Gather all the function describing the environment behaviour during one cycle  : 
  - The metabolites diffuse into the environment
  - Make cell randomly die
  - Make the surviving cells compete to divide into the empty space
  - Each cells metabolizes the metabolites into its box  

* **refresh_Environment()** : Reset every box of the environment at the initial glucose concentration (A_init).  

* **pick_char (vector<char>* tab)** : This function pick randomly and return a caractere contained into a vector given as argument.  

* **pick_coord (vector< vector<int> >*  tab)** : This function pick randomly and return a vector of coordinates contained into a vector given as argument.  

* **Run(float time, float T)** : This function run the cellular 
proliferation for a time (given as argument). Every T time the middle is
 refresh. The cycle function is called for every step dt. This function 
 create a csv file containing the Ga and Gb number at each cycle.  




