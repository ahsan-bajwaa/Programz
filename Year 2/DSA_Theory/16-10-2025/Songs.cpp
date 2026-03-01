#include <iostream>
using namespace std;

#define SIZE 7

class MusicPlaylist
{
private:
    string songs[SIZE];
    int front, rear;

public:
    MusicPlaylist()
    {
        front = -1;
        rear = -1;
    }

    void addSong(string song)
    {
        if ((front == 0 && rear == SIZE - 1) || (rear + 1 == front))
        {
            cout << "Playlist is Full!" << endl;
            return;
        }

        if (front == -1)
            front = 0;

        rear = (rear + 1) % SIZE;
        songs[rear] = song;
    }

    void playSong()
    {
        if (front == -1)
        {
            cout << "Playlist is Empty!" << endl;
            return;
        }

        cout << "Playing \"" << songs[front] << "\"..." << endl;

        // If only one song was left
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }

    void displayPlaylist()
    {
        if (front == -1)
        {
            cout << "Playlist is Empty!" << endl;
            return;
        }

        cout << "\nCurrent Playlist Order:\n";
        int i = front;
        while (true)
        {
            cout << songs[i] << "  ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main()
{
    MusicPlaylist playlist;

    playlist.addSong("Song 1");
    playlist.addSong("Song 2");
    playlist.addSong("Song 3");
    playlist.addSong("Song 4");
    playlist.addSong("Song 5");

    cout << endl;
    playlist.displayPlaylist();

    cout << "\n--- Playing Songs ---\n";
    playlist.playSong();
    playlist.playSong();
    playlist.playSong();

    cout << endl;
    playlist.displayPlaylist();

    cout << "\n--- Adding New Songs ---\n";
    playlist.addSong("Song 6");
    playlist.addSong("Song 7");

    cout << endl;
    playlist.displayPlaylist();

    return 0;
}
