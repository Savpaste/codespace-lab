#include <iostream>
#include <vector>
#include <string>
#include <limits>

struct Task {
    std::string description;
    bool done = false;
};

void show_menu() {
    std::cout << "\nTODO List - choose an option:\n";
    std::cout << "1) Add task\n";
    std::cout << "2) List tasks\n";
    std::cout << "3) Mark task as complete\n";
    std::cout << "4) Remove task\n";
    std::cout << "5) Exit\n";
    std::cout << "Enter choice: ";
}

void list_tasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks in the list.\n";
        return;
    }
    std::cout << "\nCurrent tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        const Task &t = tasks[i];
        std::cout << (i + 1) << ") [" << (t.done ? 'X' : ' ') << "] " << t.description << "\n";
    }
}

void add_task(std::vector<Task>& tasks) {
    std::cout << "Enter task description: ";
    std::string desc;
    std::getline(std::cin, desc);
    if (desc.find_first_not_of(" \t\n\r") == std::string::npos) {
        std::cout << "Empty description, task not added.\n";
        return;
    }
    tasks.push_back(Task{desc, false});
    std::cout << "Task added.\n";
}

void mark_complete(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to mark.\n";
        return;
    }
    std::cout << "Enter task number to mark complete: ";
    int id;
    if (!(std::cin >> id)) {
        std::cout << "Invalid input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (id < 1 || static_cast<size_t>(id) > tasks.size()) {
        std::cout << "No task with that number.\n";
        return;
    }
    tasks[id - 1].done = true;
    std::cout << "Task " << id << " marked complete.\n";
}

void remove_task(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to remove.\n";
        return;
    }
    std::cout << "Enter task number to remove: ";
    int id;
    if (!(std::cin >> id)) {
        std::cout << "Invalid input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (id < 1 || static_cast<size_t>(id) > tasks.size()) {
        std::cout << "No task with that number.\n";
        return;
    }
    tasks.erase(tasks.begin() + (id - 1));
    std::cout << "Task " << id << " removed.\n";
}

int main() {
    std::vector<Task> tasks;
    while (true) {
        show_menu();
        int choice;
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                add_task(tasks);
                break;
            case 2:
                list_tasks(tasks);
                break;
            case 3:
                mark_complete(tasks);
                break;
            case 4:
                remove_task(tasks);
                break;
            case 5:
                std::cout << "Exiting. Goodbye!\n";
                return 0;
            default:
                std::cout << "Unknown choice. Please enter 1-5.\n";
        }
    }
    return 0;
}
