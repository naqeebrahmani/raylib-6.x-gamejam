#include <iostream>
#include <raylib.h>
#include <cmath>


Color colours[] = {RED, GREEN, BLUE};


Color currentcolour = colours[0];

Color usercolour = {0,0,0,255};

std::string usercolourred;


class TextBox{
    private:
        float x;
        float y;
        std::string title;
        float width;
        float height;


    public:

        TextBox(float x, float y, std::string title, float width, float height){

        }


        void TakeInputAndDisplay(std::string &inputtext, char title[], float x, float y, float width, float height){

        DrawRectangle(x, y, width, height, WHITE);
        DrawText(title, x + 10, y + 10, 20, BLACK);

        auto key = GetCharPressed();

        if (key!= 0){
            std::cout << (char)key << "\n";
        }

        }




}

void TakeInputAndDisplay(std::string &inputtext, char title[], float x, float y, float width, float height){

    DrawRectangle(x, y, width, height, WHITE);
    DrawText(title, x + 10, y + 10, 20, BLACK);

    auto key = GetCharPressed();

    if (key!= 0){
        std::cout << (char)key << "\n";
    }



}



int HexadecimalToDecimal(char hexa[], int arraysize){

    int num = 0;
    int temp_num;
    int size = arraysize;

    for(int i = 0; i < size; i++){
        if(isdigit(hexa[i])==false){
            switch(hexa[i]){
                case 'A':
                    temp_num = 10;
                    break;
                case 'B':
                    temp_num = 11;
                    break;
                case 'C':
                    temp_num = 12;
                    break;
                case 'D':
                    temp_num = 13;
                    break;
                case 'E':
                    temp_num = 14;
                    break;
                case 'F':
                    temp_num = 15;
                    break;
            }

            num += temp_num * pow(16, size-i-1); //subtracting 1 because i starts as 0
        
        }
        else{

            num += (hexa[i] - '0') * pow(16, size-i-1); //subtracted the char 0 because of their ascii values 
        }                                               //because 0 doesnt have the ascii value 0 but something like 48 i think

    }

    return num;

}






int main(){

    InitWindow(720, 720, "Match And Merge");
    SetTargetFPS(60);

    std::cout << HexadecimalToDecimal("F0", 2);


    while(!WindowShouldClose()){


        

        BeginDrawing();
        
        ClearBackground(currentcolour);

        DrawRectangle(260, 100, 200, 200, usercolour);

        DrawRectangle(0, 400, 720, 320,  {0,0,0,155});

        TakeInputAndDisplay(usercolourred, "RED: ", 100, 500, 100, 30);


        EndDrawing();
    }








    return 0;
}