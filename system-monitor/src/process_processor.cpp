#include <string>
#include <unistd.h>
#include <vector>


#include "process_processor.h"

#include "linux_parser.h"

double ProcessProcessor::Utilization() {
  return (double)((double)CalcTotalTime() / (double)sysconf(_SC_CLK_TCK)) /
         (double)CalcSeconds();
}

void ProcessProcessor::SetUtime(int utime) { utime_ = utime; }

void ProcessProcessor::SetStime(int stime) { stime_ = stime; }

void ProcessProcessor::SetCutime(int cutime) { cutime_ = cutime; }

void ProcessProcessor::SetCstime(int cstime) { cstime_ = cstime; }

void ProcessProcessor::SetStarttime(int starttime) { starttime_ = starttime; }

void ProcessProcessor::SetUptime(int uptime) { uptime_ = uptime; }

void ProcessProcessor::SetProcessor(std::vector<int> values) {

  SetUtime(values[0]);
  SetStime(values[1]);
  SetCutime(values[2]);
  SetStime(values[3]);
  SetStarttime(values[4]);
  SetUptime(values[5]);
}

int ProcessProcessor::CalcTotalTime() {
  return utime_ + stime_ + cutime_ + cstime_;
}

int ProcessProcessor::CalcSeconds() {
  return uptime_ - (starttime_ / sysconf(_SC_CLK_TCK));
}