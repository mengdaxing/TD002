#include <stdio.h>

int fun(int x,int y, int a, int b){
  // These are the four constrains. Make sure the point P(x,y) is in the diamond D(a,b).
  // l1: y = -b/a*x + b 
  // l2: y = b/a*x - b
  // l3: y = b/a*x + b 
  // l4: y = -b/a*x + 3*b 
  int couleur = 255;
  if (y >= -b/a*x + b 
  && y >= b/a*x - b 
  && y <= b/a*x + b
  && y <=-b/a*x + 3*b)
    couleur = 0;
  return couleur;
}

void drawJacquard(int nbL, int nbC, int nbSplitX, int nbSplitY) {
  int i, j, r;
  int couleur;
  int a = nbC / nbSplitX;
  int b = nbL / nbSplitY;
  FILE *fptr;
  fptr = fopen("my.ppm", "w");

  int x,y;
  fprintf(fptr, "P3\n%d %d\n255\n", nbC, nbL);

  for (i = 0; i < nbL; i++)
    for (j = 0; j < nbC; j++) {
      // tip1: Divide and conquer. Divide the question into smaller one
      x = j % (2*a);
      y = i % (2*b);

      // tip2: List the constrains, and make point P satisfy them.
      couleur = fun(x,y,a,b);
      fprintf(fptr, "%d %d %d\n", couleur, couleur, couleur);
    }
}

int main() {
  drawJacquard(500, 500, 10, 10);
  return 0;
}