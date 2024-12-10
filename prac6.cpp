#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Record {
    std::string name;
    std::string dob; 
    std::string telephone;

    bool operator<(const Record& other) const {
        return name < other.name;
    }
};

void displayRecords(const std::vector<Record>& records) {
    std::cout << "Records:\n";
    for (const auto& record : records) {
        std::cout << "Name: " << record.name 
                  << ", DOB: " << record.dob 
                  << ", Telephone: " << record.telephone << std::endl;
    }
}

void searchRecord(const std::vector<Record>& records, const std::string& name) {
    auto it = std::find_if(records.begin(), records.end(), [&name](const Record& record) {
        return record.name == name;
    });

    if (it != records.end()) {
        std::cout << "Record found: Name: " << it->name 
                  << ", DOB: " << it->dob 
                  << ", Telephone: " << it->telephone << std::endl;
    } else {
        std::cout << "Record not found for name: " << name << std::endl;
    }
}

int main() {
    std::vector<Record> records;
    int n;

    std::cout << "Enter number of records: ";
    std::cin >> n;
    std::cin.ignore(); 

    for (int i = 0; i < n; ++i) {
        Record record;
        std::cout << "Enter Name: ";
        std::getline(std::cin, record.name);
        std::cout << "Enter DOB (YYYY-MM-DD): ";
        std::getline(std::cin, record.dob);
        std::cout << "Enter Telephone: ";
        std::getline(std::cin, record.telephone);
        records.push_back(record);
    }

    std::sort(records.begin(), records.end());

    displayRecords(records);

    std::string searchName;
    std::cout << "Enter name to search: ";
    std::getline(std::cin, searchName);
    searchRecord(records, searchName);

    return 0;
}
