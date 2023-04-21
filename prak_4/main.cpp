#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Devices {
public:
	virtual void poll() {
		std::cout << "Device name" << std::endl;
	}
};

class ElectricalEnergyMeters : public Devices {
public:
	void poll() override{
		std::cout << "Electrical Energy Meters" << std::endl;
	}
};

class BlocksInputSignals : public Devices {
public:
	void poll() override {
		std::cout << "Blocks Input Signals" << std::endl;
	}
};

class HeatingControlUnits : public Devices {
public:
	void poll() override {
		std::cout << "Heating Control Units" << std::endl;
	}
};

int main() {
	vector<Devices*> devices;

	ifstream file("Devices.txt");
	string device_name;
	while (!file.eof())
	{
		file >> device_name;
		if (device_name == "Mercury230") {
			ElectricalEnergyMeters* Mercury230 = new ElectricalEnergyMeters;
			devices.push_back(Mercury230);
		}
		else if (device_name == "NevaMT314") {
			ElectricalEnergyMeters* NevaMT314 = new ElectricalEnergyMeters;
			devices.push_back(NevaMT314);
		}
		else if (device_name == "EnergymeterCE308") {
			ElectricalEnergyMeters* EnergymeterCE308 = new ElectricalEnergyMeters;
			devices.push_back(EnergymeterCE308);
		}
		else if (device_name == "ReallabNL") {
			BlocksInputSignals* ReallabNL = new BlocksInputSignals;
			devices.push_back(ReallabNL);
		}
		else if (device_name == "DeviceelectroPRE") {
			BlocksInputSignals* DeviceelectroPRE = new BlocksInputSignals;
			devices.push_back(DeviceelectroPRE);
		}
		else if (device_name == "EnergoserviceENMV") {
			BlocksInputSignals* EnergoserviceENMV = new BlocksInputSignals;
			devices.push_back(EnergoserviceENMV);
		}
		else if (device_name == "OumanS203") {
			HeatingControlUnits* OumanS203 = new HeatingControlUnits;
			devices.push_back(OumanS203);
		}
		else if (device_name == "OvenTRM232") {
			HeatingControlUnits* OvenTRM232 = new HeatingControlUnits;
			devices.push_back(OvenTRM232);
		}
	}
	file.close();
	for (int i = 0; i < devices.size(); i++) {
		devices[i]->poll();
	}
}