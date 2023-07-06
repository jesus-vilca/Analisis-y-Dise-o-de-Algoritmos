#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task {
    int start;
    int finish;
};

bool compare(Task a, Task b) {
    return a.finish < b.finish;
}

vector<Task> greedyTaskScheduling(vector<Task>& tasks) {
    sort(tasks.begin(), tasks.end(), compare);

    vector<Task> schedule;
    schedule.push_back(tasks[0]);

    int lastFinish = tasks[0].finish;

    for (int i = 1; i < tasks.size(); i++) {
        if (tasks[i].start >= lastFinish) {
            schedule.push_back(tasks[i]);
            lastFinish = tasks[i].finish;
        }
    }

    return schedule;
}

int main() {
    vector<Task> tasks = {
        {1, 4},
        {3, 5},
        {0, 6},
        {5, 7},
        {3, 8},
        {5, 9},
        {6, 10},
        {8, 11},
        {8, 12},
        {2, 13},
        {12, 14}
    };

    vector<Task> schedule = greedyTaskScheduling(tasks);

    cout << "Tareas programadas: " << endl;
    for (const Task& task : schedule) {
        cout << "Inicio: " << task.start << ", Fin: " << task.finish << endl;
    }

    return 0;
}
