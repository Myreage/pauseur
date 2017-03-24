int choixPertinent(char **colortable, char color, int **connexetab, int n){
  int i,j;
  int **aux = createconnexetab(n);

  for(i=0;i<n;i++){   /*copie de la connexetab*/
    for(j=0;k<n;j++){
      aux[i][j] = connexetab[i][j];
    }
  }

  updateconnexetab(colortable, aux, color, n);

  for(i=0;i<n;i++){   /*comparaison des tables*/
    for(j=0;k<n;j++){
      if(aux[i][j] != connexetab[i][j]){
        return 1;        /*s'il y a une modif, ok*/
      }
    }
  }
  return 0; /*sinon, pas pertinent*/

}

void solveur(grille g, pile solution) {
  // déclarations des variables locales i, g2, …
  for (i=0; i<6; i=i+1) { // pour toutes les couleurs possibles
    if (choixPertinent(g,i)) {
      solution = empiler(solution,c[i]);
      g2 = propageCouleur(g, c[i]);
      if (victoire(g2)) uneSolutionTrouvee(solution);
      else solveur(g2, solution);
      depiler(&solution);
      }
  }
}
