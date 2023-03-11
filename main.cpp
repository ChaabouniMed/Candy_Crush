#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "game.h"

void swap(candy p1, candy p2)
{
    std::swap(p1.col, p2.col);
    std::swap(p1.row, p2.row);
    grid[p1.row][p1.col] = p1;
    grid[p2.row][p2.col] = p2;
}
void destroy(int a, int b)
{
    for (int i = b; i > 0; i--)
        swap(grid[i][a], grid[i - 1][a]);
    grid[0][a].y = -decalage[a] * 74;
    grid[0][a].kind = rand() % 6;
    decalage[a]++;
}

sf::RenderWindow Game::window(sf::VideoMode(592, 680), "Candy Crush");
int main()
{
    srand(time(0));
    Game game;
    game.manage();
    return 0 ;
}