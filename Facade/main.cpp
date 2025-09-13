#include <iostream>
using namespace std;

// Subsystem classes
class CPU {
public:
    void freeze() { cout << "CPU freezing...\n"; }
    void jump(long pos) { cout << "CPU jumping to " << pos << "\n"; }
    void execute() { cout << "CPU executing...\n"; }
};

class Memory {
public:
    void load(long pos, string data) {
        cout << "Loading data '" << data << "' at position " << pos << "\n";
    }
};

class HardDrive {
public:
    string read(long lba, int size) {
        return "OS_BOOT_SECTOR";
    }
};

// Facade class
class ComputerFacade {
private:
    CPU cpu;
    Memory memory;
    HardDrive hd;

public:
    void startComputer() {
        cpu.freeze();
        string bootData = hd.read(0, 10);
        memory.load(0, bootData);
        cpu.jump(0);
        cpu.execute();
        cout << "Computer started successfully!\n";
    }
};

// Client code
int main() {
    ComputerFacade computer;
    computer.startComputer();  // Client only calls one method
    return 0;
}
