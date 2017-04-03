//======================================================================
//                         INCLUDES
//======================================================================
#include "Environment.h"



//======================================================================
//                  DEFINITION STATIC ATTRIBUTES
//======================================================================
const float Environment::dt_ =0.1;

//======================================================================
//                         CONSTRUCTORS
//======================================================================

Environment::Environment()

/*Environment default constructor : built an toroidal grid_ of W_*H_ 
 * size in wich each coordinate represents a box that host a cell. No 
 * metabolites are added into the environment. There are as much Ga 
 * phenotype cells as Gb and these are placed randomly into the 
 * environment.*/

  {
    W_ = 32;
    H_ = 32;
    A_init_ = 0;
    D_ = 0.1;
    vector<char>* tab = new vector<char> (W_*H_);
    grid_ = vector<vector<Box*>>(H_,vector< Box* >(W_));
    for (int i = 0 ; i!=W_*H_/2 ; ++i ){
      (*tab)[i]='a';
    }
    for (int j = W_*H_/2  ; j!=W_*H_; ++j){
      (*tab)[j]='b';
    }
      
    vector<vector<Box*> >::iterator row;
    vector<Box*>::iterator col;
    for (row = grid_.begin(); row != grid_.end(); row++) {
      for (col = row->begin(); col != row->end(); col++) {
        char type = pick_char(tab);
	  (*col) = new Box(type,A_init_);
	  }
    }
    delete tab;
  }
  
Environment::Environment(float A_init)

/*Environment constructor based on the level of glucose placed into the 
 * environment. The environment is created with the default constructor 
 * but the initial level of glucose (A_init) contained in each box is 
 * chosen by the user. */
{
      W_ = 32;
      H_ = 32;
      A_init_ = A_init;
      D_ = 0.1;
      vector<char>* tab = new vector<char> (W_*H_);
      grid_ = vector<vector<Box*>>(H_,vector< Box* >(W_));
      for (int i = 0 ; i!=W_*H_/2 ; ++i ){
          (*tab)[i]='a';
      }
      for (int j = W_*H_/2  ; j!=W_*H_; ++j){
          (*tab)[j]='b';
      }
      
      vector<vector<Box*> >::iterator row;
      vector<Box*>::iterator col;
      for (row = grid_.begin(); row != grid_.end(); row++) {
          for (col = row->begin(); col != row->end(); col++) {
              char type = pick_char(tab);
              (*col) = new Box(type,A_init_);
          }
      }
      delete tab;
  }
  
  
//======================================================================
//                          DESTRUCTOR
//======================================================================
Environment::~Environment()

/*Destructor of environment : apply the box destructor for each box 
 * contained into the grid_.*/

  {
    vector<vector<Box*> >::iterator row;
    vector<Box*>::iterator col;
    for (row = grid_.begin() ; row != grid_.end(); row++)
    { 
      for (col = row->begin(); col != row->end(); col++) {
          delete *col;
      }
    }
  }

//======================================================================
//                       PUBLIC METHODS
//======================================================================
vector<int> Environment::Run(float time, float T)
  
  /* This function run the growth of the cell population and save into a 
   * csv file called data.csv the number of Ga and Gb phenotypes. Every 
   * T time the growth middle is refresh (the metabolites in the middle 
   * are removed and replace by A metabolite). For every dt until time
   * one cycle occure. */
 
  {
	  float T_ = T;
	  float elapse_Time = 0;
	  float refresh_Time = 0;
          int nb_cell;
	  while(elapse_Time < time)
      {
			  elapse_Time ++;
			  refresh_Time ++;
			  if (refresh_Time > T_) 
			  // The environment is refreshed every T_ span.
          {
            refresh_Environment();
            refresh_Time = 0;
				  }
              
			  Cycle();
          nb_cell = grid_[0][0]->cell_-> Get_nb();
          if ((W_*H_ - nb_cell==0 or nb_cell==0) and grid_[0][0]->cell_->Pmut()){cout<<"BREAK"<<endl;break;}
			
              }
		nb_cell = grid_[0][0]->cell_-> Get_nb();
		if (grid_[0][0]-> get_cell_type() == 'a')
		{
			return {nb_cell , W_*H_ - nb_cell}; // (Ga,Gb) vector is returned 
		}
		else 
		{
			return {W_*H_ - nb_cell, nb_cell};
		}
			
	}

    

//======================================================================
//                     PROTECTED METHODS
//======================================================================
vector<int> Environment::toroidal(vector<int> coord)

/*This function ensure the toroidal behaviour of the environment. For a 
 * given coordinate, it return its coordinate into the environment so 
 * that it will never leave the space delimited */

  {
    int i = coord[0];
    int j = coord[1];
    if (i < 0)
      {
        if (j<0)
          {
            return {H_-1,W_-1};
          }
        if (j>(W_-1))
          {
            return {H_-1,0};
          }
        return {H_-1,j};
      }
    if (i>(H_-1))
      {
        if (j<0)
          {
            return {0,W_-1};
          }
        if (j>(W_-1))
          {
            return {0,0};
          }
        return {0,j}; 
      }
    if (j>(W_-1))
      {
        return {i,0};
      } 
    if (j<0)
      {
        return {i,W_-1};
      }
    return {i,j};
  }


void Environment::diffuse_box(int x, int y)

/* This function makes the metabolites diffuse into one box of the 
 * environment considering its neighboors. The new metabolites level of 
 * the box is updated*/
{
    //cout <<" ----------------"<<endl;

    vector<float>* ABC =  grid_[x][y]->get_box_metabolites();
    vector<float>* Next_ABC = grid_[x][y]->get_box_next_metabolites();
    
    *Next_ABC = *ABC;
    
   //cout<<(*ABC)[0]<<"    "<<(*ABC)[1]<<"   "<<(*ABC)[2]<<endl;
    
    
    for (int i = -1; i <= 1; ++i){
        for (int j = -1; j <= 1; ++j){
            vector<int> coord = {x+i , y+j};
            coord = toroidal(coord);
            vector<float>* Neib_Box_ABC = grid_[coord[0]][coord[1]]-> get_box_metabolites();
            for (int rank = 0 ; rank < 3 ;  ++rank){
                Next_ABC->at(rank) += D_ * Neib_Box_ABC->at(rank);
            }
        }
    }
    for (int rank = 0 ; rank < 3 ;  ++rank){
        Next_ABC->at(rank) -= 9*D_ * ABC->at(rank);
    }
       //cout<<(*Next_ABC)[0]<<"    "<<(*Next_ABC)[1]<<"   "<<(*Next_ABC)[2]<<endl;
}

void Environment::diffuse_metabolites()

/* Run though the environment to make the metabolites diffuse into each 
 * box.*/

  {
    for (int x = 0 ; x < H_ ; ++x)
      {
        for (int y = 0 ; y < W_ ; ++y)
          {
            diffuse_box(x,y);
          }
      }
  }
  
  
vector<vector<int>>* Environment::Cellular_killer()

/* Run though the grid and for each box determine if the containig cell 
 * will die considering its probability of death*/

  {
    vector<vector<int>>* result = new vector<vector<int>>;
    for (int x = 0 ; x < H_ ; ++x)
      {
        for (int y = 0 ; y < W_; ++y)
          {
            if (grid_[x][y]->Cellular_death())
              {
                result->push_back(vector<int> {x,y});
              }
      
          } 
      }
    return(result);
  }


vector<int> Environment::Best_fit(vector<int> EmptyBox)

/* Given the coordinates of an empty box, determine which of its 
 * neighboor's cell is the most likely to divide into the box. The 
 * best neigboor is the one having the best fitness. If the best fitness
 * is shared by several cells the best neigboor will be randomly 
 * chosen between those cells. */

  {
    float Bestfit = 0.0;
    vector<vector<int>>* C = new vector<vector<int>> {};
    for (int i = -1 ; i <= 1 ; ++i)
      {
        for (int j = -1 ; j <= 1 ; ++j)
          {
            vector<int> coord = toroidal({EmptyBox[0]+i , EmptyBox[1]+j});
            if (grid_[coord[0]][coord[1]]->empty_Box() != true)
            /*We check if the neighboring box contain a cell, otherwise 
             * make it divided would be impossible */
              {
                float fitness = grid_[coord[0]][coord[1]]->get_cell_fitness();
                if (fitness == Bestfit)
                  {
                    C->push_back(coord); 
                    /* We put into a vector of coordinates of cells with
                     * the same fitness.*/
                  }
                if (fitness > Bestfit)
                  {
                    Bestfit = fitness;
                    delete C;
                    C = new vector<vector<int>> {{coord[0],coord[1]}};
                  }
              }
          }   
      }
    vector<int> xy = pick_coord(C); 
    /*we choose randomly coordinate of the cell having the same best 
     * fitness*/
    delete C;
    return xy ;
  }


 void Environment::Cycle()

/*Gather all the function describing the environment behaviour during 
 * one cycle  : 
 * - Make cell randomly die
 * - Make the surviving cells compete to divide into the empty space
 * - The metabolites diffuse into the environment
 * - Each cells metabolizes the metabolites into its box */
 {
  //Diffusion
     
   diffuse_metabolites();

 //Cellular Death
   vector< vector<int> >* dead_ones = Cellular_killer();


 //Competition
   for (auto l = dead_ones->size() ; l > 0 ; l--){
     vector<int> coord_empty = pick_coord(dead_ones);
     vector<int> coord_best_fit = Best_fit(coord_empty);
     grid_[coord_empty[0]][coord_empty[1]]->newborn( grid_[coord_best_fit[0]][coord_best_fit[1]]->cell_ );
   }
     delete dead_ones;
  //Diffusion 	
    diffuse_metabolites(); 


  //Metabolism
    for (auto col = grid_.begin(); col != grid_.end() ; col++)
    {
		for (auto box = col->begin() ; box != col->end() ; box++)
		{
			(*box)->metab_trade();
		}
	}
 }
 
 
 void Environment::refresh_Environment()

/*Reset every box of the environment at the initial glucose 
 * concentration (A_init)*/
 {
    for (auto col = grid_.begin(); col != grid_.end() ; col++)
    {
		for (auto box = col->begin() ; box != col->end() ; box++)
		{
			(*box)->refresh_box(A_init_);
		}
	}
 }
 



	  
    
char Environment::pick_char(vector<char>* tab)

/* This function pick randomly and return a caractere contained into a 
 * vector given as argument*/

  {
    int r;
    if (tab->size() > 1)
      r = rand() % (tab->size()-1);
    else
      r = 0;
    char res = tab->at(r);
    int i = 0;
    for (auto it = tab->begin(); it != tab->end() ; ++it, ++i)
      {
        if (i==r) 
          {
            tab->erase(it);
            break;
          }
      }
    return res;
  }
 
 
vector<int> Environment::pick_coord (vector< vector<int> >*  tab)

/* This function pick randomly and return a vector of coordinates 
 * contained into a vector given as argument*/
 
  {
    int r;
    if (tab->size() > 1)
        r = rand() % (tab->size()-1);
    else
        r = 0;
    vector<int> res = tab->at(r);
    int i = 0;
    for (auto it = tab->begin(); it != tab->end() ; ++it, ++i)
      {
        if (i==r) 
          {
            tab->erase(it);
            break;
          }
      }
    return res;  
  }



