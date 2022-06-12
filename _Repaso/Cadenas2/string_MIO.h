#ifndef STRING_MIO_H_INCLUDED
#define STRING_MIO_H_INCLUDED

char* strlwr_mio(char*);
char* strupr_mio(char*);
char* strcpy_mio(char*, const char*);
char* strcat_mio(char*, const char*);
int strcmp_mio(const char*, const char*);
int compararStringIg (const char*, const char*);
unsigned strlen_mio (const char*);
int toUpper_mio(int ch);
int toLower_mio(int ch);
char* strchr_mio(char*, int);
char* strstr_mio(const char *,const char*);
char* strrchr_mio(const char*, int);
void* memcpy_MI(void*, const void*, size_t);

#endif // STRING_MIO_H_INCLUDED
