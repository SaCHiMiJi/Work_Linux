#include <bits/stdc++.h>
using namespace std;

struct Job
{
    char app;
    int users;
    string available_machines;
};

int count_assigned_users(const Job &job, const string &supercomputers)
{
    int count = 0;
    for (char machine : job.available_machines)
    {
        int machine_id = machine - '0';
        if (supercomputers[machine_id] == job.app)
        {
            count++;
        }
    }
    return count;
}

bool assign_machine(const Job &job, string &supercomputers)
{
    int users_assigned = count_assigned_users(job, supercomputers);
    for (char machine : job.available_machines)
    {
        int machine_id = machine - '0';
        if (supercomputers[machine_id] == '_' && users_assigned < job.users)
        {
            supercomputers[machine_id] = job.app;
            users_assigned++;
        }
    }
    return users_assigned == job.users;
}

int main()
{
    int N;
    cin >> N;

    vector<Job> jobs(N);
    for (int i = 0; i < N; i++)
    {
        char app;
        int users;
        string available_machines;
        cin >> app >> users >> available_machines;
        getchar(); // To read the semicolon ';'
        jobs[i] = {app, users, available_machines};
    }

    string supercomputers(10, '_');
    for (const auto &job : jobs)
    {
        if (!assign_machine(job, supercomputers))
        {
            cout << "!" << endl;
            return 0;
        }
    }

    cout << supercomputers << endl;
    return 0;
}
