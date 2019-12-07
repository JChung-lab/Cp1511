// Assignment 2 19T2 CP1511: Pokedex
// pokedex.c
//
// This program was written by Megan Michelle Wong (z5241209)
// on 27/07/2019
//
// Version 1.0.0: Assignment released.
// Version 1.0.1: Minor clarifications about `struct pokenode`.
// Version 1.1.0: Moved destroy_pokedex function to correct location.
// Version 1.1.1: Renamed "pokemon_id" to "id" in change_current_pokemon.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Add any extra #includes your code needs here.a
#include <ctype.h>

// But note you are not permitted to use functions from string.h
// so do not #include <string.h>

#include "pokedex.h"

// Add your own #defines here.
#define IS_FOUND  1
#define NOT_FOUND 0

// Note you are not permitted to use arrays in struct pokedex,
// you must use a linked list.
//
// You are also not permitted to use arrays in any of the functions
// below.
//
// The only exception is that char arrays are permitted for
// search_pokemon and functions it may call, as well as the string
// returned by pokemon_name (from pokemon.h).
//
// You will need to add fields to struct pokedex.
// You may change or delete the head field.

struct pokedex {
    struct pokenode *head;
    struct pokenode *selected;
};

// You don't have to use the provided struct pokenode, you are free to
// make your own struct instead.
// If you use the provided struct pokenode, you will need to add fields
// to it to store other information.

struct pokenode {
    struct pokenode *next;
    // Pointer to the pokemon that the current selected one evolves into.
    struct pokenode *evolveTo;
    // Pointer to the pokemon that the current selected one evolves from.
    struct pokenode *evolveFrom;
    Pokemon         pokemon;
    int found;
    int to;
};

// Add any other structs you define here.

// Function that returns a pointer to a struct of pokenode created.
struct pokenode *new_pokenode(Pokemon pokemon);
//
static void add_to_end(Pokedex pokedex, struct pokenode *node);
static void print(Pokemon pokemon);
static void nameLength(Pokemon pokemon);
static void printPokemon(Pokemon pokemon);
static int nameMatch(char *name, char *text);
static int inputLength(char *text);

// You need to implement the following 20 functions.
// In other words, replace the lines calling fprintf & exit with your code.
// You can find descriptions of what each function should do in pokedex.h


Pokedex new_pokedex(void) {
    Pokedex new_pokedex = malloc(sizeof (struct pokedex));
    assert(new_pokedex != NULL);
    // add your own code here
    new_pokedex->head = NULL;
    return new_pokedex;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                          //
////////////////////////////////////////////////////////////////////////

// Function that adds a pokemon given as a parameter at the end of the list
void add_pokemon(Pokedex pokedex, Pokemon pokemon) {
    struct pokenode *node = new_pokenode(pokemon);
    add_to_end(pokedex,node);
}

// Function that returns a pointer to a node that contains all the fields defined
struct pokenode *new_pokenode(Pokemon pokemon) {
    struct pokenode *node;
    node = malloc(sizeof(struct pokenode));
    node->pokemon = pokemon;
    node->next = NULL;
    node->evolveTo = NULL;
    node->evolveFrom = NULL;
    node->found = NOT_FOUND;
    node->to = -2;

    return node;
}

// Function that adds a pokenode at the end of the pokedex.
static void add_to_end(Pokedex pokedex, struct pokenode *node) {

    struct pokenode *curr = NULL;
    // Add to the head if the pokedex is empty.
    if( pokedex->head == NULL ) {
        pokedex->head = node;
        pokedex->selected = pokedex->head;
    } else {
        curr = pokedex->head;
        // Add the node to the end of the list.
        while( curr->next != NULL ) {
            // If the pokemon with that id is already in the pokedex, exits the program.
            if( pokemon_id(curr->pokemon) == pokemon_id(node->pokemon) ) {
                fprintf(stderr, "The pokemon has already been added\n");
                exit(1);
            }
            curr = curr->next;
        }
        curr->next = node;
    }
}

// Function to print the details of the currently selected pokemon.
void detail_pokemon(Pokedex pokedex) {

    struct pokenode *curr = pokedex->selected;
    // If the pokemon is found, print all the details, otherwise print symbols.
    if( curr->found == IS_FOUND ) {
        print(curr->pokemon);
    } else {
        printf("Id: %03d\n", pokemon_id(curr->pokemon));
        printf("Name: ");
        nameLength(curr->pokemon);
        printf("Height: --\n");
        printf("Weight: --\n");
        printf("Type: --\n");
    }
}

// Function to print details of the pokemon if it is found.
static void print(Pokemon pokemon) {

    pokemon_type first = pokemon_first_type(pokemon);
    pokemon_type second = pokemon_second_type(pokemon);
    
    const char *firstS = pokemon_type_to_string(first);
    const char *secondS = pokemon_type_to_string(second);
    
    printf("Id: %03d\n", pokemon_id(pokemon));
    printf("Name: %s\n", pokemon_name(pokemon));
    printf("Height: %.1fm\n", pokemon_height(pokemon));
    printf("Weight: %.1fkg\n", pokemon_weight(pokemon));
    if( second == NONE_TYPE ) {
        printf("Type: %s\n", firstS);
    } else {
        printf("Type: %s %s\n", firstS, secondS);
    }
}

// Function to print the equal number of asterisks and the length of the name.
static void nameLength(Pokemon pokemon) {

    int i = 0;
    char *name = pokemon_name(pokemon);
    while( name[i] != '\0' ) {
        i++;
    }
    for( int j = 0; j < i; j++ ) {
        printf("*");
    }
    printf("\n");
}

// Function that returns a pointer to the currently selected pokemon.
Pokemon get_current_pokemon(Pokedex pokedex) {

    if( pokedex->head == NULL ) {
        fprintf(stderr, "There is no pokemon inside the pokedex\n");
        exit(1);
    }
    return pokedex->selected->pokemon;
}

// Function that set the currently selected to be FOUND.
void find_current_pokemon(Pokedex pokedex) {

    if( pokedex->head != NULL ) {
        if( get_current_pokemon(pokedex) != NULL ) {
            pokedex->selected->found = IS_FOUND;
        }
    }
}

// Function that prints the list of pokemons in the pokedex and highlights 
// the currently selected one with an -->.
void print_pokemon(Pokedex pokedex) {

    struct pokenode *curr = pokedex->head;
    // Loop to search each pokemon if it is the selected one.
    while( curr != NULL ){
        if( pokemon_id(curr->pokemon) == pokemon_id(get_current_pokemon(pokedex)) ) {
            printf("--> ");
        } else {
            printf("    ");
        }
        printf("#%03d: ", pokemon_id(curr->pokemon));
        // If pokemon is found, print the name, otherwise print asterisks.
        if( curr->found == IS_FOUND ) {
            printf("%s\n", pokemon_name(curr->pokemon) );
        } else {
            nameLength(curr->pokemon);
        }
        curr = curr->next;
    }
}

////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////

// Function to set the currently selected pokemon to be the next one.
void next_pokemon(Pokedex pokedex) {
 
    struct pokenode *curr = NULL;
    
    if( pokedex->head != NULL ) {
        curr = pokedex->selected;
        // If there is a pokemon next to the selected one. Otherwise selected stays the same.
        if( curr->next != NULL ) {
            pokedex->selected = curr->next;
        }
    }
}

// Function to set the currently selected pokemon to be the previous one.
void prev_pokemon(Pokedex pokedex) {

    struct pokenode *curr = NULL;
    struct pokenode *previous = NULL;
    
    // If the pokedex is empty it does nothing.
    if( pokedex->head != NULL ) {
        previous = pokedex->head;
        if( pokedex->selected != NULL ) {
            // If the selected pokemon is the first added, it does not change.
            if( pokedex->selected == previous ) {
                pokedex->selected = previous;
            } else {
                curr = pokedex->selected;
                // Loop to find the node that its next points to the selected pokemon.
                while( previous->next != curr ) {
                    previous = previous->next;
                }
                pokedex->selected = previous;
            }
        }
    }
}

// Function to change the selected pokemon by a given id.
void change_current_pokemon(Pokedex pokedex, int id) {

    struct pokenode *curr = NULL;
    
    if( pokedex->head != NULL ) {
        curr = pokedex->head;
        // Loop to reach to the pokemon with the given id.
        while( curr->next != NULL && pokemon_id(curr->pokemon) != id ) {
            curr = curr->next;
        }
        pokedex->selected = curr;
    }
}

// Function to remove the selected pokemon from the pokedex and free the memory.
void remove_pokemon(Pokedex pokedex) {

    struct pokenode *selected = NULL;
    struct pokenode *previous = NULL;
    
    if( pokedex->head != NULL ) {
        previous = pokedex->head;
        selected = pokedex->selected;
        if( previous == selected ) {
            //If the current selected pokemon is the only pokemon of the pokedex.
            if( selected->next == NULL ) {
                pokedex->head = NULL;
                destroy_pokemon(selected->pokemon);
                free(selected);
            } else {
                // If the pokemon to remove is the evolution of another pokemon.
                if( selected->evolveFrom != NULL ) {
                    selected->evolveFrom->evolveTo = NULL;
                }
                selected = selected->next;
                pokedex->head = selected;
                pokedex->selected = pokedex->head;
                destroy_pokemon(previous->pokemon);
                free(previous);
            }
        } else {
            // Loop to search the pointer that points to the pokemon to remove.
            while( previous->next != selected ) {
                previous = previous->next;
            }
            // If the pokemon to remove is the evolution of another pokemon.
            if( selected->evolveFrom != NULL ) {
                selected->evolveFrom->evolveTo = NULL;
            }
            pokedex->selected = previous;
            previous->next = selected->next;
            // If there is a next pokemon, that would be the new selected pokemon,
            // otherwise it would stay to be the previous one.
            if( selected->next != NULL ) {
                pokedex->selected = selected->next;
                destroy_pokemon(selected->pokemon);
                free(selected);
            } else {
                destroy_pokemon(selected->pokemon);
                free(selected);
            }
        }
    }
}

// Function to destroy the pokedex and free all allocated memory.
void destroy_pokedex(Pokedex pokedex) {

    struct pokenode *temp = pokedex->head;
    // Loop to run until the head becomes NULL.
    while( pokedex->head != NULL ) {
        temp = pokedex->head;
        pokedex->head = pokedex->head->next;
        destroy_pokemon(temp->pokemon);
        free(temp);
    }
    free(pokedex);
}

// Function that returns the total number of found pokemons in the pokedex.
int count_found_pokemon(Pokedex pokedex) {

    int count = 0;
    struct pokenode *curr = pokedex->head;
    // Loop to search if each pokemon is found.
    while( curr != NULL ) {
        if( curr->found == IS_FOUND ) {
            count++;
        }
        curr = curr->next;
    }
    return count;
}

// Function that returns the total number of pokemons in the pokedex.
int count_total_pokemon(Pokedex pokedex) {

    int count = 0;
    struct pokenode *curr = pokedex->head;
    // Loop counter.
    while( curr != NULL ) {
        count++;
        curr = curr->next;
    }
    return count;
}


////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////

// Function to add pokemons evolutions
void add_pokemon_evolution(Pokedex pokedex, int from_id, int to_id) {

    int flag1 = 0;
    int flag2 = 0;
    // If the two ids are equal, exits the program.
    if( from_id == to_id ) {
        fprintf(stderr, "The pokemon cannot be set to evolve itself\n");
        exit(1);
    }
    struct pokenode *curr = NULL;
    struct pokenode *fromPokemon = NULL;
    struct pokenode *toPokemon = NULL;
    
    if( pokedex->head != NULL ) {
        curr = pokedex->head;
        // Loop to search the pokemon with the from_id and to_id.
        while( curr != NULL ) {
            if( pokemon_id(curr->pokemon) == from_id ) {
                flag1 = 1;
                curr->to = to_id;
                fromPokemon = curr;
            }
            if( pokemon_id(curr->pokemon) == to_id ) {
                flag2 = 1;
                toPokemon = curr;
            }
            curr = curr->next;          
        }
        fromPokemon->evolveTo = toPokemon;
        toPokemon->evolveFrom = fromPokemon;
        
        // If one of the two pokemons does not exist in the list, exit the program.
        if( flag1 + flag2 != 2 ) {
            fprintf(stderr, "One of the ids does not exist in the pokedex\n");
            exit(1);
        }
    }
}

// Function that prints the sequence of evolution of the currently selected pokemon.
void show_evolutions(Pokedex pokedex) {

    struct pokenode *curr = pokedex->head;
    struct pokenode *selected = pokedex->selected;
    
    if( selected->found == IS_FOUND ) {
        printPokemon(selected->pokemon);
    } else {
        printf("#%03d ???? [????]", pokemon_id(selected->pokemon));
    }
    // Loop to search the evolution of the currently selected pokemon.
    while( curr != NULL ) {
        if( selected->evolveTo != NULL ) {   
            printf(" --> "); 
            if( selected->evolveTo->found == IS_FOUND ) {
                printPokemon(selected->evolveTo->pokemon);
            } else {
                printf("#%03d ???? [????]", pokemon_id(selected->evolveTo->pokemon));
            }
            selected = selected->evolveTo;
        }
        curr = curr->next;
    }
    printf("\n");
}

// Function to print the pokemon evolution with details if it is found.
static void printPokemon(Pokemon pokemon) {
    pokemon_type first = pokemon_first_type(pokemon);
    pokemon_type second = pokemon_second_type(pokemon);
    
    if( second == NONE_TYPE ) {
        printf(" #%03d %s [%s]", pokemon_id(pokemon), pokemon_name              (pokemon),pokemon_type_to_string(first));
    } else {
        printf(" #%03d %s [%s, %s]", pokemon_id(pokemon), pokemon_name(pokemon), pokemon_type_to_string(first), pokemon_type_to_string(second));
    }
}

// Function that returns the id of the pokemons that the currently selected one evolves into
int get_next_evolution(Pokedex pokedex) {
    struct pokenode *curr = NULL;
    if( pokedex->head != NULL ) {
        curr = pokedex->head;
        // Loop to find the pokemons which the selected evolves into
        while( curr != NULL ) {
            if( pokedex->selected->to == pokemon_id(curr->pokemon) ) {
                return pokemon_id(curr->pokemon);
            }
            curr = curr->next;
        }
    } else {
        fprintf(stderr, "The pokedex is empty!\n");
        exit(1);
    }
    return DOES_NOT_EVOLVE;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

// Funtion that returns a new created pokedex that contains the pokemons 
// that matches with the input type in the original pokedex.
Pokedex get_pokemon_of_type(Pokedex pokedex, pokemon_type type) {

    Pokedex pokedexType = new_pokedex();
    Pokemon pokemonType;

    if( type == NONE_TYPE || type == INVALID_TYPE || type == MAX_TYPE ) {
        fprintf(stderr, "The type is not valid!\n");
        exit(1);
    }
    
    struct pokenode *curr = NULL;
    if( pokedex->head != NULL ) {
        curr = pokedex->head;
        // Loop to find the pokemons which matches the type given
        while( curr != NULL ) {
            pokemon_type first = pokemon_first_type(curr->pokemon);
            pokemon_type second = pokemon_second_type(curr->pokemon);
            
            if( (type == first || type==second ) && curr->found == IS_FOUND ) {
                pokemonType = new_pokemon(pokemon_id(curr->pokemon), pokemon_name(curr->pokemon), 
                pokemon_height(curr->pokemon), pokemon_weight(curr->pokemon), first, second);
                add_pokemon(pokedexType,pokemonType);
                pokedexType->selected = pokedexType->head;
            }
            curr = curr->next;
        }
        struct pokenode *find;
        if( pokedexType->head != NULL ) {
            find = pokedexType->head;
            // Loop to set all of the pokemons inside the new pokedex to be found.
            while( find != NULL ) {
                find->found = IS_FOUND;
                find = find->next;
            }
        }
    }
    return pokedexType;
}

// Function that returns a new pokedex that contains pokemons that are found from the original pokedex.
Pokedex get_found_pokemon(Pokedex pokedex) {

    Pokedex pokedexFound = new_pokedex();
    Pokemon pokemonFound;
    struct pokenode *curr = NULL;
    if( pokedex->head != NULL ) {
        curr = pokedex->head;
        // Loop to find all the pokemons that are found in the original pokedex.
        while( curr != NULL ) {
            pokemon_type first = pokemon_first_type(curr->pokemon);
            pokemon_type second = pokemon_second_type(curr->pokemon);
            
            if( curr->found == IS_FOUND ) {
                pokemonFound = new_pokemon(pokemon_id(curr->pokemon), pokemon_name(curr->pokemon), 
                pokemon_height(curr->pokemon), pokemon_weight(curr->pokemon), first, second);
                // Sort the pokedex into ascendent order
                struct pokenode *nodeFound = new_pokenode(pokemonFound);
                struct pokenode *previous = NULL;
                struct pokenode *curr1 = NULL;
                
                if( pokedexFound->head == NULL ) {
                    pokedexFound->head = nodeFound;
                } else {
                    curr1 = pokedexFound->head;
                    // Loop to sort the list, sorting by insertion.
                    while( (curr1 != NULL) && (pokemon_id(nodeFound->pokemon) > pokemon_id(curr1->pokemon)) ) {
                        previous = curr1;
                        curr1 = curr1->next;
                    }
                    
                    if( previous == NULL ) {
                        pokedexFound->head = nodeFound;
                    } else {
                        previous->next = nodeFound;
                    }
                    nodeFound->next = curr1;
                }
                pokedexFound->selected = pokedexFound->head;
            }
            curr = curr->next;
        }
        struct pokenode *find = NULL;
        if( pokedexFound->head != NULL ) {
            find = pokedexFound->head;
            // Loop to set all of the pokemons in the new pokedex to be found.
            while( find != NULL ) {
                find->found = IS_FOUND;
                find = find->next;
            }
        }
    }  
    return pokedexFound;
}

// Funtion that returns a new pokedex that contains the pokemons with their name matching with a piece of string.
Pokedex search_pokemon(Pokedex pokedex, char *text) {

    Pokedex pokedexString = new_pokedex();
    Pokemon pokemonString;

    struct pokenode *curr = NULL;
    if( pokedex->head != NULL ) {
        curr = pokedex->head;
        
        while( curr != NULL ) {
            pokemon_type first = pokemon_first_type(curr->pokemon);
            pokemon_type second = pokemon_second_type(curr->pokemon);
            
            if( (nameMatch(pokemon_name(curr->pokemon) ,text) == 1) && (curr->found == IS_FOUND) ) {
                pokemonString = new_pokemon(pokemon_id(curr->pokemon), pokemon_name(curr->pokemon), 
                pokemon_height(curr->pokemon), pokemon_weight(curr->pokemon), first, second);
                add_pokemon(pokedexString,pokemonString);
                pokedexString->selected = pokedexString->head;
            }
            curr = curr->next;
        }
        struct pokenode *find = NULL;
        if( pokedexString->head != NULL ) {
            find = pokedexString->head;
            
            while( find != NULL ) {
                find->found = IS_FOUND;
                find = find->next;
            }
        }
    }
    return pokedexString;
}

// Function that checks if the name of the pokemon contains the text given by input, 
// if yes, returns 1, otherwise returns 0.
static int nameMatch(char *name, char *text) {
    int i = 0;
    int j;
    int k = 0;
    int count = 0;
    char compare[10] = {'\0'};
    char nameInLower[20] = {'\0'};
    // Loop to convert the input given to lower cases and store it into another array.
    while( text[k] != '\0' ) {
        compare[k] = text[k];
        compare[k] = tolower(compare[k]);
        k++;
    }
    // Loop to convert the name of the pokemon into lower cases.
    while( name[i] != '\0' ) {
        nameInLower[i] = tolower(name[i]);
        j = 0;
        // Loop to check if name contains text.
        while( compare[j] != '\0' ) {
            if( nameInLower[i] == compare[j] ) {
                count++;
                compare[j] = -1;
                break;
            }
            j++;
        }
        i++;
    }     
    // If the length of repeat is equal to the length of the text, returns 1.     
    if( count == inputLength(text) ) {
        return 1;
    }
    return 0;
}

// Function that returns the length of a string.
static int inputLength(char *text) {
    int length = 0;
    // Loop to count the number of chars
    while( text[length] != '\0' ) {
        length++;
    }
    return length;
}

// Add definitions for your own functions below.
// Make them static to limit their scope to this file.
