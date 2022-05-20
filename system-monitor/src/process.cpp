#include <cctype>
#include <sstream>
#include <string>
#include <unistd.h>
#include <vector>

#include "linux_parser.h"
#include "process.h"


using std::string;
using std::to_string;
using std::vector;

int Process::Pid() { return Process::pid_; }

string Process::Command() { return Process::command_; }

float Process::CpuUtilization() { return Process::cpuUtilization_; }

string Process::Ram() { return Process::ram_; }

string Process::User() { return Process::user_; }

string Process::Uid() { return Process::uid_; }

long int Process::UpTime() { return Process::upTime_; }

bool Process::operator>(Process const &a) const {
  return cpuUtilization_ > a.cpuUtilization_;
}

void Process::SetPid(int pid) { Process::pid_ = pid; }

void Process::SetUser(string user) { Process::user_ = user; }

void Process::SetUid(string uid) { Process::uid_ = uid; }

void Process::SetCommand(string command) { Process::command_ = command; }

void Process::SetCpuUtilization() {
  vector<int> values = LinuxParser::Processor(Pid());
  values.emplace_back(LinuxParser::UpTime());
  Process::processor.SetProcessor(values);
  cpuUtilization_ = Process::processor.Utilization();
}

void Process::SetRam(string ram) { Process::ram_ = ram; }

void Process::SetUpTime(long int upTime) { Process::upTime_ = upTime; }