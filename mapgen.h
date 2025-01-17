#ifndef _MAPGEN_H_
#define _MAPGEN_H_

#include <stdio.h>
#include <stdlib.h>

#include "const.h"
#include "util.h"

typedef struct _entity {
    int hp;
    int dmg;
    int x;
    int y;
} entity_t;

/*
    contains info about the world, i.e. the map, player position
    depth should be added at some point as well
*/
typedef struct _world {
    char map[ROWS][COLS];
    entity_t *player;
    entity_t **enemies;
    int depth;
    int exit_x;
    int exit_y;
} world_t;

/*
    initial map creation
    each cell has a 45% probability of being a wall
    otherwise it's floor
*/
void map_init(char map[ROWS][COLS]);

/*
    counts the number of walls around a given cell
    X X X
    X O X
    X X X
    counts how many of the Xs are walls
*/
int map_tile_neighbours(char map[ROWS][COLS], int x, int y);

/* gives the next iteration of the map after applying the rules once */
void map_step(char map[ROWS][COLS]);

/* applies map_step n times */
void map_iter(char map[ROWS][COLS], int n);

void map_add_exit(world_t *w);

void apply_fov(world_t *w, char map[ROWS][COLS], int fov_x, int fov_y);

#endif