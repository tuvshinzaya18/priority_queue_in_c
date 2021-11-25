#ifndef DARR_HEADER
#define DARR_HEADER

typedef struct darray
{
  void ** cells;
  int capacity;
  int size;
} darray;

darray* initialize_darr (int size);
void tidy_darr(darray* array);
int size_darr(darray*);
struct darray* insert_darr (void* value, darray* array);

#endif