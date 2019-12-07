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
struct date *stringToDate(char *s);

void betweenDaysWhales(struct pod *firstPod, struct date *startDay, struct date *finishDay);
// ADD YOUR NEW FUNCTION PROTOTYPES
int dayBetween(struct pod *firstPod, struct date *startDay, struct date *finishDay);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <start-day> <finish-day>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct pod *firstPod = readSightingsFile();
    struct date *startDay = stringToDate(argv[1]);
    struct date *finishDay = stringToDate(argv[2]);

    betweenDaysWhales(firstPod, startDay, finishDay);

    return EXIT_SUCCESS;
}


// Print the whale sightings between start_day and finish_day inclusive.
// One line containing number of whales and species is printed for each sighting.

void betweenDaysWhales(struct pod *firstPod, struct date *startDay, struct date *finishDay) {
// PUT YOUR CODE HERE
    struct pod *p = firstPod;
    while( p != NULL ){
        if(dayBetween(p,startDay,finishDay)==0) {
            printf("%02d/%02d/%02d %2d %s\n",p->when->day,p->when->month,p->when->year,p->howMany,p->species);
        }
        p = p->next;
    }
}

// PUT YOUR FUNCTIONS HERE
//
int dayBetween(struct pod *firstPod, struct date *startDay, struct date *finishDay){
    struct pod *p = firstPod;
    int yearP=p->when->year;
    int monthP=p->when->month;
    int dayP=p->when->day;
    int yearS=startDay->year;
    int monthS=startDay->month;
    int dayS=startDay->day;
    int yearF=finishDay->year;
    int monthF=finishDay->month;
    int dayF=finishDay->day;
    
    if( yearS < yearF && yearP >= yearS && yearP <= yearF ){
        if(yearP==yearS){
            if(monthP>monthS){
                return 0;
            }
            if(monthP==monthS&&dayP>=dayS){
                return 0;
            }
        }
        if(yearP==yearF){
            if(monthP<monthF){
                return 0;
            }
            if(monthP==monthF&&dayP<=dayF){
                return 0;
            }
        }
    }
    else if( yearS == yearF && yearP == yearF ){
        if( monthS < monthF && (monthP >= monthS && monthP <= monthF) ){
            if( monthP>monthS&&monthP<monthF ){
                return 0;
            } else if(monthP==monthS){
                if(dayP>=dayS){
                    return 0;
                } else {
                    return 1;
                }
            } else if(monthP==monthF){
                if(dayP<=dayF){
                    return 0;
                } else {
                    return 1;
                }
            }
        }
        if( monthS == monthF && monthP == monthS ){
            if( dayP <= dayF && dayP >= dayS ){
                return 0;
            }
        } 
    }
    return 1;
}
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
