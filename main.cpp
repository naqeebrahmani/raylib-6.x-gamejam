#include <iostream>
#include <raylib.h>
#include <cmath>
#include <string>


Color GREY = {200, 200, 200, 255};

Color colRED = {255, 0, 0, 255};
Color colYELLOW = {255, 255, 0, 255};
Color colPURPLE = {255, 0, 255, 255};
Color colGREY = {125, 125, 125, 255};
Color colCYAN = {0, 255 ,255, 255};



Color colours[] = {colRED, colYELLOW, colPURPLE, colGREY, colCYAN};

float score = 0;
int totalscore = (sizeof(colours)/sizeof(Color))*10;

int red; int green; int blue;

bool finished = false;

int currentcolour = 0;

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
        std::string inputtextdeci = "";

        bool hex = true;
        


    public:

        bool selected = false;
        Rectangle rect;

        TextBox(float x, float y, std::string title, float width, float height){
            this->x = x;
            this->y = y;
            this->title = title;
            this->width = width;
            this->height = height;
            this->rect = Rectangle{x, y, width, height};
        }


        bool HexOrNot(){
            return hex;
        }

        std::string TextHex(){
            return inputtexthex;
        }

        std::string TextDeci(){
            return inputtextdeci;
        }

        void TakeInputAndDisplay(){

            if(selected == true){
            DrawRectangle(x, y, width, height, GREY);
            }
            else{
                DrawRectangle(x, y, width, height, WHITE);
            }
            
            DrawText(title.c_str(), x + 10, y + 10, 20, BLACK);

            DrawRectangle(x +  width + 50, y, width/2, height, BLACK);
            if(hex == true){
                DrawText("hexa", x + width + 50 + 10, y + 5, 20, WHITE);
            }
            else{
                DrawText("deci", x + width + 50 + 10, y + 5, 20, WHITE);
            }

            if(CheckCollisionPointRec(GetMousePosition(), Rectangle{x +  width + 50, y, width/2, height})){
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    if(hex){
                        hex = false;
                        inputtexthex.clear();
                    }
                    else{
                        hex = true;
                        inputtextdeci.clear();
                    }
                }
            }


            if(selected){

                char key = GetCharPressed();
                
                if(key != 0){
                    if(hex){
                        if(inputtexthex.length() < 2){
                            inputtexthex += std::toupper(key);
                        }
                    }
                    else{
                        if(inputtextdeci.length() < 3){
                            inputtextdeci += std::toupper(key);
                            }
                        }
                }
                if(IsKeyPressed(KEY_BACKSPACE)){
                    if(!inputtexthex.empty()){
                    inputtexthex.pop_back(); 
                    }
                    if(!inputtextdeci.empty()){
                        inputtextdeci.pop_back();
                    }
                }

                

            }

            DrawText(inputtexthex.c_str(), x + 90, y + 5, 25, BLACK);
            DrawText(inputtextdeci.c_str(), x + 90, y + 5, 25, BLACK);


        }

};

class Button{
    private:
        float x;
        float y;
        float width;
        float height;
        std::string text;
        bool visible;
        bool pressed = false;

    public:
        Button(float x, float y, float width, float height, std::string text, bool visible){
            this->x = x;
            this->y = y;
            this->width = width;
            this->height = height;
            this->text = text;
            this->visible = visible;
        }

        void displayAndPressCheck(){
            if(visible){
                if(CheckCollisionPointRec(GetMousePosition(), Rectangle{x, y, width, height}) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                    DrawRectangle(x, y, width - 5, height - 5, GREY);
                    DrawText(text.c_str(), x + 5, y + 5, 20, BLACK);
                }
                else{
                DrawRectangle(x, y, width, height, GREY);
                DrawText(text.c_str(), x + 10, y + 10, 20, BLACK);
                }

                if(CheckCollisionPointRec(GetMousePosition(), Rectangle{x, y, width, height}) && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                    if(pressed){
                        pressed = false;
                    }
                    else{
                    pressed = true;
                    }
                }

            }

        }

        void MakeVisible(){
            visible = true;
        }
        void MakeInVisible(){
            visible = false;
        }

        void UnPress(){
            pressed = false;
        }

        bool Pressed(){
            return pressed;
        }



};


//creating the buttons//
Button buttonnext(500, 450, 100, 40, "NEXT->", false);
Button buttonskip(500, 550, 100, 40, "SKIP->", false);

//creating the textboxes//
TextBox textbox1(100, 450, "RED: ", 150, 30);
TextBox textbox2(100, 500, "GREEN: ", 150, 30);
TextBox textbox3(100, 550, "BLUE: ", 150, 30);
//============================================//
void selecttextbox(TextBox *tb1, TextBox *tb2, TextBox *tb3){

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){

        if(CheckCollisionPointRec(GetMousePosition(), (*tb1).rect)){
            (*tb1).selected = true;
            (*tb2).selected = false;
            (*tb3).selected = false;
            
        }
        else if(CheckCollisionPointRec(GetMousePosition(), (*tb2).rect)){
            (*tb2).selected = true;
            (*tb1).selected = false;
            (*tb3).selected = false;
            
        }
        else if(CheckCollisionPointRec(GetMousePosition(), (*tb3).rect)){
            (*tb3).selected = true;
            (*tb1).selected = false;
            (*tb2).selected = false;
            
        } 

    }

}


int HexadecimalToDecimal(const char hexa[], int arraysize){

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
                default:
                    temp_num = 0;
                    return -1;
                
            }

            num += temp_num * pow(16, size-i-1); //subtracting 1 because i starts as 0
        
        }
        else{

            num += (hexa[i] - '0') * pow(16, size-i-1); //subtracted the char 0 because of their ascii values 
        }                                               //because 0 doesnt have the ascii value 0 but something like 48 i think

    }

    return num;

}



bool IsDigitOrNot(const char array[], int size){

    for(int i  = 0; i < size; i++){
        if(!isdigit(array[i])){
            return false;
        }
    }

    return true;

}


void AssignColours(){
    int tempvar1 = -1;
    int tempvar2 = -1;
    int tempvar3 = -1;
    if(textbox1.HexOrNot()){
        std::string tempvarstr = textbox1.TextHex();
        tempvar1 = HexadecimalToDecimal(tempvarstr.c_str(),tempvarstr.length());
    }
    else{
        std::string tempvarstr = textbox1.TextDeci();

        if(IsDigitOrNot(tempvarstr.c_str(), tempvarstr.length())){
            tempvar1 = TextToInteger(tempvarstr.c_str());
        }
    }

    if(textbox2.HexOrNot()){
        std::string tempvarstr = textbox2.TextHex();
        tempvar2 = HexadecimalToDecimal(tempvarstr.c_str(),tempvarstr.length());
    }
    else{
        std::string tempvarstr = textbox2.TextDeci();

        if(IsDigitOrNot(tempvarstr.c_str(), tempvarstr.length())){
            tempvar2 = TextToInteger(tempvarstr.c_str());
        }
    }

    if(textbox3.HexOrNot()){
        std::string tempvarstr = textbox3.TextHex();
        tempvar3 = HexadecimalToDecimal(tempvarstr.c_str(),tempvarstr.length());
    }
    else{
        std::string tempvarstr = textbox3.TextDeci();

        if(IsDigitOrNot(tempvarstr.c_str(), tempvarstr.length())){
            tempvar3 = TextToInteger(tempvarstr.c_str());
        }
    }

    //bool valid = false;

    if(tempvar1 >= 0 && tempvar1 <= 255){
        red = tempvar1;
    }
    if(tempvar2 >= 0 && tempvar2 <= 255){
        green = tempvar2;
    }
    if(tempvar3 >= 0 && tempvar3 <= 255){
        blue = tempvar3;
    }

}

void WinConditionsAndContinue(){

    if(colours[currentcolour].r == (unsigned char)red && colours[currentcolour].g == (unsigned char)green && colours[currentcolour].b == (unsigned char)blue){
        DrawText("PERFECT MERGE!", 200, 50, 30, GREEN);
        if(currentcolour < ((sizeof(colours)/sizeof(Color)))){
            buttonnext.MakeVisible();
        }
    }
    else if(((int)colours[currentcolour].r <= (red + 10) &&  (int)colours[currentcolour].r >= (red - 10))
         && ((int)colours[currentcolour].g <= (green + 10) &&  (int)colours[currentcolour].g >= (green - 10))
         && ((int)colours[currentcolour].b <= (blue + 10) &&  (int)colours[currentcolour].b >= (blue - 10)))
    
    {
        
        DrawText("Partial Merge", 250, 50, 30, GREEN);
        if(currentcolour < ((sizeof(colours)/sizeof(Color)))){
            buttonnext.MakeVisible();
        }
    }
    else if(((int)colours[currentcolour].r <= (red + 20) &&  (int)colours[currentcolour].r >= (red - 20))
         && ((int)colours[currentcolour].g <= (green + 20) &&  (int)colours[currentcolour].g >= (green - 20))
         && ((int)colours[currentcolour].b <= (blue + 20) &&  (int)colours[currentcolour].b >= (blue - 20)))
    
    {
        
        DrawText("Minimal Merge", 250, 50, 30, GREEN);
        if(currentcolour < ((sizeof(colours)/sizeof(Color)))){
            buttonnext.MakeVisible();
        }
    }

    else{
        buttonnext.MakeInVisible();
    }

    if(buttonnext.Pressed()){
        if(colours[currentcolour].r == (unsigned char)red && colours[currentcolour].g == (unsigned char)green && colours[currentcolour].b == (unsigned char)blue){
        score += 10;
        }
        
        else if(((int)colours[currentcolour].r <= (red + 10) &&  (int)colours[currentcolour].r >= (red - 10))
         && ((int)colours[currentcolour].g <= (green + 10) &&  (int)colours[currentcolour].g >= (green - 10))
         && ((int)colours[currentcolour].b <= (blue + 10) &&  (int)colours[currentcolour].b >= (blue - 10)))
        {
        score += 5;
        }

        else if(((int)colours[currentcolour].r <= (red + 20) &&  (int)colours[currentcolour].r >= (red - 20))
         && ((int)colours[currentcolour].g <= (green + 20) &&  (int)colours[currentcolour].g >= (green - 20))
         && ((int)colours[currentcolour].b <= (blue + 20) &&  (int)colours[currentcolour].b >= (blue - 20)))
    
        {
        score += 2.5;
        }

        buttonnext.UnPress();

        if(currentcolour == (sizeof(colours)/sizeof(Color) - 1)){
            finished = true;
        }
        else{
        currentcolour ++;
        }
    }

}


int main(){

    InitWindow(720, 720, "Match And Merge");
    SetTargetFPS(60);


    while(!WindowShouldClose()){

        if(!finished){

            AssignColours();

            selecttextbox(&textbox1, &textbox2, &textbox3);

            BeginDrawing();
            
            ClearBackground(colours[currentcolour]);

            DrawRectangle(260, 100, 200, 200, {(unsigned char)red, (unsigned char)green, (unsigned char)blue, 255});

            DrawRectangle(0, 400, 720, 320,  {0,0,0,155});

            //drawing and taking input from the textboxes//
            textbox1.TakeInputAndDisplay();
            textbox2.TakeInputAndDisplay();
            textbox3.TakeInputAndDisplay();
            //===========================================//

            buttonnext.displayAndPressCheck();

            //==========================//

            WinConditionsAndContinue();

            EndDrawing();
        
        }

        else{

            BeginDrawing();

            ClearBackground(WHITE);


            DrawText(TextFormat("Score: %0.2f/%0.2f", score, (float)totalscore), 100, 100, 30, BLACK);

            EndDrawing();

        }

    }








    return 0;
}