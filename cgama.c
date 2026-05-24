#include <stdio.h>
#include <unistd.h>

int main() {
    int me = 10;
    int teacher = 3;
    int dir = 1;
    char c;

    printf("Escape the monster\n");
    printf(" a left d right q exit\n\n");

    while (1) {
        printf("\033[H\033[J");
        for(int i=0;i<20;i++){
            if(i==me) printf("😎");
            else if(i==teacher) printf("🧟‍♀️");
            else printf("·");
        }
        printf("\n");

        teacher += dir;
        if(teacher<=0||teacher>=19) dir *= -1;
        if(read(0,&c,1)>0){
            if(c=='a'&&me>0) me--;
            if(c=='d'&&me<19) me++;
            if(c=='q') break;
        }

        if(me==teacher){
            printf("Caught the monster.\n");
            break;
        }

        usleep(150000);
    }
    return 0;
}
    
