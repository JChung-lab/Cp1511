
//
// Starting code for CP1511 lab exercises
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SPECIES_NAME_LENGTH 4096

// a struct to represent the date
// a whale pod sighting was made

struct date {
    int year;
    int month;
    int day;
};

// a struct to represent a sighting
// of a pod (group) of whales

struct pod {
    struct pod  *next;
    struct date *when;
    int         howMany;
    char        *species;
};


static struct pod *readSightingsFile();
static struct pod *readSighting();
struct date *readDate();

void speciesCount(char species[], struct pod *firstPod, int *nPods, int *nWhales);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <species>\n", argv[0]);
        return EXIT_FAILURE;
    }
    char *species = argv[1];

    struct pod *firstPod = readSightingsFile();

    int podCount;
    int whaleCount;
    speciesCount(species, firstPod, &podCount, &whaleCount);
    printf("%d %s pods containing %d whales\n", podCount, species, whaleCount);

    return EXIT_SUCCESS;
}

// number of pods of the specified species assigned to *n_pods
// total number of whales of the specified species assigned to *n_whales

void speciesCount(char species[], struct pod *firstPod, int *nPods, int *nWhales) {
    // REPLACE THIS COMMENT WITH YOUR CODE
    // YOU ARE NOT PERMITTED TO USE ARRAYS
    // THIS FUNCTION SHOULD NOT CALL SCANF OR PRINTF
    // IT SHOULD JUST RETURN A VALUE
    *nPods = 0;
    *nWhales = 0;
    struct pod *p = firstPod;
    while( p != NULL ){
        if(strcmp(p->species, species) == 0) {
            *nPods = *nPods +1;
            *nWhales = *nWhales + p->howMany;
        }
        p = p->next;
    }
}


//
// DO NOT CHANGE THE FUNCTIONS BELOW HERE
//

// return linked list of sightings read from filename
// exit called if there is an error

struct pod *readSightingsFile() {
    /*FILE *f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr,"error: file '%s' can not open\n", filename);
        exit(EXIT_FAILURE);
    }
    */
    struct pod *firstSighting = NULL;
    struct pod *lastSighting = NULL;

    struct pod *sighting = readSighting();
    while (sighting != NULL) {
        if (firstSighting == NULL) {
            firstSighting = sighting;
            firstSighting->next = NULL;
        } else {
            lastSighting->next = sighting;
        }
        lastSighting = sighting;
        sighting = readSighting();
    }

    return firstSighting;
}


// read a whale sighting (date, number of whales, whale species)
// return a pointer to a malloced struct containing these details
// return NULL if a sighting can not be read

struct pod *readSighting() {
    struct pod *p = malloc(sizeof (struct pod));
    if (p == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(1);
    }

    p->next = NULL;

    p->when = readDate();
    if (p->when == NULL) {
        free(p);
        return NULL;
    }

    int nScanned = scanf("%d", &(p->howMany));
    if (nScanned != 1) {
        free(p);
        return NULL;
    }

    fgetc(stdin);
    char speciesBuffer[MAX_SPECIES_NAME_LENGTH];
    if (fgets(speciesBuffer, MAX_SPECIES_NAME_LENGTH, stdin) == NULL) {
        free(p);
        return NULL;
    }
   // finish string at '\n' if there is one
    char *newlinePtr = strchr(speciesBuffer, '\n');
    if (newlinePtr != NULL) {
        *newlinePtr = '\0';
    }

    // also finish string at '\r' if there is one - files from Windows  will
    newlinePtr = strchr(speciesBuffer, '\r');
    if (newlinePtr != NULL) {
        *newlinePtr = '\0';
    }

    // malloc a char array long enough to hold species name
    // and copy species to it
    p->species = malloc(strlen(speciesBuffer) + 1);
    if (p->species == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(EXIT_FAILURE);
    }
    strcpy(p->species, speciesBuffer);

    return p;
}


// read a date in day/month/year format from stream f
// return a pointer to a malloced date struct containing them
//  return NULL if a date can not be read

struct date *readDate() {
    struct date *d = malloc(sizeof (struct date));
    if (d == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(1);
    }
    int n_scanned = scanf("%d/%d/%d", &(d->day), &(d->month), &(d->year));
    if (n_scanned != 3) {
        free(d);
        return NULL;
    }
    return d;
}
