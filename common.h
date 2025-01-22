#define MAX_STUDENTS 10

enum {
	DATA_SAVE_OK,
	DATA_SAVE_ERR_INPUT,
	DATA_SAVE_ERR_OPEN,
	DATA_SAVE_ERR_WRITE,
	DATA_READ_ERR_FILE
};

struct student {
	char name[20];
	char lastname[20];
	int group_id;
	int course;
};
