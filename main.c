// Import library
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
    // init the whole windows and starting points, heading poses
    // init windows
    WINDOW *win = initscr();

    // set up keypad
    keypad(win, true);

    // set up a no delay for each key pressed
    nodelay(win, true);

    // init the init position of snake (the grid is x * y)
    int posX = 0;
    int posY = 0;

    // set food coord with randomized x and y
    // not technically rand (basically an algo)
    int foodX = rand() % 20;
    int foodY = rand() % 20;

    // start the direction of the head
    // it turns right on init
    int dirX = 1;
    int dirY = 0;

    while (true)
    {
        // init wgetch (windows reader - getter)
        int pressed = wgetch(win);
        // switch between pressed keys
        switch (pressed)
        {
        default:
            dirX = 0;
            dirY = 0;
            break;
        case KEY_LEFT:
            dirX = -1;
            dirY = 0;
            break;
        case KEY_RIGHT:
            dirX = 1;
            dirY = 0;
        case KEY_UP:
            dirX = 0;
            dirY = -1;
        case KEY_DOWN:
            dirX = 0;
            dirY = 1;
        }

        posX += dirX;
        posY += dirY;

        // create blank windows (adding space to every small pixel of the window)
        erase();
        // create a snake and food by creating a string for it
        mvaddstr(posX, posY, 'o');
        mvaddchstr(foodX, foodY, '*');

        if (foodX == posX && foodY == posY)
        {
            // if the snake hits the food, change the food pos
            int foodX = rand() % 20;
            int foodY = rand() % 20;
        }

        // stop the program every 100000 milisec
        usleep(100000);
    }

    // end windows
    endwin();
}