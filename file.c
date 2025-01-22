#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "common.h"

int data_save(int count, struct student *s, const char *file) {
	int fd;
	ssize_t bw = 0;
	int data_size = 0;
	
	if (count < 1)
		return 0;
		
	data_size = count * sizeof(struct student);
	
	if (!s || !file)
		return -DATA_SAVE_ERR_INPUT;
		
	fd = open(file, O_CLOEXEC | O_CREAT |  O_WRONLY | O_APPEND , 0600);
	if (fd < 0){
		return -DATA_SAVE_ERR_OPEN;
	}
	
	bw = write(fd, s, data_size);
	if (bw < data_size){
		close(fd);
		return -DATA_SAVE_ERR_WRITE;
	}
	
	close(fd);
	return DATA_SAVE_OK;
}

struct student *data_read(const char *file, int *count) {
    int fd;
    ssize_t br = 0;
    *count = 0;
    struct student *data = NULL;
    struct student temp;

    if (!file) {
        return NULL;
    }

    fd = open(file, O_RDWR, 0600);
    if (fd < 0) {
        printf("Error opening file: %m\n");
        return NULL;
    }

    while ((br = read(fd, &temp, sizeof(struct student))) == sizeof(struct student)) {
        struct student *new_data = realloc(data, sizeof(struct student) * (*count + 1));
        if (!new_data) {
            printf("Realloc failed\n");
            free(data);
            data = NULL;
            goto exit;
        }

        data = new_data;
        data[*count] = temp;
        (*count)++;
    }

    if (br != 0 && br != sizeof(struct student)) {
        printf("Error reading file: %m\n");
        free(data);
        data = NULL;
    }

exit:
    close(fd);
    return data;
}







