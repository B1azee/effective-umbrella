
#include "txlib.h"

using namespace std;

void house (int, int, bool = 0, float = 1, COLORREF = RGB (101, 67, 33), COLORREF = RGB (194, 27, 7)) ;
void landscape (COLORREF grass = RGB (0, 230, 0));
void interface1();
void tree (int x, int y, float sizetree, COLORREF gra = RGB (0, 100, 0));
void swingingTree(int x,int y,float sizeTree,COLORREF gra  = RGB (0, 100, 0));

int main()
{
    txCreateWindow (800, 600);
    int x = 1;
    int y = 1;
    int t = 20;
    bool tr = 1;
    bool tre = 1;
    COLORREF gra = RGB (0, 100, 0);
    COLORREF grass = RGB (0, 230, 0);
    landscape();
    interface1();
    tree (600, 500, 1);
    house (300, 300, 1);

    while (true)
    {
        bool cycle = true;

        if (txMouseButtons() & 1)
        {
            RECT buttonstart = {20, 20, 140, 80 };// СТАРТ

            if (In (txMousePos(), buttonstart))
            {

                gra  = RGB (0, 100, 0);
                grass = RGB (0, 230, 0);

                while (cycle == true)
                {
                    for(int treeCicle = 1; treeCicle< 4; treeCicle++)
                    {
                        if (treeCicle == 2 && tre==1  )
                        {
                            tr = 0;
                            tree (600, 500, 2, gra);

                        }
                        for (int h = 1; h < 80; h++)
                        {
                            txSetColor (RGB (255, 255, 255));
                            txSetFillColor (RGB (255, 255, 255));
                            txCircle (445 - x, 220 - y, 15);
                            x = x + 2;
                            y = y + 2;
                            txSleep (t);
                            txSetFillColor (RGB (0, 0, 0));
                            txClear();
                            landscape (grass);
                            house (300, 300, 1);
                            if (treeCicle == 2 && tre == 1)
                            {
                                tr = 0;
                                if(h<21)
                                {
                                    swingingTree(600+h,500,2,gra);
                                }
                                if(h>20 and h<61)
                                {
                                    swingingTree(640-h,500,2,gra);
                                }
                                if(h>60)
                                {
                                    swingingTree(520+h,500,2,gra);
                                }
                            }
                            if   (tr ==1)
                            {
                                tree (600, 500, h * 0.025, gra);
                            }

                            interface1();

                            if (txMouseButtons() & 1)//ФИНИШ
                            {
                                RECT buttonFinish = { 20, 520, 140, 580 };

                                if (In (txMousePos(), buttonFinish))
                                {
                                    h = 100;
                                    cycle = false;
                                }
                            }

                            if (txMouseButtons() & 1)//ЗАМЕДЛЕНИЕ
                            {
                                RECT buttonSlow = { 20, 100, 140, 160 };

                                if (In (txMousePos(), buttonSlow))
                                {
                                    t = t + 3;

                                    if (t > 80)
                                    {
                                        t = 10;
                                        txSleep (2000);
                                    }
                                }
                            }

                            if (txMouseButtons() & 1)//УСКОРКНИЕ
                            {
                                RECT buttonSpeed = {20, 180, 140, 240 };

                                if (In (txMousePos(), buttonSpeed))
                                {
                                    t = t - 3;

                                    if (t < 1)
                                    {
                                        t = 10;
                                        txSleep (2000);
                                    }
                                }
                            }

                            if (txMouseButtons() & 1)//ДЕРЕВО
                            {

                                RECT buttonTree = {20, 260, 140, 320 };

                                if (In (txMousePos(), buttonTree))
                                {
                                    tr = !tr;
                                    tre = !tre;
                                    txSleep (100);
                                }
                            }

                            if (txMouseButtons() & 1)//ВРЕМЯ ГОДА
                            {
                                RECT buttonColor = {20, 340, 140, 400 };

                                if (In (txMousePos(), buttonColor))
                                {
                                    if (gra == RGB (0, 100, 0))
                                    {
                                        gra  = RGB (240, 100, 10);
                                        grass = RGB (200, 132, 10);
                                    }
                                    else
                                    {
                                        gra  = RGB (0, 100, 0);
                                        grass = RGB (0, 230, 0);
                                    }
                                }
                                txSleep (100);
                            }

                        }
                        x = 1;
                        y = 1;
                        if (treeCicle == 2 && tre == 1)
                        {
                            treeCicle =0;
                            tr=1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void landscape (COLORREF grass)
{
    txSetColor (RGB (0, 0, 0));
    txSetFillColor (RGB (135, 206, 235));
    txRectangle (0, 0, txGetExtentX(), txGetExtentY());
    txSetFillColor (grass);
    txRectangle (0, txGetExtentY() * 0.7, txGetExtentX(), txGetExtentY());
}
void interface1 ()
{
    txSetColor (RGB (0, 0, 0));
    txSetFillColor (RGB (160, 160, 160));
    txRectangle (0, 0, 160, txGetExtentY());

    txSetFillColor (RGB (0, 200, 0));//ЗЕЛЕНЫЙ
    txRectangle (20, 20, 140, 80);
    txSelectFont ("Arial", 20, 8);
    txDrawText (20, 20, 140, 80, "Старт");
    txSetFillColor (RGB (200, 0, 0));//КРИСНЫЙ
    txRectangle (20, txGetExtentY() - 20, 140, txGetExtentY() - 80);
    txDrawText (20, txGetExtentY() - 20, 140, txGetExtentY() - 80, "Конец");
    txSetFillColor (RGB (240, 240, 0));// СИНИЙ
    txRectangle (20, 100, 140, 160);
    txDrawText (20, 100, 140, 160, "Замедление");
    txRectangle (20, 180, 140, 240);
    txDrawText (20, 180, 140, 240, "Ускрение");
    txRectangle (20, 260, 140, 320);
    txDrawText (20, 260, 140, 320, "Дерево");
    txRectangle (20, 340, 140, 400);
    txDrawText (20, 340, 140, 400, "Сменить цвет");
}
void house (int x, int y, bool flue, float sizehouse, COLORREF collorhouse, COLORREF collorroof)
    {
    txSetColor (RGB (0, 0, 0)); //чёрный
    txSetFillColor (collorhouse); //коричневый
    txRectangle (x + 20 * sizehouse, y + 80 * sizehouse, x + 180 * sizehouse, y + 160 * sizehouse); //сам дом
    POINT wall[4] = {{x + 180 * sizehouse, y + 80 * sizehouse }, {x + 220 * sizehouse, y + 60 * sizehouse}, {x + 220 * sizehouse, y + 140 * sizehouse}, {x + 180 * sizehouse, y + 160 * sizehouse}}; // стена
    txPolygon (wall, 4);

    txSetFillColor (collorroof); //красный
    POINT roof[4] = {{x + 100 * sizehouse, y + 1 * sizehouse}, {x + 140 * sizehouse, y - 20 * sizehouse}, {x + 240 * sizehouse, y + 60 * sizehouse}, {x + 200 * sizehouse, y + 80 * sizehouse}}; // бок крыши
    txPolygon (roof, 4);
    POINT triangle[3] = {{x + 1 * sizehouse, y + 80 * sizehouse}, {x + 100 * sizehouse, y + 1 * sizehouse}, {x + 200 * sizehouse, y + 80 * sizehouse}}; //перед крыши
    txPolygon (triangle, 3);

    txSetFillColor (RGB (135, 206, 235)); //голубой
    txRectangle (x + 40 * sizehouse, y + 100 * sizehouse, x + 100 * sizehouse, y + 140 * sizehouse); //окно
    txCircle (x + 100 * sizehouse, y + 50 * sizehouse, 15 * sizehouse); //окно-чердак
    POINT window[4] = {{x + 190 * sizehouse, y + 95 * sizehouse}, {x + 210 * sizehouse, y + 85 * sizehouse}, {x + 210 * sizehouse, y + 125 * sizehouse}, {x + 190 * sizehouse, y + 135 * sizehouse}}; // окно сбоку
    txPolygon (window, 4);

    txSetColor (RGB (0, 0, 0));
    txLine (x + 100 * sizehouse, y + 35 * sizehouse, x + 100 * sizehouse, y + 65 * sizehouse); //рама вертикальная(чердак)
    txLine (x + 85 * sizehouse, y + 50 * sizehouse, x + 115 * sizehouse, y + 50 * sizehouse); //рама горизонтальная(чердак)
    txLine (x + 70 * sizehouse, y + 100 * sizehouse, x + 70 * sizehouse, y + 140 * sizehouse); //рама вертикальная
    txLine (x + 40 * sizehouse, y + 120 * sizehouse, x + 100 * sizehouse, y + 120 * sizehouse); //рама горизонтальная

    txSetFillColor (RGB (86, 67, 33)); //коричневый
    txRectangle (x + 120 * sizehouse, y + 100 * sizehouse, x + 160 * sizehouse, y + 160 * sizehouse); //дверь

    if (flue)
        {
        txSetFillColor (collorhouse);
        POINT flue1[4] = {{x + 130 * sizehouse, y - 7 * sizehouse}, {x + 130 * sizehouse, y - 60 * sizehouse}, {x + 150 * sizehouse, y - 60 * sizehouse}, {x + 150 * sizehouse, y + 10 * sizehouse}};
        txPolygon (flue1, 4);

        POINT flue2[4] = {{x + 155 * sizehouse, y + 7 * sizehouse}, {x + 155 * sizehouse, y - 65 * sizehouse}, {x + 150 * sizehouse, y - 60 * sizehouse}, {x + 150 * sizehouse, y + 10 * sizehouse}};
        txPolygon (flue2, 4);

        txSetFillColor (RGB (86, 67, 33)); //чёрный
        POINT flue3[4] = {{x + 130 * sizehouse, y - 60 * sizehouse}, {x + 150 * sizehouse, y - 60 * sizehouse}, {x + 155 * sizehouse, y - 65 * sizehouse}, {x + 135 * sizehouse, y - 65 * sizehouse}};
        txPolygon (flue3, 4);
        }

    }
void tree (int x, int y, float sizetree, COLORREF gra)
{
    txSetFillColor (RGB (86, 67, 33)); //коричневый
    txRectangle (x - 10 * sizetree, y - 70 * sizetree, x + 10 * sizetree, y + 1 * sizetree);
    txSetFillColor (gra);
    txCircle (x + 1 * sizetree, y - 70 * sizetree, 30 * sizetree);
}
void swingingTree(int x,int y,float sizeTree,COLORREF gra)
{

    POINT tree2[4] {{x - 10* sizeTree, y - 70* sizeTree},{600-10* sizeTree,y+1* sizeTree}, {600+10* sizeTree, y + 1* sizeTree},{x+10* sizeTree,y-70* sizeTree}};
    txSetFillColor (RGB (86, 67, 33)); //коричневый
    txPolygon (tree2, 4);
    txSetFillColor (gra);
    txCircle (x + 1* sizeTree, y - 70* sizeTree, 30* sizeTree);

}
