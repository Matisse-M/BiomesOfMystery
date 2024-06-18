/*
** EPITECH PROJECT, 2024
** test_path
** File description:
** find_assets
*/

#include "rpg.h"
#include <string.h>

int find_and_chdir_to_repo(const char *repo_name, char *path, size_t path_len)
{
    char command[1024];
    FILE *fp = NULL;

    snprintf(command, sizeof(command),
        "find / -type d -name '%s' 2>/dev/null", repo_name);
    fp = popen(command, "r");
    if (fp == NULL)
        return -1;
    if (fgets(path, path_len, fp) != NULL) {
        path[strcspn(path, "\n")] = '\0';
        pclose(fp);
        return 0;
    }
    pclose(fp);
    fprintf(stderr, "Repository not found: %s\n", repo_name);
    return -1;
}

static void write_in_second_file(rpg_t *rpg)
{
    char *filename = my_scat(rpg->name, "/ressources/beginquests.txt");
    FILE *file = fopen(filename, "w");

    if (file == NULL)
        exit(84);
    fprintf(file, "%s\n", my_scat(rpg->name, "/ressources/quest0.txt"));
    fprintf(file, "%s\n", my_scat(rpg->name, "/ressources/quest1.txt"));
    fprintf(file, "%s\n", my_scat(rpg->name, "/ressources/quest2.txt"));
    fprintf(file, "%s\n", my_scat(rpg->name, "/ressources/quest3.txt"));
    fprintf(file, "%s\n", my_scat(rpg->name, "/ressources/quest4.txt"));
    fclose(file);
}

static void write_in_file(rpg_t *rpg)
{
    char *filename = my_scat(rpg->name, "/ressources/all_quests.txt");
    FILE *file = fopen(filename, "w");

    if (file == NULL)
        exit(84);
    fprintf(file, "%s\n", my_scat(rpg->name, "/ressources/quest5.txt"));
    fprintf(file, "%s\n", my_scat(rpg->name, "/ressources/quest6.txt"));
    fprintf(file, "%s\n", my_scat(rpg->name, "/ressources/quest7.txt"));
    fprintf(file, "%s\n", my_scat(rpg->name, "/ressources/quest8.txt"));
    fprintf(file, "%s\n", my_scat(rpg->name, "/ressources/quest9.txt"));
    fprintf(file, "%s\n", my_scat(rpg->name, "/ressources/quest10.txt"));
    fprintf(file, "%s\n", my_scat(rpg->name, "/ressources/quest11.txt"));
    fclose(file);
}

void test_assets(rpg_t *rpg)
{
    char path[1024];

    if (rpg == NULL)
        exit(84);
    if (find_and_chdir_to_repo("asset_content_bom", path, sizeof(path)) == 0) {
        rpg->name = strdup(path);
    }
    write_in_second_file(rpg);
    write_in_file(rpg);
}
