# Terminal TODO List (C++)

This is a simple interactive TODO list command-line app written in C++.

Features:
- Add tasks
- List tasks
- Mark tasks as complete
- Remove tasks
- Run in terminal/console

Build and run (Linux / macOS with g++):

```bash
# compile
g++ -std=c++17 main.cpp -o todo

# run
./todo
```

Example interactive session (user input shown after prompts):

1) Add task
Enter task description: Buy milk
1) Add task
Enter task description: Write code
2) List tasks
3) Mark task as complete
Enter task number to mark complete: 1
4) Remove task
Enter task number to remove: 2
5) Exit

Notes:
- This program keeps tasks in-memory for the session (no persistence).
- Task numbers are shown when listing and are used for mark/remove operations.
# codespace-lab