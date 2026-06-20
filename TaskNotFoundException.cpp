#include "TaskNotFoundException.h"

TaskNotFoundException::TaskNotFoundException(int taskId)
    : TasksExceptions("Task with ID " + to_string(taskId) + " not found on task board.") {}

