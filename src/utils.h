#pragma once
#ifndef UTILS_H
#define UTILS_H


#include <stdint.h>

#define HEAP_SIZE (2048 * 2048 * 4)
// Structure représentant un noeud du graphe (un pixel accessible du labyrinthe)
typedef struct Node {
    int x, y;
    int g, h, f;
    struct Node* parent;
    struct Node** voisins;
    int nb_voisins;
} Node;

// Alloue une zone mémoire sur le tas personnalisé
void* allocate(size_t size);
// Initialise le tas mémoire pour les allocations personnalisées
void heap_init();
// Crée la grille de noeuds à partir de l'image (1 noeud par pixel blanc)
Node*** creer_grille(uint8_t* img, int w, int h);
// Relie chaque noeud aux voisins accessibles (haut, bas, gauche, droite)
void lier_voisins(Node*** grille, int w, int h);
// Algorithme A* pour trouver le chemin le plus court entre deux noeuds
Node* astar(Node* depart, Node* arrivee);

#endif


