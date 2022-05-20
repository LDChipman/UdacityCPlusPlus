#ifndef PROCESS_PROCESSOR_H
#define PROCESS_PROCESSOR_H

#include <vector>

class ProcessProcessor {
public:
  void SetUtime(int utime);
  void SetStime(int stime);
  void SetCutime(int cutime);
  void SetCstime(int cstime);
  void SetStarttime(int starttime);
  void SetUptime(int uptime);

  void SetProcessor(std::vector<int> values);

  double Utilization();

private:
  int utime_;
  int stime_;
  int cutime_;
  int cstime_;
  int starttime_;
  int uptime_;

  int CalcTotalTime();
  int CalcSeconds();
};

#endif