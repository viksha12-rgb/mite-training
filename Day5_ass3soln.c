#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char name[50];
    struct Song* next;
} Song;

Song* createSong(char name[]) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    strcpy(newSong->name, name);
    newSong->next = newSong;  
    return newSong;
}
Song* insertSong(Song* last, char name[]) {
    Song* newSong = createSong(name);
    if (last == NULL) {
        return newSong;  
    }
    newSong->next = last->next;
    last->next = newSong;
    return newSong;  
}
void playSongs(Song* last, int times) {
    if (last == NULL) {
        printf("Playlist is empty!\n");
        return;
    }
    Song* current = last->next;  
    for (int i = 0; i < times; i++) {
        printf("Now Playing: %s\n", current->name);
        current = current->next;
    }
}
int main() {
    Song* playlist = NULL;
    playlist = insertSong(playlist, "Song A");
    playlist = insertSong(playlist, "Song B");
    playlist = insertSong(playlist, "Song C");
    playSongs(playlist, 5);  
    return 0;
}
