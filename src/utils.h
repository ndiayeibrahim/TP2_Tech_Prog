#pragma once
#ifndef UTILS_H
#define UTILS_H


#include <stdint.h>

#define HEAP_SIZE (2048 * 2048 * 4)
// Structure repr�sentant un noeud du graphe (un pixel accessible du labyrinthe)
typedef struct Node {
    int x, y;
    int g, h, f;
    struct Node* parent;
    struct Node** voisins;
    int nb_voisins;
} Node;

// Alloue une zone m�moire sur le tas personnalis�
void* allocate(size_t size);
// Initialise le tas m�moire pour les allocations personnalis�es
void heap_init();
// Cr�e la grille de noeuds � partir de l'image (1 noeud par pixel blanc)
Node*** creer_grille(uint8_t* img, int w, int h);
// Relie chaque noeud aux voisins accessibles (haut, bas, gauche, droite)
void lier_voisins(Node*** grille, int w, int h);
// Algorithme A* pour trouver le chemin le plus court entre deux noeuds
Node* astar(Node* depart, Node* arrivee);

#endif


