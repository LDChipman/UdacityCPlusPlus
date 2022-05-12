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

// TODO: Return the system's CPU
Processor &System::Cpu() { return cpu_; }

// TODO: Return a container composed of the system's processes
vector<Process> &System::Processes() { return processes_; }

std::string System::Kernel() { return LinuxParser::Kernel(); }

// TODO: Return the system's memory utilization
float System::MemoryUtilization() { return LinuxParser::MemoryUtilization(); }

std::string System::OperatingSystem() {

  // return "Test Results: " + std::to_string(LinuxParser::MemoryUtilization());

  return LinuxParser::OperatingSystem();
}

int System::RunningProcesses() { return LinuxParser::RunningProcesses(); }

int System::TotalProcesses() { return LinuxParser::TotalProcesses(); }

long int System::UpTime() { return LinuxParser::UpTime(); }
