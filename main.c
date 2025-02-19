#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024


typedef struct LogNode {
    char log_entry[MAX_LINE];
    struct LogNode *next;
} LogNode;


LogNode* create_node(char *log_entry) {
    LogNode *new_node = (LogNode*)malloc(sizeof(LogNode));
    if (!new_node) {
        perror("Bellek tahsisi basarisiz");
        exit(EXIT_FAILURE);
    }
    strncpy(new_node->log_entry, log_entry, MAX_LINE);
    new_node->next = NULL;
    return new_node;
}


void append_node(LogNode **head, char *log_entry) {
    LogNode *new_node = create_node(log_entry);
    if (*head == NULL) {
        *head = new_node;
    } else {
        LogNode *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}


void print_logs(LogNode *head) {
    LogNode *current = head;
    printf("\n--- Syslog Kayitlari ---\n");
    while (current) {
        printf("%s", current->log_entry);
        current = current->next;
    }
}


void free_list(LogNode *head) {
    LogNode *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    
    char *log_file_path = "/var/log/syslog";

    FILE *logfile = fopen(log_file_path, "r");
    if (!logfile) {
        perror("Log dosyasi acilamadi");
        return EXIT_FAILURE;
    }

    LogNode *log_list = NULL;
    char line[MAX_LINE];

    
    while (fgets(line, sizeof(line), logfile)) {
        append_node(&log_list, line);
    }
    fclose(logfile);

  
    print_logs(log_list);

    
    free_list(log_list);
    
    return EXIT_SUCCESS;
}

