#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a song
typedef struct {
    char title[100];
    char artist[100];
    int duration; // in seconds
} Song;

// Structure for a playlist
typedef struct {
    Song *songs;
    int count;
    int capacity;
} Playlist;

// Function to initialize a playlist
void initPlaylist(Playlist *pl) {
    pl->count = 0;
    pl->capacity = 2;
    pl->songs = (Song *)malloc(pl->capacity * sizeof(Song));
    if (pl->songs == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}

// Function to add a song to the playlist
void addSong(Playlist *pl, const char *title, const char *artist, int duration) {
    if (pl->count >= pl->capacity) {
        pl->capacity *= 2;
        pl->songs = (Song *)realloc(pl->songs, pl->capacity * sizeof(Song));
        if (pl->songs == NULL) {
            printf("Memory reallocation failed!\n");
            exit(1);
        }
    }
    strcpy(pl->songs[pl->count].title, title);
    strcpy(pl->songs[pl->count].artist, artist);
    pl->songs[pl->count].duration = duration;
    pl->count++;
}

// Function to print the playlist
void printPlaylist(const Playlist *pl) {
    printf("\nYour Playlist:\n");
    for (int i = 0; i < pl->count; i++) {
        printf("%d. %s - %s [%d sec]\n", i + 1, pl->songs[i].title, pl->songs[i].artist, pl->songs[i].duration);
    }
}

// Function to remove a song by index
void removeSong(Playlist *pl, int index) {
    if (index < 0 || index >= pl->count) {
        printf("Invalid index!\n");
        return;
    }
    for (int i = index; i < pl->count - 1; i++) {
        pl->songs[i] = pl->songs[i + 1];
    }
    pl->count--;
}

// Function to free allocated memory
void freePlaylist(Playlist *pl) {
    free(pl->songs);
}

// Interactive function to get song details
void userInputSong(Playlist *pl) {
    char title[100], artist[100];
    int duration;
    printf("Enter song title: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0'; // Remove newline
    printf("Enter artist name: ");
    fgets(artist, sizeof(artist), stdin);
    artist[strcspn(artist, "\n")] = '\0';
    printf("Enter song duration (sec): ");
    scanf("%d", &duration);
    getchar(); // Consume newline
    addSong(pl, title, artist, duration);
}

int main() {
    Playlist myPlaylist;
    initPlaylist(&myPlaylist);
    
    printf("Welcome to C-Spotify!\n");
    int choice;
    do {
        printf("\n1. Add Song\n2. View Playlist\n3. Remove Song\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline
        
        if (choice == 1) {
            userInputSong(&myPlaylist);
        } else if (choice == 2) {
            printPlaylist(&myPlaylist);
        } else if (choice == 3) {
            int index;
            printf("Enter song index to remove: ");
            scanf("%d", &index);
            getchar(); // Consume newline
            removeSong(&myPlaylist, index - 1);
        }
    } while (choice != 4);
    
    freePlaylist(&myPlaylist);
    printf("Goodbye!\n");
    return 0;
}

