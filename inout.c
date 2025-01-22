#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "common.h"

#define MAX_STUDENTS 10

void data_input(int count, struct student *s) {
	if (count < 1)
		return;
	if (count > MAX_STUDENTS) {
		printf("Too much data for input\n");
		return;
	}
	
	for (int i = 0; i < count; i++) {
		printf("Please enter data for student %d:\n", i + 1);
		printf("Name, Lastname, Group_ID, Course\n");
		scanf("%s %s %d %d", (s + i)->name, (s + i)->lastname, &(s + i)->group_id, &(s + i)->course);
	}
	
	return;
}


void data_output(int count, struct student *s) {
    if (count < 1) {
        printf("Nothing to show\n");
        return;
    }

    int max_name_len = strlen("Name");
    int max_lastname_len = strlen("Surname");
    int max_group_id_len = strlen("Group ID");
    int max_course_len = strlen("Course");

    for (int i = 0; i < count; i++) {
        if (strlen((s + i)->name) > max_name_len)
            max_name_len = strlen((s + i)->name);
        if (strlen((s + i)->lastname) > max_lastname_len)
            max_lastname_len = strlen((s + i)->lastname);
    }

    printf("%-*s %-*s %-*s %-*s\n",
           max_name_len+3, "Name",
           max_lastname_len+3, "Surname",
           10, "Group ID",
           10, "Course");

    for (int i = 0; i < max_name_len + max_lastname_len + 25; i++)
        printf("-");
    printf("\n");

    for (int i = 0; i < count; i++) {
        printf("%-*s %-*s %-10d %-10d\n",
               max_name_len+3, (s + i)->name,
               max_lastname_len+3, (s + i)->lastname,
               (s + i)->group_id,
               (s + i)->course);
    }
}








