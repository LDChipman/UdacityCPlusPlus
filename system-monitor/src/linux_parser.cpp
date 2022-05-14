#include <dirent.h>
#include <sstream>
#include <string>
#include <unistd.h>
#include <vector>

#include "linux_parser.h"

using std::stof;
using std::string;
using std::to_string;
using std::vector;

string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;
}

string LinuxParser::Kernel() {
  string os, kernel, version;
  string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >> version >> kernel;
  }
  return kernel;
}

// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR *directory = opendir(kProcDirectory.c_str());
  struct dirent *file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

float LinuxParser::MemoryUtilization() {
  int value;
  float memTotal;
  float memFree;
  string name;
  string line;
  std::ifstream stream(kProcDirectory + kMeminfoFilename);

  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      while (linestream >> name >> value) {
        if (name == "MemTotal:")
          memTotal = value;
        if (name == "MemFree:") {
          memFree = value;
          return (memTotal - memFree) / memTotal;
        }
      }
    }
  }
  return -1.0;
}

long LinuxParser::UpTime() {
  long seconds;
  string line;
  std::ifstream stream(kProcDirectory + kUptimeFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> seconds;
  }

  return seconds;
}

// TODO: Read and return the number of jiffies for the system
long LinuxParser::Jiffies() { return 0; }

// TODO: Read and return the number of active jiffies for a PID
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::ActiveJiffies(int pid [[maybe_unused]]) { return 0; }

// TODO: Read and return the number of active jiffies for the system
long LinuxParser::ActiveJiffies() { return 0; }

// TODO: Read and return the number of idle jiffies for the system
long LinuxParser::IdleJiffies() { return 0; }

vector<string> LinuxParser::CpuUtilization() {
  string value1, value2, value3, value4, value5, value6, value7, value8, value9,
      value10;
  vector<string> values;
  string name;
  string line;
  std::ifstream stream(kProcDirectory + kStatFilename);

  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      while (linestream >> name >> value1 >> value2 >> value3 >> value4 >>
             value5 >> value6 >> value7 >> value8 >> value9 >> value10) {
        if (name == "cpu") {
          values = {value1, value2, value3, value4, value5,
                    value6, value7, value8, value9, value10};
          return values;
        }
      }
    }
  }
  return {};
}

int LinuxParser::TotalProcesses() {
  int value;
  string name;
  string line;
  std::ifstream stream(kProcDirectory + kStatFilename);

  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      while (linestream >> name >> value) {
        if (name == "processes") {
          return value;
        }
      }
    }
  }
  return -1;
}

int LinuxParser::RunningProcesses() {
  int value;
  string name;
  string line;
  std::ifstream stream(kProcDirectory + kStatFilename);

  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      while (linestream >> name >> value) {
        if (name == "procs_running") {
          return value;
        }
      }
    }
  }
  return -1;
}

string LinuxParser::Command(int pid) {
  string command;
  string line;
  std::ifstream stream(kProcDirectory + to_string(pid) + kCmdlineFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> command;
  }

  return command;
}

string LinuxParser::Ram(int pid) {
  int value;
  string name;
  string line;
  std::ifstream stream(kProcDirectory + to_string(pid) + kStatusFilename);

  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      while (linestream >> name >> value) {
        if (name == "VmSize:") {
          return to_string(value / 1000);
        }
      }
    }
  }
  return "-1";
}

string LinuxParser::Uid(int pid) {
  int value;
  string name;
  string line;
  std::ifstream stream(kProcDirectory + to_string(pid) + kStatusFilename);

  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      while (linestream >> name >> value) {
        if (name == "Uid:") {
          return to_string(value);
        }
      }
    }
  }
  return "-1";
}

string LinuxParser::User(string uid) {
  string line;
  string user;
  string x;
  string value;
  std::ifstream filestream(kPasswordPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ':', ' ');
      std::istringstream linestream(line);
      while (linestream >> user >> x >> value) {
        if (value == uid) {
          return user;
        }
      }
    }
  }
  return "-1";
}

long LinuxParser::UpTime(int pid) {

  int value;
  int dummy;
  string dummyString;
  string line;
  std::ifstream stream(kProcDirectory + to_string(pid) + kStatFilename);

  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> dummy >> dummyString >> dummyString >> dummy >> dummy >>
        dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >>
        dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >>
        value;
    return UpTime() - value / sysconf(_SC_CLK_TCK);
  }
  return -1;
}
