#ifndef PROCESS_H
#define PROCESS_H

#include "process_processor.h"
#include <string>

/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
public:
  int Pid();
  std::string User();
  std::string Uid();
  std::string Command();
  float CpuUtilization();
  std::string Ram();
  long int UpTime();
  bool operator>(Process const &a) const;
  void SetPid(int pid);
  void SetUser(std::string user);
  void SetUid(std::string uid);
  void SetCommand(std::string command);
  void SetCpuUtilization();
  void SetRam(std::string ram);
  void SetUpTime(long int uptime);

private:
  int pid_;
  std::string user_;
  std::string uid_;
  std::string command_;
  float cpuUtilization_;
  std::string ram_;
  long int upTime_;
  ProcessProcessor processor;
};

#endif