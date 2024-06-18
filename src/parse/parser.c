/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** json_parser
*/

#include "rpg.h"
#include <fcntl.h>
#include <string.h>

static char *openfile(char *file)
{
    int fd = open(file, O_RDONLY);
    char *buffer = NULL;
    struct stat st;

    if (fd == -1) {
        print("Error: could not open file\n");
        exit(84);
    }
    stat(file, &st);
    buffer = malloc(sizeof(char) * (st.st_size + 1));
    if (!buffer)
        exit(84);
    if (read(fd, buffer, st.st_size) == -1) {
        print("Error: could not read file\n");
        exit(84);
    }
    buffer[st.st_size] = '\0';
    close(fd);
    return buffer;
}

quest_t *parse_quest_details(char *quest_buffer)
{
    char *quest_line = NULL;
    quest_t *quest = init_quest();

    if (quest_buffer == NULL)
        exit(84);
    quest_line = strtok(quest_buffer, "\n");
    while (quest_line) {
        if (strstr(quest_line, "title :") == quest_line)
            quest->title = strdup(quest_line + 8);
        if (strstr(quest_line, "description :") == quest_line)
            quest->description = strdup(quest_line + 14);
        quest_line = strtok(NULL, "\n");
    }
    return quest;
}

quest_t **parse_and_fill(char *file)
{
    char **qst_files = NULL;
    int nb_qst = 0;
    char *line = NULL;
    quest_t **quests = NULL;

    if (openfile(file) == NULL)
        exit(84);
    for (line = strtok(openfile(file), "\n"); line;
        line = strtok(NULL, "\n")) {
        qst_files = realloc(qst_files, sizeof(char *) * (nb_qst + 1));
        qst_files[nb_qst] = strdup(line);
        nb_qst++;
    }
    quests = malloc(sizeof(quest_t *) * nb_qst + 1);
    for (int i = 0; i < nb_qst; i++) {
        quests[i] = parse_quest_details(openfile(qst_files[i]));
        quests[i]->id = i + 1;
    }
    quests[nb_qst] = NULL;
    return quests;
}
