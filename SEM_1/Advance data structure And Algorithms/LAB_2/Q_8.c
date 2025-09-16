#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool is_vowel[256] ={false};

bool vowel_lookup(){
    is_vowel['a'] = true;
    is_vowel['A'] = true;
    is_vowel['e'] = true;
    is_vowel['E'] = true;
    is_vowel['i'] = true;
    is_vowel['I'] = true;
    is_vowel['o'] = true;
    is_vowel['O'] = true;
    is_vowel['u'] = true;
    is_vowel['U'] = true;
}


int main(){
    char a[50]={"HELLO World Harsh aeee iou"};
    int i=0,c=0;

    while(i<50){
        if(a[i]=='a'|| a[i]=='A'||a[i]=='e'||a[i]=='E'||a[i]=='i'||a[i]=='I'||a[i]=='o'||a[i]=='O'||a[i]=='u'||a[i]=='U')
            {
                c++;
            }
        i++;
    }
    printf("no. of vowels ==> %d",c);
 for(int j=0 ; j<50 ; j++){
        if(is_vowel[a[j]]){
            c++;
        }
    }
    printf("\nno. of vowels ==> %d",c);

}