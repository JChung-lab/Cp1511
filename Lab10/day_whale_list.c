#include <stdio.h>
//
// Starting code for CP1511 lab exercises
//
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
struct date *stringToDate(char *s);

void dayWhales(struct pod *firstPod, struct date *day);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <day>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct pod *firstPod = readSightingsFile();
    struct date *day = stringToDate(argv[1]);

    dayWhales(firstPod, day);

    return EXIT_SUCCESS;
}


// Print the whale sightings, for the specified day.
// One line containing number of whales and species
// is printed for each sighting.

void dayWhales(struct pod *firstPod, struct date *day) {
    // PUT YOUR CODE HERE
    struct pod *p = firstPod;
    while( p != NULL ){
        if(p->when->year==day->year&&p->when->month==day->month&&p->when->day==day->day) {
            printf("%d %s\n",p->howMany,p->species);
            
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


// given a string containing a date in day/month/year format
// return a pointer to a malloced date struct containing them
// return NULL if a date can not be read

struct date *stringToDate(char *s) {
    struct date *d = malloc(sizeof (struct date));
    if (d == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(EXIT_FAILURE);
    }
    int nScanned = sscanf(s, "%d/%d/%d", &(d->day), &(d->month), &(d->year));
    if (nScanned != 3) {
        free(d);
        return NULL;
    }
    return d;
}
