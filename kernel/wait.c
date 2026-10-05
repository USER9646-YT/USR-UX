typedef enum {
    STATE_READY,
    STATE_RUNNING,
    STATE_SLEEPING,  // Paused, waiting for an event
    STATE_ZOMBIE     // Finished executing, but parent hasn't collected exit code yet
} process_state_t;

typedef struct pcb {
    pid_t pid;
    pid_t parent_pid;
    process_state_t state;
    int exit_code;         // Stored here when exit() is called
    // ... memory layouts, page tables, saved registers ...
} pcb_t;
