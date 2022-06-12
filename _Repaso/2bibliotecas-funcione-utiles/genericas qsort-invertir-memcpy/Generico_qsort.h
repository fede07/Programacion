#ifndef GENERICO_QSORT_H_INCLUDED
#define GENERICO_QSORT_H_INCLUDED

typedef struct{
int dni;
char apyn[20];
float sueldo;
}t_emp;

typedef int (*compar) (const void *, const void*);
void* buscarMenor(void *base, size_t nitems, size_t, compar);
void qsort2(void *base, size_t nitems, size_t, compar);

int comparInt (const void *elem1, const void *elem2);
int comparChar (const void *elem1, const void *elem2);
int comparEmp (const void *elem1, const void *elem2);

void invertirGen (void * dato, size_t tam);
void * memcpy2 (void *, const void *, size_t);

#endif // GENERICO_QSORT_H_INCLUDED
