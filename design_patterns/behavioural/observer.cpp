#include <iostream>
#include <string>
#include <vector>

using namespace std;

class JobPost {
string title;
public:
    JobPost(const string & title) : title(title) {}
    string getTitle() const { return title; }
};

class JobSeeker {
string name;
public:
    JobSeeker(const string & name) : name(name) {}

    void onJobPosted(const JobPost & job) {
        cout << "Hi " << name << ", new job available: " << job.getTitle() << endl;
    }
};

class JobPostings {
vector<JobSeeker*> observers;
public:
    void addObserver(JobSeeker * js) {
        observers.push_back(js);
    }

    void notify(const JobPost & job) {
        for(auto o : observers) {
            o->onJobPosted(job);
        }
    }

    void addJob(const JobPost & job) {
        notify(job);
    }
};

int main() {
    JobPostings postings;
    postings.addObserver(new JobSeeker("Bob"));
    postings.addObserver(new JobSeeker("Alice"));

    postings.addJob(JobPost("Driver"));
}