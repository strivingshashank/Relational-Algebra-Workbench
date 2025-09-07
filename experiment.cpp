/* To keep things simple, access specifiers are set to -> public */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>

#define NEW_LINE std::cout << '\n';

constexpr bool DEBUG_MODE = false;

enum class ReturnStatus {
  success,
  failure
};

// enum class LogStatus {
//   update
// };

using string = std::string;
using serial_t = size_t;

template <typename KEY_TYPE, typename VALUE_TYPE>
using map = std::map<KEY_TYPE, VALUE_TYPE>;

template <typename KEY_TYPE, typename VALUE_TYPE>
using unordered_map = std::unordered_map<KEY_TYPE, VALUE_TYPE>;

template <typename DATA_TYPE>
using set = std::set<DATA_TYPE>;

template <typename DATA_TYPE>
using vector = std::vector<DATA_TYPE>;


// template <typename DATA_TYPE>
class Cell {
private:
  string value;
  
public:
  // Default Constructor
  Cell() : value("NULL") { }
  
  // Parameterized Constructor
  Cell(string value) : value(value) {
    // Blah-Blah Black Sheep
  }

  string getValue() const {
    return value;
  }

  void setValue(const string& newValue) {
    value = newValue;
  }
};

class Attribute {
  string title;
  unordered_map<serial_t, Cell> records;

public:
  // Default Constructor
  Attribute(string title) : title(title) { }

  // Parameterized Constructor
  // Attribute(string title, serial_t serialKey) : title(title), records({{serialKey, Cell()}}) { }

  void setTitle(const string& newTitle) {
    title = newTitle;
  }

  string getTitle() const {
    return title;
  }

  string getValueAtRecord(serial_t serialKey) {
    return records[serialKey].getValue();
  }

  void updateRecord(serial_t serialKey, string cellValue) {
    /* Validate if the [serialKey] is already present in the table. */
    if (records.find(serialKey) != records.end()) {
      NEW_LINE
      std::cerr << "Serial key [" << serialKey << "] is already present, updating to Value [" << cellValue << "].";
      NEW_LINE
    } 

    records[serialKey] = cellValue;

    if (DEBUG_MODE) {
      std::cout << "UPDATED";
      NEW_LINE
      std::cout << "Attribute [\"" << title << "\"] @ Serial [\"" << serialKey << "\"] : Value [\"" << cellValue << "\"]";
      NEW_LINE 
    }
  }
};

class Table {
public:
  serial_t nextSerialKey;
  set<serial_t> serialKeySet;
  unordered_map<string, Attribute> attributes; 

  Table() : nextSerialKey(0) { }

  bool findAttribute(const string& attribute) {
    if (attributes.find(attribute) == attributes.end()) {
      return false;
    }

    return true;
  }

  void updateAttribute(const string& newAttributeTitle) {
    /* Validate if the [newAttributeTitle] is already present in the table. */
    if (attributes.find(newAttributeTitle) != attributes.end()) {
      NEW_LINE
      std::cerr << "Cannot insert attribute [" << newAttributeTitle << "]";
      NEW_LINE
      std::cerr << "Already present";
      NEW_LINE

    }

    /* If the attribute is not present, add it. */
    // attributes[newAttributeTitle] = Attribute(newAttributeTitle);
    attributes.emplace(newAttributeTitle, Attribute(newAttributeTitle));

    if (DEBUG_MODE) {
      std::cout << "UPDATED";
      NEW_LINE
      std::cout << "Attribute [\"" << newAttributeTitle << "\"] with Title [\"" << newAttributeTitle << "\"]";
      NEW_LINE 
    }
  }

  ReturnStatus insertInstance(const vector<string>& operandAttributes, const vector<string>& operandCellValues) {
    if (operandAttributes.empty() || operandCellValues.empty()) {
      NEW_LINE
      std::cerr << "Cannot insert instance with empty attributes or cell values";
      NEW_LINE

      return ReturnStatus::failure;
    }

    /* Defaults to all cell to be not NULL. Needs to be changed if the cell supports nullable values. */
    if (operandAttributes.size() != operandCellValues.size()) {
      NEW_LINE
      std::cerr << "Cannot insert instance with different-sized attributes and cell values";
      NEW_LINE

      return ReturnStatus::failure;
    }

    for (int index = 0; index < operandAttributes.size(); index++) {
      if (! findAttribute(operandAttributes[index])) {
        NEW_LINE
        std::cerr << "Cannot insert at attribute [" << operandAttributes[index] << "]";
        NEW_LINE
        std::cerr << "No such attribute"; 
        NEW_LINE

        return ReturnStatus::failure;
      }

      attributes.at(operandAttributes[index]).updateRecord(nextSerialKey, operandCellValues[index]);
      serialKeySet.insert(nextSerialKey);
    }

    nextSerialKey++;
    return ReturnStatus::success;
  }

  void printTable() {
    vector<string> attributeTitles;

    for (const auto& attribute : attributes) {
      attributeTitles.push_back(attribute.second.getTitle());
    }

    for (const auto& title : attributeTitles) {
      std::cout << title << " | ";
    }

    NEW_LINE

    for (const auto& serialKey : serialKeySet) {
      for (const auto& title : attributeTitles) {
        std::cout << attributes.at(title).getValueAtRecord(serialKey) << " | ";
      }

      NEW_LINE
    }
  }
};

int main() {
  vector<string> attributes;
  
  attributes.push_back("name");
  attributes.push_back("age");
  attributes.push_back("address");
  attributes.push_back("contact number");
  attributes.push_back("sex");
  attributes.push_back("email");
  
  vector<string> cellValues = {"Shashank", "21", "Kaulagarh", "9520074060", "M", "shashankvermayoyo@gmail.como"};

  Table table;

  for (const string& attributeTitle : attributes) {
    table.updateAttribute(attributeTitle);
  }

  // table.updateAttribute(attribute1);
  
  table.insertInstance(attributes, cellValues);

  table.printTable();

  return 0;
}