#pragma once

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <math.h>

// *****   declarations of types and constants   *****

#define llu unsigned long long;

#define TRUE 1;
#define FALSE 0;
#define MAX_VERT    8 // maximum number of vertices (6 is for hexagon)

/*enum POLY_TYPE {QUADRI = 4, PENTAGON, HEXAGON = 6, 
                OCTAGON = 8, BAD_POLY};*/

enum POLY_TYPE {QUADRI = 4, HEXAGON = 6, OCTAGON = 8};
enum WHOM_TO_OUTPUT {CURRENT, ALL_POLY, NONE};

struct point {
   int x, y;
};

struct polygon {
     enum POLY_TYPE poly_type;
     struct point * vertices;
}; 

// *****   declarations of function prototypes   *****
void my_exception(int line, const char* function, char* msg);
double calc_side(struct point pt1, struct point pt2);
double calc_triangle_area(struct point p1, struct point p2, struct point p3);
double calc_perimeter(struct polygon polygonToCalc);
double calc_area(struct polygon polygonToCalc);
void print_point(struct point pt);
void print_polygon_name(enum POLY_TYPE poly);
void get_instruction_line(int* isFlagNOn, int* isFlagLOn, enum WHOM_TO_OUTPUT * whomToOutput, int* isFlagdOn, int* isFlagpOn, int* isFlagaOn, enum POLY_TYPE * polyType);
char * getString();
void print_poloygon(int isFlagdOn, int isFlagpOn, int isFlagaOn, struct polygon polygonToPrint);
void print_polygon_perimeter(struct polygon polygonToPrint);
void print_polygon_area(struct polygon polygonToPrint);
void print_polygon_points(size_t sizeOfVerticlesArr, struct point * verticles);
struct point * get_verticles(enum POLY_TYPE polyType);
void get_lines_of_verticles_and_add_to_verticles_arr(struct point ** verticles, int numOfLines);
struct polygon * copy_polygon(struct polygon polygonOfNewNode);
int get_num_of_points_by_polygon_type(enum POLY_TYPE polyType);
int get_num_of_numbers_to_read_by_polygon_type(enum POLY_TYPE polyType);
int get_coordinate_from_number(unsigned long long number);
void prog();
void free_polygon(struct polygon* poly);