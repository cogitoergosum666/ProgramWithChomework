#pragma once
void SortArray2D(int*** input);
int cmp(const void* a, const void* b);
void SortArray1D(int** input);
void SortStructArray(DATAITEM** input);
int cmpStruct(const void* a, const void* b);
int cmpFinger(const void* a, const void* b);
void SortFingerArray(DATAITEM*** input);
int cmpLink(const void* a, const void* b);
void SortLink(LINKNODE** input);