#include <iostream>
#include <vector>

using namespace std;

struct Task {
  string name;
  bool completed;
};

// Function to add a new task to the list
void AddTask(vector<Task>& tasks) {
  Task newTask;
  string taskName;

  cout << "Please enter the task name (or quit): ";
  while (getline(cin, taskName) && taskName != "quit") {
    if (!taskName.empty()) {
      newTask.name = taskName;
      newTask.completed = false;
      tasks.push_back(newTask);
      cout << "Task added successfully!" << endl;
      cout << "Please enter the next task name (or quit): ";
    }
  }
}

// Function to view all tasks in the list
void ViewTasks(const vector<Task>& tasks) {
  if (tasks.empty()) {
    cout << "There are no tasks." << endl;
    return;
  }

  for (const auto& task : tasks) {
    cout << "Task: " << task.name << ", Status: "
         << (task.completed ? "Completed" : "Pending") << endl;
  }
}

// Function to mark a task as completed
void MarkTaskAsCompleted(vector<Task>& tasks) {
  int index;
  cout << "Enter the index of the task to mark as completed: ";
  cin >> index;
  index--;

  if (index < 0 || index >= tasks.size()) {
    cout << "Invalid index." << endl;
    return;
  }

  tasks[index].completed = true;
  cout << "Task marked as completed!" << endl;
}

// Function to remove a task from the list
void RemoveTask(vector<Task>& tasks) {
  int index;
  cout << "Enter the index of the task to remove: ";
  cin >> index;
 index--;

  if (index < 0 || index >= tasks.size()) {
    cout << "Invalid index." << endl;
    return;
  }

  tasks.erase(tasks.begin() + index);
  cout << "Task removed successfully!" << endl;
}

int main() {
  vector<Task> tasks;
  int choice;

  do {
    cout << "---------- To-Do List App----------" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";

    cin >> choice;

    switch (choice) {
      case 1:
        AddTask(tasks);
        break;
      case 2:
        ViewTasks(tasks);
        break;
      case 3:
        MarkTaskAsCompleted(tasks);
        break;
      case 4:
        RemoveTask(tasks);
        break;
      case 0:
        cout << "Exiting..." << endl;
        break;
      default:
        cout << "Invalid choice." << endl;
        break;
    }
  } while (choice != 0);

  return 0;
}