#include <algorithm>
#include <cstddef>
#include <set>
#include <string>
#include <unistd.h>
#include <vector>

#include "linux_parser.h"
#include "process.h"
#include "processor.h"
#include "system.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

Processor &System::Cpu() {

  if (!setInitial) {
    cpu_.SetInitPrev();
  }

  cpu_.SetProcessor(LinuxParser::CpuUtilization());

  return cpu_;
}

vector<Process> &System::Processes() {

  pids_ = LinuxParser::Pids();
  Process process;
  processes_ = {};
  for (int pid : pids_) {
    process.SetPid(pid);
    process.SetUid(LinuxParser::Uid(process.Pid()));
    process.SetUser(LinuxParser::User(process.Uid()));
    process.SetCommand(LinuxParser::Command(process.Pid()));
    process.SetCpuUtilization();
    process.SetRam(LinuxParser::Ram(process.Pid()));
    process.SetUpTime(LinuxParser::UpTime(process.Pid()));
    processes_.emplace_back(process);
  }

  std::sort(processes_.begin(), processes_.end(),
            [](Process a, Process b) { return a > b; });

  return processes_;
}

std::string System::Kernel() { return LinuxParser::Kernel(); }

float System::MemoryUtilization() { return LinuxParser::MemoryUtilization(); }

std::string System::OperatingSystem() { return LinuxParser::OperatingSystem(); }

int System::RunningProcesses() { return LinuxParser::RunningProcesses(); }

int System::TotalProcesses() { return LinuxParser::TotalProcesses(); }

long int System::UpTime() { return LinuxParser::UpTime(); }
