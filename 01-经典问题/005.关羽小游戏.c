#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct player{
    int x;
    int y;
    char appearance;
    int speed;
    int health;
};

void init_map(char * pmap, int height, int width){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(i == 0 || i == height - 1){
                *(pmap + i * width + j) = '-';
            }else if(j == 0 || j == width - 1){
                *(pmap + i * width + j) = '|';
            }else{
                *(pmap + i * width + j) = ' ';
            }
        }
    }
}

void draw_map(char * pmap, int height, int width){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            printf("%c", *(pmap + i * width + j));
        }
        printf("\n");
    }
}

void place_player(char * pmap, int height, int width, struct player * pp){
    init_map(pmap, height, width);
    int x = pp->x;
    int y = pp->y;
    *(pmap + y * width + x) = pp->appearance;
}

int main()
{
    char my_map[25][50];
    init_map((char *)my_map, 25, 50);
    //draw_map((char *)my_map, 25, 50);
    struct player guanyu;
    guanyu.y = 12;
    guanyu.x = 36;
    guanyu.appearance = 'G';
    guanyu.speed = 3;
    guanyu.health = 100;
    place_player((char *)my_map, 25, 50, &guanyu);
    draw_map((char *)my_map, 25, 50);
    /**/
    while(1){
        char c = _getch();
        if(c == 'a'){
            guanyu.x -= guanyu.speed;
        }else if(c == 'd'){
            guanyu.x += guanyu.speed;
        }else if(c == 'w'){
            guanyu.y -= guanyu.speed;
        }else if(c == 's'){
            guanyu.y += guanyu.speed;
        }
        system("cls");
        place_player((char *)my_map, 25, 50, &guanyu);
        draw_map((char *)my_map, 25, 50);
    }

    return 0;
}