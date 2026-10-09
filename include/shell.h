// USER9646's shell.h
#ifndef SHELL_H
#define SHELL_H

// This is my half-assed attempt at trying to split the shell from the kernel, since in a UNIX environment, you cannot make a singular program be the monolith. Login manager can wait for fucks sake. It also specifies input buffer size too

#define MAX_USERNAME 32
#define MAX_PASSWORD 32
#define MAX_HOSTNAME 64

#define INPUT_BUFFER_SIZE 65536


typedef struct {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    char hostname[MAX_HOSTNAME];
    int is_setup;
} user_config_t;

extern user_config_t config;
extern int shell_exit_flag;

void read_line(char* buffer, int max_len);
void setup_wizard(void);
void shell(void);
void print_prompt_path(void);
void login_prompt(void);
void init(void);

// JESUS FUCKING CHRIST JUST WORK PLEASSEEEEE

#endif
