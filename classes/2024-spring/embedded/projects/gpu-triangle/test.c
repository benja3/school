#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

typedef struct vertex_node_ {
  float x;
  float y;
  float z;
} vertex_node;

vertex_node* vector_add(vertex_node* v1, vertex_node* v2)
{
  vertex_node* result = calloc(1, sizeof(vertex_node));

  result->x = v1->x + v2->x;
  result->y = v1->y + v2->y;
  result->z = v1->z + v2->z;

  return result;

}

vertex_node* vector_sub(vertex_node* v1, vertex_node* v2)
{
  vertex_node* result = calloc(1, sizeof(vertex_node));

  result->x = v1->x - v2->x;
  result->y = v1->y - v2->y;
  result->z = v1->z - v2->z;

  return result;
}

vertex_node* mult_scal_vect(int scal, vertex_node* vect)
{
  vertex_node* result = calloc(1, sizeof(vertex_node));

  result->x = vect->x * scal;
  result->y = vect->y * scal;
  result->z = vect->z * scal;

  return result;
}

float vector_dot(vertex_node* v1, vertex_node* v2)
{
  return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

vertex_node* vector_cross(vertex_node* v1, vertex_node* v2)
{
  vertex_node* result = calloc(1, sizeof(vertex_node));

  result->x = v1->y * v2->z - v2->y * v1->z;
  result->y = v2->x * v1->z - v1->x * v2->z;
  result->z = v1->x * v2->y - v2->x * v1->y;

  return result;
}

float vector_mag(vertex_node* vect)
{
  return sqrt((vect->x * vect->x) + (vect->y * vect->y) + (vect->z * vect->z));
}

int main()
{
    char* string = "1.3324 232.33 9.2342344";
    assert(*(string + 6) == ' ');

    float f = strtod(string, NULL);
    printf("%f\n", f);

    char* face = "234 44 22";
    int d = atoi(face);
    printf("%d\n", d);

    vertex_node* v1 = calloc(1, sizeof(vertex_node));
    vertex_node* v2 = calloc(1, sizeof(vertex_node));

    v1->x = 1; v1->y = 2; v1->z = 3;
    v2->x = 4; v2->y = 5; v2->z = 6;

    vertex_node* result;
    float result_i;

    result = vector_add(v1,v2);
    result = vector_add(result, v1);
    result = vector_sub(v2,v1);
    result = mult_scal_vect(2, v2);
    result = vector_cross(v1, v2);
    result_i = vector_dot(v1,v2);
    result_i = vector_mag(v1);
    

}