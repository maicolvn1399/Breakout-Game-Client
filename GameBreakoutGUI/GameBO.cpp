//
// Created by michael on 12/9/21.
//

#include "GameBO.h"

#include "GameBO.h"

bool GameBO :: init(){
    VideoMode videoMode(width, height);
    window.create(videoMode,"Break Out");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(FRAMES_PER_SECOND);

    setup();
    return true;
}

int GameBO :: exec(){
    Clock renderClock, updateClock;
    while (window.isOpen()){

        time=renderClock.getElapsedTime();
        float fFps=1000000/time.asMicroseconds();
        std::stringstream s;
        s<<"fps: "<<fFps;
        fps.setString(s.str());
        renderClock.restart();

        const Int64 frameTime = 1000000/FRAMES_PER_SECOND;
        Clock c;
        Time t=c.getElapsedTime();
        Int64 nextFrameTime=t.asMicroseconds()+frameTime;

        int loops = 0;
        while( t.asMicroseconds() < nextFrameTime && loops < MAX_FRAMESKIP)
        {
            processEvents();
            updateTime=updateClock.restart().asMilliseconds();
            update();
            t=c.getElapsedTime();
            loops++;
        }

        display();
    }
    return EXIT_SUCCESS;
}

void GameBO :: processEvents(){
    Event event;
    while (window.pollEvent(event))
    {
        if ( (event.type == Event::Closed) ||
             ((event.type == Event::KeyPressed) && (event.key.code==Keyboard::Escape)) )
            window.close();
        else
        if ((event.type == Event::KeyPressed) && (gameState == INTRO))
            gameState=PLAYING;
    }
}

void GameBO::update(){
    if (gameState!=PLAYING)
        return;

    updatePlayer();
    checkCollisions();
    updateBall();

    // detect if game is over
    if (playerLives < 0)
        gameState=GAME_LOST;
}

void GameBO :: setup(){
    top.setPosition(0, 0);
    top.setSize(Vector2f(width, borderSize));

    left.setPosition(0, borderSize);
    left.setSize(Vector2f(borderSize, height+borderSize));

    right.setPosition(width-borderSize, borderSize);
    right.setSize(Vector2f(borderSize, height+borderSize));

    bottom.setPosition(0, height+2*borderSize);
    bottom.setSize(Vector2f(width, borderSize));

    top.setFillColor(Color(100,100,100));
    top.setOutlineColor(Color::Black);
    top.setOutlineThickness(2);

    left.setFillColor(Color(100,100,100));
    left.setOutlineColor(Color::Black);
    left.setOutlineThickness(2);

    right.setFillColor(Color(100,100,100));
    right.setOutlineColor(Color::Black);
    right.setOutlineThickness(2);

    bottom.setFillColor(Color(100,100,100));
    bottom.setOutlineColor(Color::Black);
    bottom.setOutlineThickness(2);

    /**
    ball.setPosition(width/2, height-margin);
    ball.setSize(Vector2f(20, 20));
    ball.setFillColor(Color::Green);
    ball.setOutlineColor(Color::Red);
    ball.setOutlineThickness(2);

    player.setSize(Vector2f(90,borderSize));
    player.setPosition(width/2-45, height-margin-borderSize);
    player.setFillColor(Color(0,122,245));
    player.setOutlineColor(Color::Green);
    player.setOutlineThickness(3);
    **/


    title.setString("Break Out!");
    title.setFont(font);
    title.setCharacterSize(50);
    title.setPosition(width/2-title.getGlobalBounds().width/2,100);
    title.setColor(Color::Blue);

    start.setString("Press any key to start");
    start.setFont(font);
    start.setCharacterSize(30);
    start.setPosition(width/2-start.getGlobalBounds().width/2,400);
    start.setColor(Color::Red);

    won.setString("You have won this game.\n\n Congratulations !");
    won.setFont(font);
    won.setCharacterSize(20);
    won.setPosition(width/2-won.getGlobalBounds().width/2,height/2-won.getGlobalBounds().height/2);
    won.setColor(Color::Green);

    lost.setString("You have lost this game, \n better luck next time!");
    lost.setFont(font);
    lost.setCharacterSize(20);
    lost.setPosition(width/2-lost.getGlobalBounds().width/2,height/2-lost.getGlobalBounds().height/2);
    lost.setColor(Color::Red);

    score.setString("0");
    score.setFont(font);
    score.setCharacterSize(30);
    score.setPosition(width/2+score.getGlobalBounds().width/2,height-60);
    score.setColor(Color(0,0,100,50));

    lives.setString("5");
    lives.setFont(font);
    lives.setCharacterSize(50);
    lives.setPosition(width/2-lives.getGlobalBounds().width/2,height-60);
    lives.setColor(Color(0,0,100,50));

    fps.setString("0");
    fps.setFont(font);
    fps.setCharacterSize(30);
    fps.setPosition(fps.getGlobalBounds().width/2,height-40);
    fps.setColor(Color(52,0,100,50));

    resetGame();
    gameState=INTRO;

    // grid.setup()
    /**
    grid.setDimensions(7,5);
    grid.left=borderSize+5;
    grid.top=borderSize+5;
    grid.width=width-2*borderSize-10;
    grid.height=250;
    grid.init();
     **/

}

void GameBO :: display(){
    window.clear(Color::White);
    switch(gameState)
    {
        case INTRO:
            window.draw(title);
            window.draw(start);
            break;
        case PLAYING:
            window.draw(left);
            window.draw(right);
            //grid.display(window);
            //window.draw(player);
            //window.draw(ball);
            window.draw(score);
            window.draw(lives);
            window.draw(top);
            window.draw(bottom);
            window.draw(fps);
            break;
        case GAME_WON:
            window.draw(won);
            break;
        case GAME_LOST:
            window.draw(lost);
            break;
    }
    window.display();
}

void GameBO::updatePlayer(){
    // move player 1 pad
    if (Keyboard::isKeyPressed(Keyboard::Left)){
        //player.move(-moveDistance*updateTime/50.0,0);
    }else
    if (Keyboard::isKeyPressed(Keyboard::Right)){
        //player.move(moveDistance*updateTime/50.0,0);
    }
}

void GameBO :: checkCollisions(){
    // block players pad inside the play area

    if ( intersects(player,left) || intersects(player,right) )
    {
        FloatRect l=left.getGlobalBounds();
        FloatRect r=right.getGlobalBounds();
        Vector2f p=player.getPosition();
        p.x=clamp(p.x,l.left+l.width+5,r.left-player.getGlobalBounds().width-5);
        player.setPosition(p.x,p.y);
    }

    // ball collides with top, left and right
    if (intersects(ball,top))
    {
        FloatRect t=top.getGlobalBounds();
        FloatRect b=ball.getGlobalBounds();
        ballSpeed.y= abs(ballSpeed.y);
        int u = t.top + t.height - b.top;
        ball.move(0,2*u);

    }
    if (intersects(ball,left))
    {
        FloatRect l=left.getGlobalBounds();
        FloatRect b=ball.getGlobalBounds();
        ballSpeed.x= abs(ballSpeed.x);
        int u = l.left + l.width - b.left;
        b.left = l.left +  l.width + u;
        ball.setPosition(b.left,b.top);

    }

    if (intersects(ball,right))
    {
        FloatRect r=right.getGlobalBounds();
        FloatRect b=ball.getGlobalBounds();
        ballSpeed.x= -abs(ballSpeed.x);
        int u = b.left + b.width - r.left ;
        b.left = r.left -  b.width - u;
        ball.setPosition(b.left,b.top);

    }

    if (intersects(ball,bottom)){

        playerLives--;
        std::stringstream str;
        str << playerLives;
        lives.setString(str.str());
        lives.setPosition(width/2-lives.getGlobalBounds().width/2,height-60);
        resetBall();
    }
    // ball collides with player
    if (intersects(ball,player))
    {
        FloatRect p= player.getGlobalBounds();
        FloatRect b= ball.getGlobalBounds();

        //let o be the center of p
        Vector2f o=Vector2f(p.left+p.width/2,p.top+p.height/2);
        //om: vector from o to the center of the ball M
        Vector2f om=Vector2f(b.left+b.width/2-o.x,b.top+b.height/2-o.y);
        // let's scale om to square dimensions and act as if p is a square
        om.x/=p.width;
        om.y/=p.height;
        // reflect the ball according to the angle of om
        float angle=atan2(om.y,om.x);
        if ( angle < -PI/4 && angle > -3*PI/4) //top
        {
            ballSpeed.y = -abs(ballSpeed.y);//in case of double contact
            ballSpeed.x= (b.left+b.width/2 - p.left- p.width/2) / 200;
            int u = b.top + b.height - p.top;
            b.top = p.top - b.height - u;
            ball.setPosition(b.left,b.top);
            //increase ball speed by 2%
            ballSpeed.x*=1.02f;
            ballSpeed.y*=1.02f;

        }
    }
    //ball collides with grid
    if (grid.collide(ball,ballSpeed,playerScore))
    {

        playerScore+=200;
        std::stringstream str;
        str << playerScore << " pts  ";
        score.setString(str.str());
        score.setPosition(width/2+score.getGlobalBounds().width/2-margin,height-60);
    }
    // check for end of game
    if (grid.isGameWon())
        gameState=GAME_WON;
    if (playerLives<=0)
        gameState=GAME_LOST;

}
