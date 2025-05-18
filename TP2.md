Pourquoi j'ai choisi la liste d'adjacence
Pour représenter le labyrinthe sous forme de graphe, j’avais deux choix : la matrice d’adjacence ou la liste d’adjacence.
J’ai choisi la liste d’adjacence parce que c’est beaucoup plus efficace pour un labyrinthe. En effet, dans un labyrinthe, la plupart des cases sont des murs, donc il y a très peu de connexions entre les nœuds. La liste d’adjacence ne garde en mémoire que les vrais chemins, alors que la matrice d’adjacence gaspille de la place pour rien, car elle réserve de la mémoire pour toutes les cases, même celles qui sont des murs.
En plus, quand on utilise l’algorithme A*, on a souvent besoin de parcourir rapidement les voisins d’un nœud. Avec une liste d’adjacence, c’est direct : on a juste à lire la liste des voisins. Avec une matrice, il faudrait parcourir toute une ligne, ce qui est beaucoup plus lent.
En résumé :
La liste d’adjacence prend moins de mémoire, surtout pour les grands labyrinthes.
Elle est plus rapide pour trouver les voisins d’un nœud, ce qui est parfait pour A*.
C’est pour ça que j’ai choisi cette structure : elle est tout simplement mieux adaptée à ce problème.