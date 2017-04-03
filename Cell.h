#ifndef CELL_H
#define CELL_H 

//======================================================================
//                            INCLUDES
//======================================================================
#include <vector>

using std::vector;

/**
 * @class Cell
 * @brief Creates a Cell
 */

class Cell
{
public:
//======================================================================
//                          CONSTRUCTORS
//======================================================================
  Cell();
  Cell(vector<float>);
  
//======================================================================
//                           DESTRUCTOR
//======================================================================
  virtual ~Cell();
 
//======================================================================
//                            GETTERS
//======================================================================
  inline vector<float>      intra_metabolites() const; 
  inline float              Pmut() const; 
  inline float              fitness() const;
  inline float              Pdeath() const;
  inline virtual int        Get_nb() const;
  virtual char              WhatAmI() = 0;

//======================================================================
//                         PUBLIC METHODS
//======================================================================
  virtual void              metabolism(vector<float>*) = 0;
  void                      Cell_division();




protected:
//======================================================================
//                       PROTECTED METHODS
//======================================================================
  virtual void              Update_Fit() = 0; 
    
//======================================================================
//                           ATTRIBUTES
//======================================================================
  static const float        fitness_min_;
  static const float        Pdeath_;
  static const float        Pmut_;
  static const float        dt_ ;
  float                     fitness_;
  vector<float>             concentrations_;
  static int                nb_cell;
};




//======================================================================
//                         GETTER DEFINITION
//======================================================================
inline float Cell::Pmut() const

/* Getter to access the cell probabilty of mutation. */
 
  {
    return Pmut_;
  }


inline float Cell::fitness() const

/* Getter to access the cell fitness. */
 
  {
    return fitness_;
  }


inline float Cell::Pdeath() const

/* Getter to access the cell probability of death. */
 
  {
    return Pdeath_;
  }


inline int Cell::Get_nb() const

/* Getter to access the number of existing cells. */
 
  {
    return nb_cell;
  }


inline vector<float> Cell::intra_metabolites() const

/* Getter to access to the cell metabolites concentrations as a vector
 * (glucose, acetate, ethanol) */
 
{  
  return(concentrations_);
}

#endif // CELL_H
