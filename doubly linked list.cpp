#include <iostream>
#include <string>
using namespace std;

struct song
{
    string title;
    song *prev;
    song *next;

    song(string t)
    {
        title = t;
        next = NULL;
        prev = NULL;
    }
};

class Playlist
{
private:
    song *head;
    song *tail;
    song *current;

public:
    Playlist()
    {
        head = tail = current = NULL;
    }

    // Add song
    void addSong(string title)
    {
        song *newSong = new song(title);

        if (head == NULL)
        {
            head = tail = current = newSong;
        }
        else
        {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
    }

    // Next song
    void nextSong()
    {
        if (current != NULL && current->next != NULL)
        {
            current = current->next;
            cout << "Playing: " << current->title << endl;
        }
        else
        {
            cout << "Already at the last song." << endl;
        }
    }

    // Previous song
    void previousSong()
    {
        if (current != NULL && current->prev != NULL)
        {
            current = current->prev;
            cout << "Playing: " << current->title << endl;
        }
        else
        {
            cout << "Already at the first song." << endl;
        }
    }

    // Display forward
    void displayForward()
    {
        song *temp = head;

        cout << "\nPlaylist (Forward): ";

        while (temp != NULL)
        {
            cout << temp->title << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    // Display backward
    void displayBackward()
    {
        song *temp = tail;

        cout << "\nPlaylist (Backward): ";

        while (temp != NULL)
        {
            cout << temp->title << " -> ";
            temp = temp->prev;
        }

        cout << "NULL\n";
    }

    // Display current song
    void currentSong()
    {
        if (current != NULL)
        {
            cout << "Current Song: " << current->title << endl;
        }
        else
        {
            cout << "Playlist is empty." << endl;
        }
    }

    // Destructor
    ~Playlist()
    {
        song *temp = head;

        while (temp != NULL)
        {
            song *next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main()
{
    Playlist playlist;

    playlist.addSong("Khat");
    playlist.addSong("Wildflower");
    playlist.addSong("Ride or Die");
    playlist.addSong("Barbaad");

    playlist.displayForward();
    playlist.displayBackward();

    playlist.currentSong();

    cout << "\nForward Navigation:\n";
    playlist.nextSong();
    playlist.nextSong();
    playlist.nextSong();
    playlist.nextSong();

    cout << "\nBackward Navigation:\n";
    playlist.previousSong();
    return 0;
}
