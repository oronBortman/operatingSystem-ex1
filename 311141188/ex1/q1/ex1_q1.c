#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>
#include "ex1_q1.h"
#include "LinkedList.h"

//-----------------------------------------------
void print_point(struct point pt)
{
	printf("{%d, %d} ", pt.x, pt.y);
}

//-----------------------------------------------
void print_polygon_points(size_t sizeOfVerticlesArr, struct point * verticles)
{
    for(int i=0; i < sizeOfVerticlesArr; i++)
    {
        print_point(verticles[i]);
        printf(" ");
    }
}

//-----------------------------------------------
int get_num_of_points_by_polygon_type(enum POLY_TYPE polyType)
{
	int numOfPoints;
	switch(polyType)
    {
        case QUADRI:
            numOfPoints=4;
			break;
        case HEXAGON:
            numOfPoints=6;
			break;
        case OCTAGON:
            numOfPoints=8;
            break;
    }
	return numOfPoints;
}

//-----------------------------------------------
int get_num_of_numbers_to_read_by_polygon_type(enum POLY_TYPE polyType)
{
	int numOfLines;
	switch(polyType)
    {
        case QUADRI:
            numOfLines=1;
			break;
        case HEXAGON:
            numOfLines=2;
			break;
        case OCTAGON:
            numOfLines=2;
            break;
    }
	return numOfLines;
}

//-----------------------------------------------
double calc_perimeter(struct polygon polygonToCalc)
{
	int numOfPoints = get_num_of_points_by_polygon_type(polygonToCalc.poly_type);
	double perimeter=0.0;
	int i;
	struct point * vertices = polygonToCalc.vertices;
	for(i=0;i<numOfPoints-1;i++)
	{
		perimeter+=calc_side(vertices[i],vertices[i+1]);
	}
	perimeter+=calc_side(vertices[i],vertices[0]);

	return perimeter;
}

//-----------------------------------------------
double calc_area(struct polygon polygonToCalc)
{
	int numOfPoints = get_num_of_points_by_polygon_type(polygonToCalc.poly_type);
	double area=0.0;
	struct point * vertices = polygonToCalc.vertices;
	numOfPoints=numOfPoints-2;
	for(int i=0;i<numOfPoints;i++)
	{
		area+=calc_triangle_area(vertices[0],vertices[i+1],vertices[i+2]);
	}
	return area;

}

//-----------------------------------------------
void print_polygon_perimeter(struct polygon polygonToPrint)
{
	printf("perimeter = %0.1f", calc_perimeter(polygonToPrint));
    printf("\n");
}

//-----------------------------------------------
void print_polygon_area(struct polygon polygonToPrint)
{
	printf("area = %0.1f",calc_area(polygonToPrint));
    printf("\n");
}

//-----------------------------------------------
char * getString()
{
	fflush(stdin);
	unsigned int logSize = 1, phySize = 2;
	char * str = (char*)malloc(sizeof(char) * phySize);
	char ch;
	if (!str)
	{
		printf("memmory alocation is failed\n");
		exit(1);
	}
	ch = getchar();
	while (ch != '\n')
	{
		if (logSize == phySize)
		{
			phySize *= 2;
			str = (char*)realloc(str, sizeof(char)*phySize);
		}
		str[logSize-1] = ch;
		logSize++;
		ch = getchar();
	}
	str = (char*)realloc(str, sizeof(char)*logSize);
	str[logSize-1] = '\0'; // put in the last index the '\0';
	return str;
}

//-----------------------------------------------
void my_exception(int line, const char* function, char* msg)
{
			fprintf(stderr, "ERROR (line %d function: %s) !!!%s\n", line, function, msg);
      exit(1);
}

//-----------------------------------------------
double calc_side(struct point pt1, struct point pt2)
{
	double x = pt1.x - pt2.x;
	double y = pt1.y - pt2.y;
	return sqrt(x*x + y*y);	
}

//-----------------------------------------------
double calc_triangle_area(struct point p1, struct point p2, struct point p3)
{
	double area, 
	      x1 = p1.x, 
	      x2 = p2.x, 
	      x3 = p3.x, 
	      y1 = p1.y, 
	      y2 = p2.y, 
	      y3 = p3.y;		  
	area = 0.5*(x1*y2 + x2*y3 + x3*y1 - x2*y1 - x3*y2 -x1*y3);
	area = (area > 0) ? area : -area;
	return area;
}

//-----------------------------------------------
void print_polygon_name(enum POLY_TYPE poly)
{
  switch (poly)
  {
    case QUADRI:  printf("quadrilateral"); break;
    case HEXAGON: printf("hexagon"); break;
    case OCTAGON: printf("octagon"); break;
    default: my_exception(__LINE__, __func__, "bad-polygon_type");
  }
}

//-----------------------------------------------
void get_instruction_line(int* isFlagNOn, int* isFlagLOn, enum WHOM_TO_OUTPUT * whomToOutput, int* isFlagdOn, int* isFlagpOn, int* isFlagaOn, enum POLY_TYPE * polyType)
{
	char c;
	char * instructionLine = getString();
	int i=0;
	c=instructionLine[i];
	*whomToOutput = NONE;
	while( c != '\0')
	{
		if(c == 'Q')
		{
			*polyType = QUADRI;
		}
		else if(c == 'H')
		{
			*polyType = HEXAGON;
		}
		else if(c == 'O')
		{
			*polyType = OCTAGON;
		}
		else if(c == 'N')
		{
			*isFlagNOn = TRUE;
		}
		else if(c == 'L')
		{
			*isFlagLOn = TRUE;
		}
		else if(c == 'C')
		{
			*whomToOutput = CURRENT;
		}
		else if(c == 'A')
		{
			*whomToOutput = ALL_POLY;
		}
		else if(c == 'd')
		{
			*isFlagdOn = TRUE;
		}
		else if(c == 'p')
		{
			*isFlagpOn = TRUE;
		}
		else if(c == 'a')
		{
			*isFlagaOn = TRUE;
		}
		else
		{
			*whomToOutput = NONE;
		}
		
		i++;
		c=instructionLine[i];
	}
	free(instructionLine);
}

//-----------------------------------------------
void print_poloygon(int isFlagdOn, int isFlagpOn, int isFlagaOn, struct polygon polygonToPrint)
{
    enum POLY_TYPE polyType = polygonToPrint.poly_type;
    if(isFlagdOn)
    {
		int sizeOfVerticlesArr=get_num_of_points_by_polygon_type(polyType);
        print_polygon_name(polyType);
        printf(" ");
        print_polygon_points(sizeOfVerticlesArr, polygonToPrint.vertices);
        printf("\n");
    }
    if(isFlagpOn)
    {
        print_polygon_perimeter(polygonToPrint);
    }
    if(isFlagaOn)
    {
        print_polygon_area(polygonToPrint);
    }
}

//-------------------------------------------------------
int get_coordinate_from_number(unsigned long long number)
{
	int coordinate=number % 256;
	if(coordinate>127)
	{
		coordinate-=256;
	}
	return coordinate;
}

//-------------------------------------------------------
struct point * get_verticles(enum POLY_TYPE polyType)
{
    unsigned int numOfPoints = get_num_of_points_by_polygon_type(polyType);
	unsigned int numOfLinesToRead = get_num_of_numbers_to_read_by_polygon_type(polyType);
	struct point * verticles = malloc(sizeof(struct point) * numOfPoints);
	int numOfPointsReaden=0;
	for(int i = 0; i < numOfLinesToRead; i++)
    {
		unsigned long long number;
        scanf("%llX", &number);
		for (int j = 0; (numOfPointsReaden < numOfPoints) && (j < 4); j++, numOfPointsReaden++)
		{
			struct point newPoint;
			newPoint.x = get_coordinate_from_number(number);
			number = number / 256;
			newPoint.y = get_coordinate_from_number(number);
			number = number / 256;
			verticles[numOfPointsReaden] = newPoint;
		}
    }

    return verticles;   
}

//-------------------------------------------------------
struct polygon * copy_polygon(struct polygon polygonOfNewNode)
{
    struct polygon * newPolygon = (struct polygon*)malloc(sizeof(struct polygon));
    newPolygon->poly_type=polygonOfNewNode.poly_type;
    struct point * verticales = polygonOfNewNode.vertices;
    int verticalesSize = get_num_of_points_by_polygon_type(polygonOfNewNode.poly_type);
    struct point * newVericals = malloc(sizeof(struct point) * verticalesSize);

    for(int i=0; i < verticalesSize; i++)
    {
        newVericals[i]=verticales[i];
    }

    newPolygon->vertices = newVericals;

    return newPolygon;
}

//-------------------------------------------------------
void prog()
{
	struct LinkedList linkedList = create_empty_linked_list();
    int isFlagNOn = FALSE;
    int isFlagLOn = FALSE;
    enum WHOM_TO_OUTPUT whomToOutput;
    int isFlagdOn = FALSE;
    int isFlagpOn = FALSE;
    int isFlagaOn = FALSE;
    enum POLY_TYPE polyType;
    struct polygon newPolygon;

    while(!isFlagLOn)
    {
        isFlagNOn = FALSE; isFlagLOn = FALSE; isFlagdOn = FALSE; isFlagpOn = FALSE; isFlagaOn = FALSE; 

        get_instruction_line(&isFlagNOn, &isFlagLOn, &whomToOutput, &isFlagdOn, &isFlagpOn, &isFlagaOn, &polyType);

        if(isFlagNOn)
        {
            newPolygon.poly_type=polyType;
            newPolygon.vertices = get_verticles(polyType);

            add_data_to_linked_list(&linkedList, newPolygon);
        }
        switch(whomToOutput)
        {
            case(CURRENT):
            {
               print_poloygon(isFlagdOn, isFlagpOn, isFlagaOn, newPolygon);
               break;
            }
            case(ALL_POLY):
            {
                struct Node* currNode = linkedList.head;
                 while(currNode != NULL)
                {
                    print_poloygon(isFlagdOn, isFlagpOn, isFlagaOn, *(currNode->poly));
                    currNode=currNode->next;
                }
                break;
            }
			case(NONE):
			{
				break;
			}
         }
		free(newPolygon.vertices);
  }
	free_list(&linkedList);
}

//-------------------------------------------------------
void free_polygon_pointer(struct polygon* poly)
{
    free(poly->vertices);
    free(poly);
}

//-------------------------------------------------------
void free_polygon(struct polygon poly)
{
	free(poly.vertices);
}

//-------------------------------------------------------
int main()
{
    prog();
}
