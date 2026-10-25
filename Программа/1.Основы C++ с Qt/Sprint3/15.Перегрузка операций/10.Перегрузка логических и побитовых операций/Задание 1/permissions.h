#pragma once

#include <bitset>
#include <iostream>
#include <sstream>

enum Permissions { READ = 1, WRITE = 2, EXECUTE = 4 };

class FileAccess {
public:
    FileAccess() : permissions_(0) {}

    void SetPermission(Permissions perm) {
      permissions_ = permissions_ | static_cast<int>(perm);
    }
   
    bool CheckPermission(Permissions perm) {
      if (static_cast<int>(perm) & permissions_) {
        return true;
      }
      return false;
    }
    
    void RemovePermission(Permissions perm) {
      permissions_ = permissions_ & ~static_cast<int>(perm);
    }
    
    void TogglePermission(Permissions perm) {
      permissions_ ^= static_cast<int>(perm);
    }
    
    std::string ToString() {
        std::ostringstream s;
        s << std::bitset<4>(permissions_);
        return s.str();
    }
private:
    int permissions_;
};