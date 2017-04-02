#ifndef GB_H
#define GB_H 

//======================================================================
//                             INCLUDES
//======================================================================

#include "Cell.h"
#include <cstdio>

/**
 * @class Gb
 * @brief Creates a Gb genotype, Cell
 */

class Gb : public Cell
{
	friend int Get_nb_Gb();
public:
//======================================================================
//                          CONSTRUCTORS
//======================================================================
  Gb();
  Gb(vector<float>);

//======================================================================
//                           DESTRUCTOR
//======================================================================
  virtual ~Gb();

//======================================================================
//                            GETTERS
//======================================================================
  inline int               Get_nb() const override;
  inline char              WhatAmI() override;

//==============================
//    PUBLIC METHODS
//==============================
  void metabolism(std::vector<float>* ext_metab) override;  

protected:
//======================================================================
//                      PROTECTED METHODS
//======================================================================
  void                     Update_Fit() override;

//======================================================================
//                           ATTRIBUTES
//======================================================================
  static const float       Rbb_;
  static const float       Rbc_;
  static int               nb_Gb; 
};




//======================================================================
//                   INLINE FUNCTION DEFINITION
//======================================================================
inline int Gb::Get_nb() const

/*Return the number of Gb type cells */

  {
    return nb_Gb;
  }


inline char Gb::WhatAmI()

/*Return the b phenotype */

  {
	  return 'b';
  }

#endif // GB_H
