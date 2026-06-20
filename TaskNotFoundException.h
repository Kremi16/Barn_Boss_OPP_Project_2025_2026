#pragma once
#include"TasksExceptions.h"

class TaskNotFoundException:public TasksExceptions
{
public:
	explicit TaskNotFoundException(int taskId);
};

