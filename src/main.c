//Bonne pratique, pour les includes systemes toujours utiliser <> et "" pour les includes de votre projet.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
#include "stb_image.h"
#include "stb_image_write.h"

#include "utils.h"

#define HEAP_SIZE (2048 * 2048 * 4)
static uint8_t* heap = NULL;
static size_t heap_top = 0;

// Allocation mémoire simple sur un gros buffer
void* allocate(size_t size) {
    size_t old_top = heap_top;
    heap_top += size;
    assert(heap_top <= HEAP_SIZE);
    return &heap[old_top];
}

int main(int argc, char** argv) {
    // Initialisation du tas mémoire
    heap = (uint8_t*)malloc(HEAP_SIZE);
    assert(heap != NULL);

    // Liste des noms d'images à traiter
    const char* img_names[] = {
        "31.bmp",
        "64.bmp",
        "128.bmp"
    };
    const size_t img_name_len = sizeof(img_names) / sizeof(img_names[0]);

    for (size_t idx = 0; idx < img_name_len; ++idx) {
        int width, height, channels;
        unsigned char* img = stbi_load(img_names[idx], &width, &height, &channels, 0);
        if (img == NULL) {
            printf("Error in loading the image %s\n", img_names[idx]);
            continue;
        }
        printf("Loaded image %s with a width of %dpx, a height of %dpx and %d channels\n",
            img_names[idx], width, height, channels);

        // Exemple de traitement : mettre tous les pixels blancs en rouge
        for (int i = 0; i < width * height * channels; i += channels) {
            unsigned char r = img[i];
            unsigned char g = (channels > 1) ? img[i + 1] : 0;
            unsigned char b = (channels > 2) ? img[i + 2] : 0;
            if (r == 255 && g == 255 && b == 255) {
                img[i] = 255;     // R
                if (channels > 1) img[i + 1] = 0;   // G
                if (channels > 2) img[i + 2] = 0;   // B
            }
        }

        // Générer le nom du fichier de sortie
        char filepath[128] = { 0 };
        snprintf(filepath, sizeof(filepath), "solution_%s", img_names[idx]);
        // Sauvegarde de l'image modifiée
        stbi_write_bmp(filepath, width, height, channels, img);
        printf("Saved: %s\n", filepath);

        stbi_image_free(img);
    }

    free(heap);
    return 0;
}
