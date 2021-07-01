 #include<conio.h>
    #include<dos.h>
    #define MEMORY_SIZE 3999  // 2 bytes for each character  total char 2000

    void main(){

    char far *vidmem = 0xB8000000; // video memory address row & column zero
    int i,o=0;

    for(i=0;i<=MEMORY_SIZE;i+=2){
        if (o%2==0)
            *( vidmem + i) = 'A';
        else
            *( vidmem + i) = 'a';
    o++;
    }

    while(!kbhit()){

        for(i=0;i<=MEMORY_SIZE;i+=2){       
            if(*( vidmem +i) == 'A')
                *( vidmem + i) = 'a';
            else
                *( vidmem + i) = 'A';
        }
        delay(200); // wait for 200 ms
    }

    }
