#include <stdio.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_USERNAME_LENGTH 50

void clear_screen() {
    // ANSI escape code to clear screen
    printf("\033[2J\033[H");
}

void help() {
    printf("SeminaryOS Commands:\n");
    printf("help       - Show this help message\n");
    printf("clear      - Clear the screen\n");
    printf("echo [msg] - Print message\n");
    printf("exit       - Exit SeminaryOS\n");
}

void prompt(const char *username) {
    printf("%s@SeminaryOS> ", username);
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char username[MAX_USERNAME_LENGTH];

    clear_screen();
    printf("Welcome to SeminaryOS!\n");
    printf("Please enter your username: ");
    fgets(username, sizeof(username), stdin);
    
    // Remove newline if present
    username[strcspn(username, "\n")] = 0;

    clear_screen();
    printf("Hello, %s! Type 'help' to see available commands.\n", username);

    while (1) {
        prompt(username);
        fgets(command, sizeof(command), stdin);
        
        // Remove newline
        command[strcspn(command, "\n")] = 0;

        if (strncmp(command, "help", 4) == 0 && (command[4] == '\0' || command[4] == ' ')) {
            help();
        } else if (strncmp(command, "clear", 5) == 0 && (command[5] == '\0' || command[5] == ' ')) {
            clear_screen();
        } else if (strncmp(command, "echo ", 5) == 0) {
            printf("%s\n", command + 5);
        } else if (strcmp(command, "exit") == 0) {
            printf("Goodbye, %s!\n", username);
            break;
        } else if (strlen(command) == 0) {
            // Do nothing on empty input
            continue;
        } else {
            printf("Unknown command: %s\n", command);
        }
    }

    return 0;
}
