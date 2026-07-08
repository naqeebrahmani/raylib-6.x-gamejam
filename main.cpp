#include <iostream>
#include <raylib.h>
#include <cmath>
#include <vector>





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
        std::string inputtexthex = "";
        std::string inputtextrgb = "";

        bool hex = true;
        


    public:

        TextBox(float x, float y, std::string title, float width, float height){
            this->x = x;
            this->y = y;
            this->title = title;
            this->width = width;
            this->height = height;
        }


        void TakeInputAndDisplay(){

            DrawRectangle(x, y, width, height, WHITE);
            DrawText(title.c_str(), x + 10, y + 10, 20, BLACK);

            DrawRectangle(x +  width + 50, y, width/2, height, BLACK);
            if(hex == true){
                DrawText("hexa", x + width + 50 + 10, y + 5, 20, WHITE);
            }
            else{
                DrawText("RGB", x + width + 50 + 10, y + 5, 20, WHITE);
            }

            if(CheckCollisionPointRec(GetMousePosition(), Rectangle{x +  width + 50, y, width/2, height})){
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    if(hex){
                        hex = false;
                    }
                    else{
                        hex = true;
                    }
                }
            }


            if(CheckCollisionPointRec(GetMousePosition(), Rectangle{x, y, width, height})){

                char key = GetCharPressed();

                

            }
        }

};

 
TextBox textbox1(100, 400, "RED: ", 150, 30);



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

    //for testing
    std::cout << HexadecimalToDecimal("FF", 2);
    ///////////////////////

    while(!WindowShouldClose()){


        

        BeginDrawing();
        
        ClearBackground(currentcolour);

        DrawRectangle(260, 100, 200, 200, usercolour);

        DrawRectangle(0, 400, 720, 320,  {0,0,0,155});

        textbox1.TakeInputAndDisplay();


        EndDrawing();
    }








    return 0;
}