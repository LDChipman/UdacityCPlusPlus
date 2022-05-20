#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <vector>

class Processor {
public:
  double GetCpu();

  void SetUser(int user);
  void SetNice(int nice);
  void SetSystem(int system);
  void SetIdle(int idle);
  void SetIowait(int iowait);
  void SetIrq(int irq);
  void SetSoftIrq(int softIrq);
  void SetSteal(int steal);
  void SetGuest(int guest);
  void SetGuestNice(int guestNice);

  void SetProcessor(std::vector<int> values);

  double Utilization();

  void SetInitPrev();

private:
  int user_;
  int nice_;
  int system_;
  int idle_;
  int iowait_;
  int irq_;
  int softIrq_;
  int steal_;
  int guest_;
  int guestNice_;

  int prevUser_;
  int prevNice_;
  int prevSystem_;
  int prevIdle_;
  int prevIowait_;
  int prevIrq_;
  int prevSoftIrq_;
  int prevSteal_;
  int prevGuest_;
  int prevGuestNice_;

  int CalcIdle();
  int CalcNonIdle();
  int CalcTotal();

  int CalcPrevIdle();
  int CalcPrevNonIdle();
  int CalcPrevTotal();

  int CalcTotald();
  int CalcIdled();

  void UpdatePrev();
};

#endif