#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/

struct s_art {
	char *name;
	int price;
};


/*--------------------------------
  :) function you must implement
  --------------------------------*/

void  sortArts(struct s_art **arts);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

struct s_art **getArts(void);


/*--------------------------------
  &  your own other function
  --------------------------------*/
void	print_arts(struct s_art **arts);

#endif
