#ProjetC-
## 15/02/2017

### Class Cell : virtual pure class
Default constructor : create a new cell without metabolites (concentration equal to 0) and with a fitness equal to 0.
Vector constructor : create a new cell with the concentration of metabolites given as argument by a vector that contain (a_ b_ c_). The fitness is the concentration of b for Ga phenotype and c for Gb phenotype. 
Destructor : Delete the cell
metabolism : Change the level of metabolites into the cell depending on the concentration available its box (given as argument). Return a vector containing the new concentration of metabolites available in the box after the reaction of the cell occure. 
Cell_division : divide by two all the metabolites of the cell and return the quantity of metabolites of the daugther.
WhatAmI : return the phenotype of the cell as a character 'a' or 'b'.

### Class Ga : inherite from cell

### Class Gb : inherite from cell

### Class Box :
empty_Box : Test wether a box is empty or not, if there is a cell into the box. Return 0 if no cell and 1 otherwise.
Cellular_death : Test wether the cell in the box is expected to die. If yes, this method release the cells metabolites into the box and destroy the cell and return 0 (the box is now empty). If not the method return 1 and do not change the cell.




### Class Environment 
array de cases
