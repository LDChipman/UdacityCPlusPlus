#include <string>
#include <vector>

#include "processor.h"

#include "linux_parser.h"

double Processor::Utilization() {
  double CPU = GetCpu();
  UpdatePrev();
  return CPU;
}

double Processor::GetCpu() {
  return (double)(CalcTotald() - CalcIdled()) / (double)CalcTotald();
}

void Processor::SetUser(int user) { user_ = user; }

void Processor::SetNice(int nice) { nice_ = nice; }

void Processor::SetSystem(int system) { system_ = system; }

void Processor::SetIdle(int idle) { idle_ = idle; }

void Processor::SetIowait(int iowait) { iowait_ = iowait; }

void Processor::SetIrq(int irq) { irq_ = irq; }

void Processor::SetSoftIrq(int softIrq) { softIrq_ = softIrq; }

void Processor::SetSteal(int steal) { steal_ = steal; }

void Processor::SetGuest(int guest) { guest_ = guest; }

void Processor::SetGuestNice(int guestNice) { guestNice_ = guestNice; }

void Processor::SetProcessor(std::vector<int> values) {

  SetUser(values[0]);
  SetNice(values[1]);
  SetSystem(values[2]);
  SetIdle(values[3]);
  SetIowait(values[4]);
  SetIrq(values[5]);
  SetSoftIrq(values[6]);
  SetSteal(values[7]);
  SetGuest(values[8]);
  SetGuestNice(values[10]);
}

int Processor::CalcIdle() { return idle_ + iowait_; }

int Processor::CalcNonIdle() {
  return user_ + nice_ + system_ + irq_ + softIrq_ + steal_;
}

int Processor::CalcTotal() { return CalcIdle() + CalcNonIdle(); }

int Processor::CalcPrevIdle() { return prevIdle_ + prevIowait_; }

int Processor::CalcPrevNonIdle() {
  return prevUser_ + prevNice_ + prevSystem_ + prevIrq_ + prevSoftIrq_ +
         prevSteal_;
}

int Processor::CalcPrevTotal() { return CalcPrevIdle() + CalcPrevNonIdle(); }

int Processor::CalcTotald() { return CalcTotal() - CalcPrevTotal(); }

int Processor::CalcIdled() { return CalcIdle() - CalcPrevIdle(); }

void Processor::UpdatePrev() {
  prevUser_ = user_;
  prevNice_ = nice_;
  prevSystem_ = system_;
  prevIdle_ = idle_;
  prevIowait_ = iowait_;
  prevIrq_ = irq_;
  prevSoftIrq_ = softIrq_;
  prevSteal_ = steal_;
  prevGuest_ = guest_;
  prevGuestNice_ = guestNice_;
}

void Processor::SetInitPrev() {
  prevUser_ = 0;
  prevNice_ = 0;
  prevSystem_ = 0;
  prevIdle_ = 0;
  prevIowait_ = 0;
  prevIrq_ = 0;
  prevSoftIrq_ = 0;
  prevSteal_ = 0;
  prevGuest_ = 0;
  prevGuestNice_ = 0;
}