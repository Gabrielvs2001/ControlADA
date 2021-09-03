#define DATA_LENGTH 1

#include "SerialPort.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;
const char* portName = "\\\\.\\COM10";
string startInput;
//Declare a global object
SerialPort* arduino;
string justRead;
string lx;
string ly;
string rx;
string ry;
int cx;
int cy;
string b1, b2, b3, b4, b5, b6, b7, b8, b9, b10;
POINT mouse;

char receivedString[DATA_LENGTH];

int main(void)
{
    cout << "please type start and press enter to begin program" << endl;
    cin >> startInput;
    if (startInput == "start")
    {
        arduino = new SerialPort(portName);
        while (arduino->isConnected())
        {
            arduino->readSerialPort(receivedString, DATA_LENGTH);
            justRead = receivedString;


            if (justRead == "a")
            {
                arduino->readSerialPort(receivedString, DATA_LENGTH);//reading lx
                lx = receivedString;
                cout << lx << ends;
                if (lx == "2") { keybd_event(0x44, 0, 0, 0); }
                if (lx == "1") { keybd_event(0x41, 0, 0, 0); }
                if (lx == "0")
                {
                    keybd_event(0x44, 0, KEYEVENTF_KEYUP, 0);
                    keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0);
                }

                arduino->readSerialPort(receivedString, DATA_LENGTH);//reading ly
                ly = receivedString;
                cout << ly << ends;
                if (ly == "2") { keybd_event(0x57, 0, 0, 0); }
                if (ly == "1") { keybd_event(0x53, 0, 0, 0); }
                if (ly == "0")
                {
                    keybd_event(0x57, 0, KEYEVENTF_KEYUP, 0);
                    keybd_event(0x53, 0, KEYEVENTF_KEYUP, 0);
                }
            }

            if (justRead == "b")
            {
                arduino->readSerialPort(receivedString, DATA_LENGTH);//reading rx
                rx = receivedString;
                cout << rx << ends;

                arduino->readSerialPort(receivedString, DATA_LENGTH);//reading tary
                ry = receivedString;
                cout << ry << ends;

                istringstream(rx) >> cx;
                istringstream(ry) >> cy;

                if (cx == 4) { mouse.x = mouse.x; }// behold the dumbest shit you'll ever see
                if (cx == 0) { mouse.x = mouse.x - 50; }
                if (cx == 1) { mouse.x = mouse.x - 20; }
                if (cx == 2) { mouse.x = mouse.x - 5; }
                if (cx == 3) { mouse.x = mouse.x - 2; }
                if (cx == 5) { mouse.x = mouse.x + 2; }
                if (cx == 6) { mouse.x = mouse.x + 5; }
                if (cx == 7) { mouse.x = mouse.x + 20; }
                if (cx == 8) { mouse.x = mouse.x + 50; }
                
                if (cy == 4) { mouse.y = mouse.y; }
                if (cy == 0) { mouse.y = mouse.y - 50; }
                if (cy == 1) { mouse.y = mouse.y - 20; }
                if (cy == 2) { mouse.y = mouse.y - 5; }
                if (cy == 3) { mouse.y = mouse.y - 2; }
                if (cy == 5) { mouse.y = mouse.y + 2; }
                if (cy == 6) { mouse.y = mouse.y + 5; }
                if (cy == 7) { mouse.y = mouse.y + 20; }
                if (cy == 8) { mouse.y = mouse.y + 50; }
                

               

                SetCursorPos(mouse.x, mouse.y);//setting new cursor position
                GetCursorPos(&mouse);//recording new cursor postion

            }

            if (justRead == "c")
            {
                arduino->readSerialPort(receivedString, DATA_LENGTH);//reading b1 (left stick -> shift)
                b1 = receivedString;
                cout << b1 << ends;
                if (b1 == "1") { keybd_event(0x10, 0, 0, 0); }
                if (b1 == "0") { keybd_event(0x10, 0, KEYEVENTF_KEYUP, 0); }

                arduino->readSerialPort(receivedString, DATA_LENGTH);//reading b2 (right stick -> middle mouse)
                b2 = receivedString;
                cout << b2 << ends;
                if (b2 == "1") { keybd_event(0x04, 0, 0, 0); }
                if (b2 == "0") { keybd_event(0x04, 0, KEYEVENTF_KEYUP, 0); }

            }

            if (justRead == "e")
            {
                arduino->readSerialPort(receivedString, DATA_LENGTH);//reading b5 (right button on left side -> E)
                b5 = receivedString;
                cout << b5 << ends;
                if (b5 == "1") { keybd_event(0x45, 0, 0, 0); }
                if (b5 == "0") { keybd_event(0x45, 0, KEYEVENTF_KEYUP, 0); }

                arduino->readSerialPort(receivedString, DATA_LENGTH);//reading b6 (left button on left side -> Q)
                b6 = receivedString;
                cout << b6 << ends;
                if (b6 == "1") { keybd_event(0x51, 0, 0, 0); }
                if (b6 == "0") { keybd_event(0x51, 0, KEYEVENTF_KEYUP, 0); }

            }

            if (justRead == "f")
            {
                arduino->readSerialPort(receivedString, DATA_LENGTH);//reading b7 (top button on left side -> r)
                b7 = receivedString;
                cout << b7 << ends;
                if (b7 == "1") { keybd_event(0x52, 0, 0, 0); }
                if (b7 == "0") { keybd_event(0x52, 0, KEYEVENTF_KEYUP, 0); }

                arduino->readSerialPort(receivedString, DATA_LENGTH);//reading b8 (bottom button on right side -> SPACE)
                b8 = receivedString;
                cout << b8 << ends;
                if (b8 == "1") { keybd_event(0x20, 0, 0, 0); }
                if (b8 == "0") { keybd_event(0x20, 0, KEYEVENTF_KEYUP, 0); }

            }

            if (justRead == "g")
            {
                arduino->readSerialPort(receivedString, DATA_LENGTH);
                b9 = receivedString;
                cout << b9 << ends;

                arduino->readSerialPort(receivedString, DATA_LENGTH);//reading b10 (right button on right side -> c)
                b10 = receivedString;
                cout << b10 << ends;

                if (b10 == "1") { keybd_event(0x43, 0, 0, 0); }
                if (b10 == "0") { keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); }

                

            }

            if (justRead == "d")
            {
                arduino->readSerialPort(receivedString, DATA_LENGTH);//reading b3 (right trigger -> left mouse)
                b3 = receivedString;
                cout << b3 << ends;
                if (b3 == "1") {
                    INPUT iNPUT1 = { 0 };
                    iNPUT1.type = INPUT_MOUSE;
                    iNPUT1.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
                    SendInput(1, &iNPUT1, sizeof(iNPUT1));
                    ZeroMemory(&iNPUT1, sizeof(iNPUT1));
                }
                if (b3 == "0") {
                    INPUT iNPUT1 = { 0 };
                    iNPUT1.type = INPUT_MOUSE;
                    iNPUT1.mi.dwFlags = MOUSEEVENTF_LEFTUP;
                    SendInput(1, &iNPUT1, sizeof(iNPUT1));
                    ZeroMemory(&iNPUT1, sizeof(iNPUT1));
                }

                arduino->readSerialPort(receivedString, DATA_LENGTH);//reading b4 (left trigger -> right mouse)
                b4 = receivedString;
                cout << b4 << ends;
                if (b4 == "1") {
                    INPUT inputr = { 0 };
                    inputr.type = INPUT_MOUSE;
                    inputr.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
                    Sleep(1);
                    inputr.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
                    SendInput(1, &inputr, sizeof(inputr));
                    ZeroMemory(&inputr, sizeof(inputr));
                }
                

                cout << "" << endl;


            } 

        }

    }
}
         
      
   

