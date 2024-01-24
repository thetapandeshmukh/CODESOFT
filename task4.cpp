// Build a simple console-based to-do list
// manager that allows users to add, view, and
// delete tasks 
// Task Input: Allow users to input tasks they want to add to the list.
// Add Task: Implement a function to add tasks to the list.
// View Tasks: Display the list of tasks with their status (completed or
// pending).
// Mark Task as Completed: Allow users to mark tasks as completed.
// Remove Task: Provide an option to remove tasks from the list.

#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

void addTask(std::vector<Task> &tasks, const std::string &description) {
    Task newTask = {description, false};
    tasks.push_back(newTask);
    std::cout << "Task added: " << description << std::endl;
}

void viewTasks(const std::vector<Task> &tasks) {
    std::cout << "Tasks:" << std::endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". ";
        if (tasks[i].completed) {
            std::cout << "[Completed] ";
        } else {
            std::cout << "[Pending] ";
        }
        std::cout << tasks[i].description << std::endl;
    }
}

void markCompleted(std::vector<Task> &tasks, size_t index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
        std::cout << "Task marked as completed: " << tasks[index].description << std::endl;
    } else {
        std::cout << "Invalid task index!" << std::endl;
    }
}

void removeTask(std::vector<Task> &tasks, size_t index) {
    if (index >= 0 && index < tasks.size()) {
        std::cout << "Task removed: " << tasks[index].description << std::endl;
        tasks.erase(tasks.begin() + index);
    } else {
        std::cout << "Invalid task index!" << std::endl;
    }
}

int main() {
    std::vector<Task> tasks;

    char choice;
    do {
        std::cout << "\nOptions:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1': {
                std::cin.ignore(); // Clear the buffer
                std::string task;
                std::cout << "Enter task description: ";
                std::getline(std::cin, task);
                addTask(tasks, task);
                break;
            }
            case '2':
                viewTasks(tasks);
                break;
            case '3': {
                size_t index;
                std::cout << "Enter the task number to mark as completed: ";
                std::cin >> index;
                markCompleted(tasks, index - 1);
                break;
            }
            case '4': {
                size_t index;
                std::cout << "Enter the task number to remove: ";
                std::cin >> index;
                removeTask(tasks, index - 1);
                break;
            }
            case '5':
                std::cout << "Exiting program..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != '5');

    return 0;
}
