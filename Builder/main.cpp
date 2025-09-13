#include <iostream>
using namespace std;

// Product
class Desktop {
public:
    int storageSize;
    int ramSize;
    int gpuSize;
    int graphicsCardSize;

    void showSpecs() {
        cout << "Storage: " << storageSize << " GB, "
             << "RAM: " << ramSize << " GB, "
             << "GPU: " << gpuSize << " GB, "
             << "Graphics Card: " << graphicsCardSize << " GB" << endl;
    }
};

// Abstract Builder
class DesktopBuilder {
public:
    virtual void setStorage() = 0;
    virtual void setRAM() = 0;
    virtual void setGPU() = 0;
    virtual void setGraphicsCard() = 0;
    virtual Desktop* getDesktop() = 0;
    virtual ~DesktopBuilder() {}
};

// Concrete Builder 1 - Normal Desktop
class NormalDesktopBuilder : public DesktopBuilder {
    Desktop* desktop;
public:
    NormalDesktopBuilder() { desktop = new Desktop(); }
    void setStorage() override { desktop->storageSize = 512; }
    void setRAM() override { desktop->ramSize = 8; }
    void setGPU() override { desktop->gpuSize = 2; }
    void setGraphicsCard() override { desktop->graphicsCardSize = 2; }
    Desktop* getDesktop() override { return desktop; }
};

// Concrete Builder 2 - Gaming Desktop
class GamingDesktopBuilder : public DesktopBuilder {
    Desktop* desktop;
public:
    GamingDesktopBuilder() { desktop = new Desktop(); }
    void setStorage() override { desktop->storageSize = 2048; }
    void setRAM() override { desktop->ramSize = 32; }
    void setGPU() override { desktop->gpuSize = 8; }
    void setGraphicsCard() override { desktop->graphicsCardSize = 12; }
    Desktop* getDesktop() override { return desktop; }
};

// Director
class Director {
public:
    Desktop* buildDesktop(DesktopBuilder* builder) {
        builder->setStorage();
        builder->setRAM();
        builder->setGPU();
        builder->setGraphicsCard();
        return builder->getDesktop();
    }
};

// Client
int main() {
    Director director;

    NormalDesktopBuilder normalBuilder;
    Desktop* normalPC = director.buildDesktop(&normalBuilder);
    cout << "Normal Desktop Specs:\n";
    normalPC->showSpecs();

    GamingDesktopBuilder gamingBuilder;
    Desktop* gamingPC = director.buildDesktop(&gamingBuilder);
    cout << "\nGaming Desktop Specs:\n";
    gamingPC->showSpecs();

    return 0;
}
