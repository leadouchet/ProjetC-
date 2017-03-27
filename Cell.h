#ifndef CELL_H
#define CELL_H 

//======================================================================
//                            INCLUDES
//======================================================================
#include <vector>

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
  Cell(std::vector<float>);
  
//======================================================================
//                           DESTRUCTOR
//======================================================================
  virtual ~Cell();
 
//======================================================================
//                            GETTERS
//======================================================================
  std::vector<float> intra_metabolites(); 
  inline float Pmut() const; 
  inline float fitness() const;
  inline float Pdeath() const;
  inline virtual int Get_nb() const;

//======================================================================
//                         PUBLIC METHODS
//======================================================================
  virtual char WhatAmI() = 0;
  virtual std::vector<float> metabolism(std::vector<float>) = 0;
  void Cell_division();




protected:
//======================================================================
//                       PROTECTED METHODS
//======================================================================
  virtual void Update_Fit() = 0; 
    
//======================================================================
//                           ATTRIBUTES
//======================================================================
  static const float fitness_min_;
  static const float Pdeath_;
  static const float Pmut_;
  static const float dt_ ;
  float fitness_;
  std::vector<float> concentrations_;
  static int nb_cell;
};




//======================================================================
//                         GETTER DEFINITION
//======================================================================
inline float Cell::Pmut() const
  {
    return Pmut_;
  }

inline float Cell::fitness() const
  {
    return fitness_;
  }

inline float Cell::Pdeath() const
  {
    return Pdeath_;
  }

inline int Cell::Get_nb() const
  {
    return nb_cell;
  }




#endif // CELL_H
