#include <iostream>
using namespace std;


class MediaPlayer 
{
public:
    virtual void play() 
    {
        cout << "Playing media" << endl;
    }
};

class MusicPlayer : public MediaPlayer
{
public:
    void play() override 
    {
        cout << "Playing music ->" << endl;
    }
};

class AdvancedMusicPlayer : public MusicPlayer 
{
public:
    void play() override 
    {
        cout << "Playing music with advanced features" << endl;
    }
};

int main() 
{
    MediaPlayer player1;
    MusicPlayer player2;
    AdvancedMusicPlayer player3;

    player1.play();
    player2.play();
    player3.play(); 

    return 0;
}