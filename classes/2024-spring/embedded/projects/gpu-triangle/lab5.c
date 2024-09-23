#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#include "libfio.c"

#define COLS 256
#define ROWS 256
#define INVISIBLE -9999999

typedef struct vertex_node_ {
  float x;
  float y;
  float z;
} vertex_node;

typedef struct face_node_ {
  int vert1;
  int vert2;
  int vert3;
} face_node;

typedef struct plane_node_ {
  vertex_node* ABC;
  float D_plane;
} plane_node;

typedef struct pixel_node_ {
  vertex_node* vert_coord;
  float n;
  float d;
  vertex_node* intersect;
  int color;
} pixel_node;

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

int line_to_buf(FILE* file, char* buffer)
{
    int bytes_read = 0;

    while(fread(buffer, 1, sizeof(char), file) > 0)
    {
      if(*buffer == '\n')
        break;

      buffer++;
    }

    return bytes_read;
}

int count_from_line(char* line, int offset)
{
  int digits = 0;
  char* str_buf = calloc(16, sizeof(char));

  while (*(line + offset + digits) != '\n')
  {
    digits++;
  }


  memcpy(str_buf, line + offset, digits);

  return atoi(str_buf);

}

vertex_node* vert_str_int(char* string_buffer)
{
  vertex_node* node = calloc(1, sizeof(vertex_node));

  node->x = strtod(string_buffer, NULL);

  while(*string_buffer != ' ') string_buffer++;

  node->y = strtod(string_buffer, NULL);
  string_buffer++;

  while(*string_buffer != ' ') string_buffer++;

  node->z = strtod(string_buffer, NULL);

  return node;

}

face_node* str_to_face(char* string_buffer)
{
  face_node* node = calloc(1, sizeof(face_node));

  while(*string_buffer != ' ') string_buffer++;
  string_buffer++;

  node->vert1 = atoi(string_buffer);

  while(*string_buffer != ' ') string_buffer++;
  string_buffer++;

  node->vert2 = atoi(string_buffer);

  while(*string_buffer != ' ') string_buffer++;
  string_buffer++;

  node->vert3 = atoi(string_buffer);

  return node;
}

plane_node* face_to_plane(face_node* face, vertex_node** vertex_list)
{
  plane_node* node = calloc(1, sizeof(face_node));

  node->ABC = vector_cross(vector_sub(vertex_list[face->vert2], vertex_list[face->vert1]), vector_sub(vertex_list[face->vert3], vertex_list[face->vert1]));
  node->D_plane = vector_dot(mult_scal_vect(-1, node->ABC), vertex_list[face->vert1]);

  return node;
}

int detect_intersection(face_node* face, vertex_node** vertex_list, vertex_node* intersect, float ndz)
{
  vertex_node* v0 = vertex_list[face->vert1];
  vertex_node* v1 = vertex_list[face->vert2];
  vertex_node* v2 = vertex_list[face->vert3];

  float dot1 = vector_dot(vector_cross(vector_sub(v2, v0), vector_sub(v1, v0)), vector_cross(vector_sub(intersect, v0), vector_sub(v1, v0)));
  float dot2 = vector_dot(vector_cross(vector_sub(v0, v1), vector_sub(v2, v1)), vector_cross(vector_sub(intersect, v1), vector_sub(v2, v1)));
  float dot3 = vector_dot(vector_cross(vector_sub(v1, v2), vector_sub(v0, v2)), vector_cross(vector_sub(intersect, v2), vector_sub(v0, v2)));

  if (dot1 < 0 || dot2 < 0 || dot3 < 0 || ndz > 0)
    return 0;
  else 
    return 1;
}

void rotate_x(vertex_node* v, float x)
{
  vertex_node* result = calloc(1, sizeof(vertex_node));

  result->x = v->x;
  result->y = v->y * cos(x) + v->z * sin(x);
  result->z = v->y * -sin(x) + v->z * cos(x);

  memcpy(v, result, sizeof(vertex_node));
  free(result);
}

void rotate_y(vertex_node* v, float y)
{
  vertex_node* result = calloc(1, sizeof(vertex_node));

  result->x = v->x * cos(y) + v->z * -sin(y);
  result->y = v->y;
  result->z = v->x * sin(y) + v->z * cos(y);

  memcpy(v, result, sizeof(vertex_node));
  free(result);
}

void rotate_z(vertex_node* v, float z)
{
  vertex_node* result = calloc(1, sizeof(vertex_node));

  result->x = v->x * cos(z) + v->y * sin(z);
  result->y = v->x * -sin(z) + v->y * cos(z);
  result->z = v->z;

  memcpy(v, result, sizeof(vertex_node));
  free(result);
}

int main(int argc, char* argv[])
{
    char* string_buffer = calloc(256, sizeof(char));
    int line = 1;
    int num_faces;
    int num_vertices;
    float max_extent;
    float a;

    vertex_node** vertex_list;
    face_node** face_list;
    pixel_node* pixel_list[ROWS][COLS];
    float zbuffer[ROWS][COLS];
    plane_node** plane_list;

    vertex_node* max_vert = calloc(1, sizeof(vertex_node));
    vertex_node* min_vert = calloc(1, sizeof(vertex_node));
    vertex_node* center = calloc(1, sizeof(vertex_node));
    vertex_node* camera = calloc(1, sizeof(vertex_node));
    vertex_node* up = calloc(1, sizeof(vertex_node));
    vertex_node* left = calloc(1, sizeof(vertex_node));
    vertex_node* right = calloc(1, sizeof(vertex_node));
    vertex_node* top = calloc(1, sizeof(vertex_node));
    vertex_node* bottom = calloc(1, sizeof(vertex_node));
    vertex_node* topleft = calloc(1, sizeof(vertex_node));

    if(argc != 6)
    {
         printf("Usage: %s <input_file> <output_file> <x> <y> <z>\n", argv[0]);
         exit(1);
    }

    // fio* input_file = create_fio(argv[1], "r", 1);
    // fio* output_file = create_fio(argv[2], "w", 1);

    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "w");

    if(input == NULL || output == NULL)
      {
        printf("bad input file\n");
        exit(1);
      }

    while(line <= 9)
      {
        line_to_buf(input, string_buffer);

        if(line == 3)
          num_vertices = count_from_line(string_buffer, 15);
        else if (line == 7)
          num_faces = count_from_line(string_buffer, 13);

        line++;
      }

    printf("Number of vertices: %d\n", num_vertices);
    printf("Number of faces: %d\n", num_faces);

    vertex_list = calloc(num_vertices, sizeof(vertex_node*));
    face_list = calloc(num_faces, sizeof(face_node*));

    for(int i = 0; i < num_vertices; i++)
    {
      line_to_buf(input, string_buffer);
      vertex_list[i] = vert_str_int(string_buffer);
    }

    for(int i = 0; i < num_faces; i++)
    {
      line_to_buf(input, string_buffer);
      face_list[i] = str_to_face(string_buffer);
    }

    // obtain bounding box info

    max_vert->x = 0; max_vert->y = 0; max_vert->z = 0;
    min_vert->x = 0; min_vert->y = 0; min_vert->z = 0;

    // find min and max vertices
    for(int i = 0; i < num_vertices; i++)
    {
      // max
      if (vertex_list[i]->x > max_vert->x) max_vert->x = vertex_list[i]->x;
      if (vertex_list[i]->y > max_vert->y) max_vert->y = vertex_list[i]->y;
      if (vertex_list[i]->z > max_vert->z) max_vert->z = vertex_list[i]->z;

      // min
      if (vertex_list[i]->x < min_vert->x) min_vert->x = vertex_list[i]->x;
      if (vertex_list[i]->y < min_vert->y) min_vert->y = vertex_list[i]->y;
      if (vertex_list[i]->z < min_vert->z) min_vert->z = vertex_list[i]->z;
    }

    // center
    center->x = (max_vert->x - min_vert->x) / 2 + min_vert->x;
    center->y = (max_vert->y - min_vert->y) / 2 + min_vert->y;
    center->z = (max_vert->z - min_vert->z) / 2 + min_vert->z;

    // max extent
    vertex_node* max_minus_min = calloc(1, sizeof(vertex_node));

    max_minus_min->x = max_vert->x - min_vert->x;
    max_minus_min->y = max_vert->y - min_vert->y;
    max_minus_min->z = max_vert->z - min_vert->z;

    if (max_minus_min->x >= max_minus_min->y && max_minus_min->x >= max_minus_min->z) // x is biggest
      max_extent = max_minus_min->x;
    else if (max_minus_min->y >= max_minus_min->x && max_minus_min->y >= max_minus_min->z)
      max_extent = max_minus_min->y;
    else if (max_minus_min->z >= max_minus_min->x && max_minus_min->z >= max_minus_min->y)
      max_extent = max_minus_min->z;
    else
      {
        printf("Error calculating max extent\n");
        exit(1);
      }

    // set defaults of camera and up
    camera->x = 1; camera->y = 0; camera->z = 0;
    up->x = 0; up->y = 0; up->z = 1;

    // rotate camera vector
    rotate_x(camera, atoi(argv[3]) * M_PI / 180);
    rotate_y(camera, atoi(argv[4]) * M_PI / 180);
    rotate_z(camera, atoi(argv[5]) * M_PI / 180);

    // rotate up vector
    rotate_x(up, atoi(argv[3]) * M_PI / 180);
    rotate_y(up, atoi(argv[4]) * M_PI / 180);
    rotate_z(up, atoi(argv[5]) * M_PI / 180);

    // move and scale camera
    camera = vector_add(mult_scal_vect(1.5 * max_extent, camera), center);

    // determine 3D bounding coordinates

    left = vector_cross(up, vector_sub(center, camera));
    a = vector_mag(left);
    left = vector_add(mult_scal_vect(max_extent / (2 * a), left), center);
    right = vector_cross(vector_sub(center, camera), up);
    right = vector_add(mult_scal_vect(max_extent / (2 * a), right), center);
    top = vector_add(mult_scal_vect(max_extent / 2, up), center);
    bottom = vector_add(mult_scal_vect(-max_extent / 2, up), center);
    topleft = vector_add(mult_scal_vect(max_extent / 2, up), left);
    
    plane_list = calloc(num_faces, sizeof(plane_node*));

    // find plane equations for all triangles (faces)
    for(int i = 0; i < num_faces; i++)
      plane_list[i] = face_to_plane(face_list[i], vertex_list);

    vertex_node* bot_min_top = vector_sub(bottom, top);
    vertex_node* r_min_l = vector_sub(right, left);

    for(int r = 0; r < ROWS; r++)
      for(int c = 0; c < COLS; c++)
      {
        // create image vector coords for each pixel
        pixel_list[r][c] = calloc(1, sizeof(pixel_node));
        
        vertex_node* tmp1 = vector_add(topleft, mult_scal_vect(c / (COLS - 1), r_min_l));
        vertex_node* tmp2 = mult_scal_vect(r / (ROWS - 1), bot_min_top);
        pixel_list[r][c]->vert_coord = vector_add(tmp1, tmp2);
        free(tmp1);
        free(tmp2);


        for(int i = 0; i < num_faces; i++)
        {
          pixel_list[r][c]->n = vector_dot(mult_scal_vect(-1, plane_list[i]->ABC), camera) - plane_list[i]->D_plane;
          pixel_list[r][c]->d = vector_dot(plane_list[i]->ABC, vector_sub(pixel_list[r][c]->vert_coord, camera));

          // set up z buffer
          if(pixel_list[r][c]->n / pixel_list[r][c]->d < 999999)
            zbuffer[r][c] = pixel_list[r][c]->n / pixel_list[r][c]->d ;
          else 
            zbuffer[r][c] = 999999;

          vertex_node* tmp1 = vector_sub(pixel_list[r][c]->vert_coord, camera);
          pixel_list[r][c]->intersect = vector_add(camera, mult_scal_vect(pixel_list[r][c]->n / pixel_list[r][c]->d, tmp1));
          free(tmp1);

          if(detect_intersection(face_list[i], vertex_list, pixel_list[r][c]->intersect, pixel_list[r][c]->n / pixel_list[r][c]->d - zbuffer[r][c]))
            {
              printf("Intersection detected at triangle %d\n", i);
              pixel_list[r][c]->color = 155 + (i % 100);
              break;
            }
        }

      }
    
    // write ppm file 
    fprintf(output, "P5 256 256 255\n");

    for(int r = 0; r < ROWS; r++)
      for(int c = 0; c < COLS; c++)
        fwrite(&pixel_list[r][c]->color, 1, sizeof(char), output);
    

}
