# To-Do CLI in C++

A small command line app to add tasks, list them, mark them done,
delete them, and save them to a file so they are still there next time
you run it. Built with a simple Task class and file handling in C++.

## How to run

```bash
g++ TodoCLI.cpp -o todo
./todo
```

## Features

- Add a task
- List all tasks with their status (pending or done)
- Mark a task done
- Delete a task
- Tasks are saved to `tasks.txt`, so they persist between runs
