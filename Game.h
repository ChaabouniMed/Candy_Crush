#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

// int decalage[8];
struct candy
{
    int x, y, col, row, kind, match, is_animated = 0, to_destroy = 0;

} 
// grid[10][10];



class Game
{
private:
    static sf::RenderWindow window;
    int ts = 74;
    int decalage[8];
public:
    void display_menu(sf::Sprite &back_gr , sf::Sprite &board)
    {
        window.clear();
        window.draw(back_gr);
        window.draw(board);
        window.display();
    }
    int levels()
    {
        sf::Sprite back_gr,board;
        sf::Texture image1,image2;
        if (!(image1.loadFromFile("images/background3.jpg")))
            std::cout << "Cannot load image";
        back_gr.setTexture(image1);
        if (!(image2.loadFromFile("images/menu4.png")))
            std::cout << "Cannot load image";
        board.setTexture(image2);
        board.setScale(0.3f, 0.3f);
        window.setFramerateLimit(60);
        sf::Vector2i pos;
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        pos = sf::Mouse::getPosition(window);
                        if (pos.x>180 && pos.x<270 && pos.y>140 && pos.y<230) 
                        {
                            sf::sleep(sf::milliseconds(100));
                            return 2;
                        }
                        else if (pos.x>270 && pos.x<320 && pos.y>520 && pos.y<570)
                        {
                            return 0;
                        }
                    }
                }
            }
            display_menu(back_gr,board);
        }
    }
    int credits()
    {
        sf::Sprite back_gr,board;
        sf::Texture image1,image2;
        if (!(image1.loadFromFile("images/background3.jpg")))
            std::cout << "Cannot load image";
        back_gr.setTexture(image1);
        if (!(image2.loadFromFile("images/menu5.png")))
            std::cout << "Cannot load image";
        board.setTexture(image2);
        board.setScale(0.3f, 0.3f);
        window.setFramerateLimit(60);
        sf::Vector2i pos;
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        return 0;
                    }
                }
            }
            display_menu(back_gr,board);
        }
    }
    int options()
    {
        sf::Sprite back_gr,board;
        sf::Texture image1,image2;
        if (!(image1.loadFromFile("images/background3.jpg")))
            std::cout << "Cannot load image";
        back_gr.setTexture(image1);
        if (!(image2.loadFromFile("images/menu3.png")))
            std::cout << "Cannot load image";
        board.setTexture(image2);
        board.setScale(0.3f, 0.3f);
        window.setFramerateLimit(60);
        sf::Vector2i pos;
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        return 0;
                    }
                }
            }
            display_menu(back_gr,board);
        }
    }
    int menu()
    {
        sf::Sprite back_gr,board;
        sf::Texture image1,image2;
        if (!(image1.loadFromFile("images/background3.jpg")))
            std::cout << "Cannot load image";
        back_gr.setTexture(image1);
       
        if (!(image2.loadFromFile("images/menu1.png")))
            std::cout << "Cannot load image";
        board.setTexture(image2);
        board.setScale(0.3f, 0.3f);
        window.setFramerateLimit(60);
        sf::Vector2i pos;
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        pos = sf::Mouse::getPosition(window);
                        //------ Play 
                        if (pos.x>200 && pos.x<410 && pos.y>140 && pos.y<200) 
                        {
                            sf::sleep(sf::milliseconds(100));
                            return 1;
                        }
                        //------ Continue
                    if (pos.x>200 && pos.x<410 && pos.y>250 && pos.y<300) 
                        {
                            sf::sleep(sf::milliseconds(100));
                            return 2;
                        }
                        //------ Options
                    if (pos.x>200 && pos.x<410 && pos.y>350 && pos.y<400) 
                        {
                            sf::sleep(sf::milliseconds(100));
                            return 3;
                        }
                        //------ Credits 
                    if (pos.x>200 && pos.x<410 && pos.y>450 && pos.y<500) 
                        {
                            sf::sleep(sf::milliseconds(100));
                            return 4;
                        }
                    }
                }
            }
            display_menu(back_gr,board);
        }
    }
    void manage()
    {      
        int task=0 ;
        while (window.isOpen())
        {
        if (task==0)
        task = menu();
        else if (task==1)
        task=levels();
        else if (task==2)
        task=run(1);
        else if (task==3)
        task=options();
        else if (task==4)
        task=credits();
        }
    }
    void destruction(candy grid[][10],int &there_is_match,int &isSwap,int &isMoving,int &objectiv)
    {
    for (int i = 0; i < 8; i++)
        decalage[i] = 1;
        if (!isMoving)
        {
        
            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 8; j++)
                    {
                        if ((grid[i][j].kind == grid[i + 1][j].kind) && (grid[i][j].kind == grid[i + 2][j].kind) && (i < 6))
                        {
                            for (int n = 0; n < 3; n++)
                            {
                                grid[i + n][j].to_destroy = 1;
                                there_is_match = 1;
                                isSwap = 0;
                            }
                        }
                        if ((grid[i][j].kind == grid[i][j + 1].kind) && (grid[i][j].kind == grid[i][j + 2].kind) && (j < 6))
                        {
                            for (int n = 0; n < 3; n++)
                            {
                                grid[i][j + n].to_destroy = 1;
                                there_is_match = 1;
                                isSwap = 0;
                            }
                        }
                    }
        }
            if (!isMoving)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (grid[i][j].to_destroy)
                        {
                            if(grid[i][j].kind==1)
                            objectiv++;
                            grid[i][j].to_destroy = 0;
                            destroy(grid[i][j].col, grid[i][j].row);
                        }
                    }
    }
    void display_game(sf::Sprite &back_gr,sf::Sprite &board , sf::Sprite s[16] , sf::RectangleShape &rectangle,sf::Text &move_text, sf::Text &objectiv_text )
    {
        window.clear();
            window.draw(back_gr);
            window.draw(board);
            //------- Drawing candys
            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 8; j++)
                {
                    rectangle.setPosition(j * 74.f, i * 74.f);
                    window.draw(rectangle);

                    candy &p = grid[i][j];

                    if (p.is_animated == 1)
                    {
                        s[p.kind + 10].setPosition(p.x, p.y);
                        window.draw(s[p.kind + 10]);
                    }
                    else
                    {
                        s[p.kind].setPosition(p.x, p.y);
                        window.draw(s[p.kind]);
                    }
                }
            window.draw(move_text);
            window.draw(objectiv_text);
            window.display();
    }
    void update(candy grid[][10],int &isMoving)
    {
        int speed = 4;
        for (int i = 0; i < 8; i++)
                for (int j = 0; j < 8; j++)
                {
                    int x, y;
                    candy &p = grid[i][j];
                    for (int n = 0; n < speed; n++)
                    {
                        x = p.x - p.col * ts;
                        if (x)
                            p.x = p.x - x / abs(x);
                        y = p.y - p.row * ts;
                        if (y)
                            p.y = p.y - y / abs(y);
                    }
                    if (x || y)
                        isMoving = 1;
                }
    }
    int run(int level)
    {

        int objectiv=0;
        int moves=0 ;
        window.setFramerateLimit(60);
        int click = 0;
        int x0, y0, x1, y1, a, b;
        int isMoving = 0, isSwap = 0, there_is_match = 0;
        sf::Vector2i pos;
        //----- Loading text
        sf::Text move_text,objectiv_text;
        sf::Font font;
        if (!font.loadFromFile("Candice.ttf")) NULL;
        move_text.setFont(font);
        objectiv_text.setFont(font);
        move_text.setString(std::to_string(30-moves));
        objectiv_text.setString(std::to_string(objectiv)+"/20");
        move_text.setPosition(115, 620);
        objectiv_text.setPosition(300,620);
        move_text.setFillColor(sf::Color::Black);
        objectiv_text.setFillColor(sf::Color::Black);
        //----- Loading background
        sf::Sprite back_gr,board;
        sf::Texture image1,image2;
        if (!(image1.loadFromFile("images/background3.jpg")))
            std::cout << "Cannot load image";
        back_gr.setTexture(image1);
        if (!(image2.loadFromFile("images/bot3.png")))
            std::cout << "Cannot load image";
        board.setTexture(image2);
        board.setScale(0.8f, 0.635f);
        // board.setOrigin(0.f, 120.f);
        
        //------- Initialisation du grid
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
            {
                grid[i][j].kind = rand() % 6;
                grid[i][j].col = j;
                grid[i][j].row = i;
                grid[i][j].x = j * ts;
                grid[i][j].y = i * ts;
            }
        //------ Initialisation rect
        sf::RectangleShape rectangle(sf::Vector2f(73, 73));
        rectangle.setFillColor(sf::Color{0, 0, 80, 60});
        //-------Loading candys-----
        sf::Sprite s[16];
        sf::Texture aux[16];
        std::string path;
        for (int i = 0; i < 16; i++)
        {
            path = "images/candy" + std::to_string(i) + ".png";
            if (!(aux[i].loadFromFile(path)))
                std::cout << "Cannot load image";
            s[i].setTexture(aux[i]);
            s[i].setScale(0.8f, 0.8f);
            s[i].setOrigin(-2.f, -2.f);
        }
        s[2].setOrigin(-12.f, -2.f);
        s[12].setOrigin(-12.f, -2.f);
        s[3].setOrigin(-10.f, -2.f);
        s[13].setOrigin(-10.f, -2.f);


        //------ The Main Game Loop ----------
        while (window.isOpen())
        {
            display_game(back_gr,board ,s ,rectangle,move_text,objectiv_text );
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        //---- bouton exit 
                        if (!isMoving && !isSwap)
                            click++;
                        pos = sf::Mouse::getPosition(window);
                        if (pos.x>450 && pos.x<520 && pos.y>600 && pos.y<680)
                        {
                            return 0;
                        }
                    }
                }
            }
            if (click == 1)
            {
                x0 = pos.x / ts;
                y0 = pos.y / ts;
                if (x0 > 7 || y0 > 7)
                    click = 0;
                else
                    grid[y0][x0].is_animated = 1;
            }
            if (click == 2)
            {
                grid[y0][x0].is_animated = 0;
                y1 = pos.y / ts;
                x1 = pos.x / ts;
                if (x1 > 7 || y1 > 7)
                {
                    click = 0;
                }
                else
                {

                    if (abs(y1 - y0) + abs(x1 - x0) == 1)
                    {
                        swap(grid[y0][x0], grid[y1][x1]);
                        click = 0;
                        isSwap = 1;
                        moves++;
                    }
                    else
                    {
                        click = 1;
                        grid[y1][x1].is_animated = 1;
                    }
                }
            }
            //-------- Updating
            isMoving = 0;
            update(grid,isMoving);
            //-------- Finding Matches 
            there_is_match = 0;
            destruction(grid,there_is_match,isSwap,isMoving,objectiv);
            //---- Swapping back in case there are no matches 
            if (!isMoving && isSwap && !there_is_match)
            {
                swap(grid[y0][x0], grid[y1][x1]);
                isSwap = 0;
            }

            //---- Display
            move_text.setString(std::to_string(30-moves));
            objectiv_text.setString(std::to_string(objectiv)+"/20");
            
            

            if (objectiv>19)
            {
                sf::Text win;
                win.setFont(font);
                win.setString("You win ! ");
                win.setPosition(150, 400);
                win.setCharacterSize(80);
                window.draw(win);
                window.display();
                sf::sleep(sf::milliseconds(3000));
                return 0;
            }
            else if(moves==30)
            {
                sf::Text lose;
                lose.setFont(font);
                lose.setString("You lose.");
                lose.setPosition(150, 400);
                lose.setCharacterSize(80);
                window.draw(lose);
                window.display();
                sf::sleep(sf::milliseconds(3000));
                return 0;
            }
        }
    }
};