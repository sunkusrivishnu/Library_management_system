void delbookbyid(books book[], int *nb, int bid);
int validbid(books book[], int bid, int * nb);
int iidpresent(issuer irecord[], int ni, char * i);
int ridpresent(issuer irecord[], char* iid, int * ni);
int available(books book[], int bid, int * nb);