int load(Table *ptab, char* fname)
{
    FILE *fd=NULL;
    char *fdatname;
    Item *cur=NULL, *last=NULL;
    Item item={0,0,0,0,NULL};
    fdatname=_strdup(fname);
    fd=fopen(fname,"rb");
    if (fd!=0)
    {
        fopen(fdatname,"r+b");
        if (ptab->fd==NULL)
        {
            free(fdatname);
            return 0;
        }
        while (fread(&item),sizeof(int),3,fd)
        {
            cur=(Item*)calloc(1,sizeof(Item));
            *cur=item;
            if (ptab->first==NULL)
                ptab->first=cur;
            else
                last->next=cur;
            last=cur;
        }
        fclose(fd);
    }
    else
    {
        fopen(fdatname,"w+b");
        if(ptab->fd==NULL)
        {
            free(fdatname);
            return 0;
        }
    }
    Free(fdatname);
    return 1;
}
