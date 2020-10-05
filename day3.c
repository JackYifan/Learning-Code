#ifndef _PSTRING_H_
#define _PSTRING_H_

typedef struct {
	int length;
	char content[];
} PString;

//	create an object of PString with its content as s
PString* psCreate(const char* s);

//	release the object ps
void psFree(PString *ps);

//	print ps
void psPrint(const PString* ps);

//	read a word, which is seperated by space
PString* psReadWord();

//	read a line
PString* psReadLine();

//	returns the number of characters in the PString object, i.e. the length of the string
int psLength(const PString* ps);

//	clone a PString object
//	return the new one
PString* psClone(const PString *ps);

//	concat two PString into a new one
//	return the new one
PString* psConcat(const PString* ps1, const PString* ps2);

//	compare two PString objects
//	returns -1 if ps1 is < ps2; 0 if ps1 == ps2; 1 if ps1 > ps2
int psCompare(const PString* ps1, const PString* ps2);

//	find the location of ch in the ps
//	return the location of the first ch in ps, -1 if ch is not in ps
int psFindChar(const PString* ps, char ch);

//	find the first location of ps2 in ps1
//	return the location, NULL is not found
int psFindString(const PString* ps1, const PString* ps2);

//	get rid of the space at both end
//	return the new created string
PString* psTrim(const PString* ps);

//	turn every character in ps into lower case
//	return the new lowered string
PString* psLower(const PString* ps);

//	turn every character in ps into upper case
//	return the new uppered string
PString* psUpper(const PString* ps);

//	take a subset of the string ps. The subset is from begin to end.
//	For example, psSubstring(psCreate(“0123456789”), 3,5) returns a PString as “345”
//	return the new extracted string
PString* psSubstring(const PString* ps, int begin, int end);

//	replace every ch1 in ps with ch2
//	return the replaced string
PString* psReplace(const PString* ps, char ch1, char ch2);

//	return the char at the index
char psChar(const PString* ps, int index);

//	return 1 if the ps1 begins with ps2, 0 otherwise
int psBeginWith(const PString* ps1, const PString* ps2);

#endif
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
//	create an object of PString with its content as s
PString* psCreate(const char* s){
    int len=strlen(s);
    PString*p=(PString*)malloc(sizeof(int)+len*sizeof(char));
    for(int i=0;i<len;i++){
        p->content[i]=s[i];
    }
    p->length=len;
    return p;
}

//	release the object ps
void psFree(PString *ps){
    free(ps);
}

//	print ps
void psPrint(const PString* ps){
    for(int i=0;i<ps->length;i++){
        printf("%c",ps->content[i]);
    }
    printf("\n");
}

//	read a word, which is seperated by space
PString* psReadWord(){
    char c;
    PString*p=(PString*)malloc(sizeof(int));
    int i=0;
    while((c=getchar())!=' '){
        p=(PString*)realloc(p,sizeof(int)+(i+1)*sizeof(char));
        p->content[i++]=c;
    }
    p->length=i;
    return p;
}

//	read a line
PString* psReadLine(){
    char c;
    PString*p=(PString*)malloc(sizeof(int));
    int i=0;
    while((c=getchar())!='\n'){
        p=(PString*)realloc(p,sizeof(int)+(i+1)*sizeof(char));
        p->content[i++]=c;
    }
    p->length=i;
    return p;
}

//	returns the number of characters in the PString object, i.e. the length of the string
int psLength(const PString* ps){
    return ps->length;
}

//	clone a PString object
//	return the new one
PString* psClone(const PString *ps){
    int len=ps->length;
    PString*p=(PString*)malloc(sizeof(int)+len*sizeof(char));
    for(int i=0;i<len;i++){
        p->content[i]=ps->content[i];
    }
    p->length=len;
    return p;
}

//	concat two PString into a new one
//	return the new one
PString* psConcat(const PString* ps1, const PString* ps2){
    int len1=ps1->length;
    int len2=ps2->length;
    PString*p=(PString*)malloc(sizeof(int)+(len1+len2)*sizeof(char));
    int i=0;
    for(int j=0;j<len1;j++){
        p->content[i++]=ps1->content[j];
    }
    for(int j=0;j<len2;j++){
        p->content[i++]=ps2->content[j];
    }
    p->length=len1+len2;
    return p;
}

//	compare two PString objects
//	returns -1 if ps1 is < ps2; 0 if ps1 == ps2; 1 if ps1 > ps2
int psCompare(const PString* ps1, const PString* ps2){
    int len1=ps1->length;
    int len2=ps2->length;
    int i=0,j=0;
    for(;i<len1&&j<len2;i++,j++){
        if(ps1->content[i]>ps2->content[j]) return 1;
        else if(ps1->content[i]<ps2->content[j]) return -1;
    }
    if(i!=len1) return 1;
    else if(j!=len2) return -1;
    else return 0; 
}

//	find the location of ch in the ps
//	return the location of the first ch in ps, -1 if ch is not in ps
int psFindChar(const PString* ps, char ch){
    int len=ps->length;
    for(int i=0;i<len;i++){
        if(ps->content[i]==ch) return i;
    }
    return -1;
}

//	find the first location of ps2 in ps1
//	return the location, NULL is not found
int psFindString(const PString* ps1, const PString* ps2){
    int len1=ps1->length;
    int len2=ps2->length;
    int i=0,j=0;
    for(i=0;i<len1;i++){
        int t=i;
        for(j=0;j<len2;j++,i++){
            if(ps1->content[i]!=ps2->content[j]){
                i=t;j=0;break;
            }
        }
        if(j==len2) return t;
    }
    return NULL;
}

//	get rid of the space at both end
//	return the new created string
PString* psTrim(const PString* ps){
    int len=ps->length;
    int i=0,j=0,k=len-1;
    for(j=0;j<len;j++){
        if(ps->content[j]!=' ') break;
    }
    printf("%d ",j);
    for(k=len-1;k>=0;k--){
        if(ps->content[k]!=' ') break;
    }
    printf("%d",k);
    int len2=k-j+1;
    PString*p=(PString*)malloc(sizeof(int)+len2*sizeof(char));
    p->length=len2;
    int index=0;
    for(int i=j;i<=k;i++){
        p->content[index++]=ps->content[i];
    }
    return p;
}

//	turn every character in ps into lower case
//	return the new lowered string
PString* psLower(const PString* ps){
    int len=ps->length;
    PString*p=(PString*)malloc(sizeof(int)+len*sizeof(char));
    for(int i=0;i<len;i++){
        if(ps->content[i]>='A'&&ps->content[i]<='Z') p->content[i]=ps->content[i]-'A'+'a';
        else p->content[i]=ps->content[i];
    }
    p->length=ps->length;
    return p;
}

//	turn every character in ps into upper case
//	return the new uppered string
PString* psUpper(const PString* ps){
    int len=ps->length;
    PString*p=(PString*)malloc(sizeof(int)+len*sizeof(char));
    for(int i=0;i<len;i++){
        if(ps->content[i]>='a'&&ps->content[i]<='z') p->content[i]=ps->content[i]-'a'+'Z';
        else p->content[i]=ps->content[i];
    }
    p->length=ps->length;
    return p;
}

//	take a subset of the string ps. The subset is from begin to end.
//	For example, psSubstring(psCreate(“0123456789”), 3,5) returns a PString as “345”
//	return the new extracted string
PString* psSubstring(const PString* ps, int begin, int end){
    int len=end-begin;
    PString*p=(PString*)malloc(sizeof(int)+len*sizeof(char));
    p->length=len;
    int i=0,j;
    for(j=begin;j<end;j++){
        p->content[i++]=ps->content[j];
    }
    return p;
}

//	replace every ch1 in ps with ch2
//	return the replaced string
PString* psReplace(const PString* ps, char ch1, char ch2){
    int len=ps->length;
    PString*p=(PString*)malloc(sizeof(int)+len*sizeof(char));
    p->length=len;
    int i=0,j;
    for(j=0;j<len;j++){
        if(ps->content[j]==ch1) p->content[i++]=ch2;
        else p->content[i++]=ps->content[j];
    }
    return p;
    
}

//	return the char at the index
char psChar(const PString* ps, int index){
    return ps->content[index];
}

//	return 1 if the ps1 begins with ps2, 0 otherwise
int psBeginWith(const PString* ps1, const PString* ps2){
    int len1=ps1->length;
    int len2=ps2->length;
    if(len1<len2) return 0;
    else{
        for(int i=0;i<len2;i++){
            if(ps1->content[i]!=ps2->content[i]) return 0;
        }
    }
    return 1;
}
#include <stdio.h>
#include <string.h>

int main(int argc, char*argv[])
{
	FILE* fp = fopen(argv[1], "w");

	//	create && free
	int fs = 0;
	PString *s = psCreate("Hello");
	if ( psLength(s) == 5 ) {
		fs++;
	}
	psFree(s);
	fprintf(fp, "#01-%d\n", fs);
		
	//	readword & readline & print
	PString *s1 = psReadWord();
	psPrint(s1);
	PString *s2 = psCreate("Zhejiang");
	if ( psCompare(s1, s2) == 0 ) { 
		fs++;
	}
	psFree(s1);
	psFree(s2);
	fprintf(fp, "#02-%d\n", fs);

	//	clone 
	s1 = psCreate("aa");
	s2 = psClone(s1);
	if ( psCompare(s1, s2) == 0 ) { 
		fs++;	//10
	}
	psFree(s1);
	psFree(s2);
	fprintf(fp, "#03-%d\n", fs);
	
	//	concat
	s1 = psCreate("hello");
	s2 = psCreate("world");
	PString* s3 = psCreate("helloworld");
	PString* s4 = psConcat(s1, s2);
	if ( psCompare(s3, s4) == 0 ) {
		fs++;
	}
	psFree(s1);
	psFree(s4);
	fprintf(fp, "#04-%d\n", fs);
	
	//	compare
	s1 = psCreate("abc");
	s2 = psCreate("abd");
	if ( psCompare(s1, s2) <0 ) {
		fs++;
	}
	psFree(s1);
	psFree(s2);
	fprintf(fp, "#05-%d\n", fs);
	
	//	findchar
	s1 = psCreate("abc");
	if ( psFindChar(s1, 'b') == 1 ) {
		fs++;
	}
	psFree(s1);
	fprintf(fp, "#06-%d\n", fs);
	
	//	findstring
	s1 = psCreate("abcdefg");
	s2 = psCreate("de");
	if ( psFindString(s1, s2) ==3 ) {
		fs++;	
	}
	psFree(s1);
	psFree(s2);
	fprintf(fp, "#07-%d\n", fs);
	
	//	trim
	s1 = psCreate("  zhejiang");
	s2 = psCreate("zhejiang");
	s3 = psTrim(s1);
    psPrint(s3);
	if ( psCompare(s3, s2) ==0 ) {
		fs++;	
	}
    printf("************\n");
    printf("%d",psCompare(s3, s2));
    printf("*************\n");
	psFree(s1);
	psFree(s2);
	psFree(s3);
	fprintf(fp, "#08-%d\n", fs);
	
	//	lower & upper
	s1 = psCreate("ZheJiang");
	s2 = psCreate("zhejiang");
	s3 = psLower(s1);
	if ( psCompare(s3, s2) ==0 ) {
		fs++;	
	}
	psFree(s1);
	psFree(s2);
	psFree(s3);
	fprintf(fp, "#09-%d\n", fs);
	
	//	substring
	s1 = psCreate("zhejiang");
	s2 = psCreate("jian");
	s3 = psSubstring(s1, 3,7);
    printf("*****\n");
    psPrint(s3);
	if ( psCompare(s3, s2) ==0 ) {
		fs++;	
	}
	psFree(s1);
	psFree(s2);
	psFree(s3);
	fprintf(fp, "#0A-%d\n", fs);
	
	//	replace
	s1 = psCreate("zhejieng");
	s2 = psCreate("zhajiang");
	s3 = psReplace(s1, 'e', 'a');
	if ( psCompare(s3, s2) ==0 ) {
		fs++;	
	}
	psFree(s1);
	psFree(s2);
	psFree(s3);
	fprintf(fp, "#0B-%d\n", fs);

	//	char
	s1 = psCreate("zhejieng");
	if ( psChar(s1, 1) =='h' ) {
		fs++;	
	}
	psFree(s1);
	fprintf(fp, "#0C-%d\n", fs);
	
	//	beginwith
	s1 = psCreate("zhejiang");
	s2 = psCreate("zhe");
	if ( psBeginWith(s1, s2) ==1 ) {
		fs++;	
	}
	psFree(s2);
	psFree(s1);
	fprintf(fp, "#0B-%d\n", fs);
	
	//	result
	fprintf(fp, "%d\n", fs);
	fclose(fp);
}
