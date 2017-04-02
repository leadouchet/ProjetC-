#ifndef GA_H
#define GA_H 

//======================================================================
//                            INCLUDES
//======================================================================
#include "Cell.h"
#include <cstdio>


/**
 * @class Ga
 * @brief Creates a Ga Genotype, Cell
 */

class Ga : public Cell
{
public:
//======================================================================
//                           CONSTRUCTORS
//======================================================================
  Ga();
  Ga(vector<float> intra_metabolites);
  
//======================================================================
//                            DESTRUCTOR
//======================================================================
  virtual ~Ga();

//======================================================================
//                          PUBLIC METHODS
//======================================================================
  char                     WhatAmI() override;
  void                     metabolism(vector<float>* ext_metab) override;
  inline int               Get_nb() const override;
  
  
  
  
protected:
//======================================================================
//                          PROTECTED METHODS
//======================================================================
  void                     Update_Fit() override;

//======================================================================
//                             ATTRIBUTES
//======================================================================
  static const float       Raa_;
  static const float       Rab_;
  static int               nb_Ga;
};




//======================================================================
// INLINE FUNCTION DEFINITION
//======================================================================

inline int Ga::Get_nb() const

/*Return the number of Ga type cells */

  {
    return nb_Ga;
  }
  
inline char Ga::WhatAmI()

/*Return a phenotype */

  {
    return 'a';
  }
#endif // GA_H

