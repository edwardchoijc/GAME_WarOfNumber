#include "const_Value.h"
#include "about_Draw.h"
#include "about_class.h"
#include "about_operation.h"

void Start_Process();
void Main_Process();
void End_Process();

using namespace std;

int main(void)
{
    SetConsoleOutputCP(437);
    Start_Process();
    Main_Process();
    End_Process();
    return 0;
}

void Start_Process()
{
    //KongZhiTai windows design.
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    hIn=GetStdHandle(STD_INPUT_HANDLE);
    hWnd =GetForegroundWindow();

    WORD att=FOREGROUND_GREEN|FOREGROUND_INTENSITY;//|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED;
    SetConsoleTextAttribute(hOut,att);
    system("CLS");

    GetConsoleCursorInfo(hOut,&cci);
    cci.bVisible=false;
    SetConsoleCursorInfo(hOut,&cci);


    SetConsoleTitle("The War of Number");
    SMALL_RECT rc = {0,0, WINDOW_SIZE_X-1,WINDOW_SIZE_Y-1};
    COORD window_size={WINDOW_SIZE_X,WINDOW_SIZE_Y};
    SetConsoleScreenBufferSize(hOut,window_size);
    SetConsoleWindowInfo(hOut,true ,&rc);

    ShowWindow(hWnd,3);

}

void Main_Process()
{
    while(1)
    {
        if(Main_Windows(hOut,hWnd)==false)
            break;
    }

}

void End_Process()
{
    //Ex:achieve save battle message?
    CloseHandle(hOut);
    CloseHandle(hIn);

}
