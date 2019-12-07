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


struct pod *readSightingsFile();
struct pod *readSighting();
struct date *readDate();

int countOrcaSightings(struct pod *firstPod);

int main(int argc, char *argv[]) {
    

    struct pod *firstPod = readSightingsFile();

    int nOrcaPods = countOrcaSightings(firstPod);
    printf("%d Orca sightings in the list\n", nOrcaPods);

    return EXIT_SUCCESS;
}

// return the number of sightings of Orca

int countOrcaSightings(struct pod *firstPod) {
    // REPLACE THIS COMMENT WITH YOUR CODE
    // YOU ARE NOT PERMITTED TO USE ARRAYS
    // THIS FUNCTION SHOULD NOT CALL SCANF OR PRINTF
    // IT SHOULD JUST RETURN A VALUE
    //return 42; // CHANGE ME
    int orcaCount = 0;
    struct pod *p = firstPod;
    while( p != NULL ){
        if(strcmp(p->species, "Orca") == 0) {
            orcaCount = orcaCount +1;
        }
        p = p->next;
    }
    return orcaCount; 

}

//
// DO NOT CHANGE THE FUNCTIONS BELOW HERE
//

struct pod *readSightingsFile() {
    
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
        exit(EXIT_FAILURE);
    }

    p->next = NULL;

    p->when = readDate();
    if (p->when == NULL) {
        free(p);
        return NULL;
    }

    //int nScanned = scanf(stdin, "%d", &(p->howMany));
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
    //int n_scanned = scanf(stdin, "%d/%d/%d", &(d->day), &(d->month), &(d->year));
    int n_scanned = scanf("%d/%d/%d", &(d->day), &(d->month), &(d->year));
    if (n_scanned != 3) {
        free(d);
        return NULL;
    }
    return d;
}
