#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stdexcept>

using namespace std;

// Base class for all field types
class Field {
public:
    virtual ~Field() = default;
    virtual void print() const = 0;
    virtual string toString() const = 0;
};

// Derived class for single string field
class StringField : public Field {
public:
    string value;
    StringField(const string& val) : value(val) {}
    void print() const override {
        cout << value;
    }
    string toString() const override {
        return value;
    }
};

// Derived class for single integer field
class IntegerField : public Field {
public:
    int value;
    IntegerField(int val) : value(val) {}
    void print() const override {
        cout << value;
    }
    string toString() const override {
        return to_string(value);
    }
};

// Derived class for single double field
class DoubleField : public Field {
public:
    double value;
    DoubleField(double val) : value(val) {}
    void print() const override {
        cout << value;
    }
    string toString() const override {
        return to_string(value);
    }
};

// Derived class for single char field
class CharField : public Field {
public:
    char value;
    CharField(char val) : value(val) {}
    void print() const override {
        cout << value;
    }
    string toString() const override {
        return string(1, value);
    }
};

// Derived class for multi-string field (vector of strings)
class MultiStringField : public Field {
public:
    vector<string> values;
    MultiStringField(const vector<string>& val) : values(val) {}
    void print() const override {
        for (const auto& val : values) {
            cout << val << " ";
        }
    }
    string toString() const override {
        string result;
        for (const auto& val : values) {
            if (!result.empty()) result += ":";
            result += val;
        }
        return result;
    }
};

// Derived class for multi-integer field (vector of integers)
class MultiIntegerField : public Field {
public:
    vector<int> values;
    MultiIntegerField(const vector<int>& val) : values(val) {}
    void print() const override {
        for (const auto& val : values) {
            cout << val << " ";
        }
    }
    string toString() const override {
        string result;
        for (const auto& val : values) {
            if (!result.empty()) result += ":";
            result += to_string(val);
        }
        return result;
    }
};

// Derived class for multi-double field (vector of doubles)
class MultiDoubleField : public Field {
public:
    vector<double> values;
    MultiDoubleField(const vector<double>& val) : values(val) {}
    void print() const override {
        for (const auto& val : values) {
            cout << val << " ";
        }
    }
    string toString() const override {
        string result;
        for (const auto& val : values) {
            if (!result.empty()) result += ":";
            result += to_string(val);
        }
        return result;
    }
};

// Derived class for multi-char field (vector of chars)
class MultiCharField : public Field {
public:
    vector<char> values;
    MultiCharField(const vector<char>& val) : values(val) {}
    void print() const override {
        for (const auto& val : values) {
            cout << val << " ";
        }
    }
    string toString() const override {
        string result;
        for (const auto& val : values) {
            if (!result.empty()) result += ":";
            result += val;
        }
        return result;
    }
};

// Function to split a string by a delimiter
void split(const string& str, char delimiter, vector<string>& out) {
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter)) {
        out.push_back(token);
    }
}

// Function to log exceptions
void logException(ofstream& logFile, const string& message, const string& command = "") {
    logFile << "Exception: " << message << endl;
    if (!command.empty()) {
        logFile << command << endl;
    }
}

// Custom function to parse quoted strings
string parseQuotedString(stringstream& ss) {
    char ch;
    ss >> ch; // Skip the opening quote
    string result;
    while (ss.get(ch)) {
        if (ch == '"') break;
        result += ch;
    }
    return result;
}

// Function to process search command
void processSearchCommand(const vector<string>& originalLines, const vector<map<string, Field*>>& records, const string& value, const string& fieldName, ofstream& outputFile) {
    outputFile << "search \"" << value << "\" in \"" << fieldName << "\"" << endl;
    bool found = false;
    // Loop through the records to find matching fields
    for (size_t i = 0; i < records.size(); ++i) {
        const auto& record = records[i];
        auto it = record.find(fieldName);
        if (it != record.end() && it->second->toString().find(value) != string::npos) {
            found = true;
            outputFile << originalLines[i] << endl;
        }
    }
    if (!found) {
        outputFile << endl;  // No match found
    }
}

// Function to process sort command
void processSortCommand(const vector<string>& originalLines, vector<map<string, Field*>>& records, const string& fieldName, ofstream& outputFile) {
    outputFile << "sort \"" << fieldName << "\"" << endl;
    vector<size_t> indices(records.size());
    // Initialize indices with values from 0 to records.size() - 1
    for (size_t i = 0; i < indices.size(); ++i) {
        indices[i] = i;
    }

    // Sort indices based on the records
    sort(indices.begin(), indices.end(), [&records, &fieldName](size_t a, size_t b) {
        const auto& aField = records[a].find(fieldName);
        const auto& bField = records[b].find(fieldName);
        if (aField != records[a].end() && bField != records[b].end()) {
            return aField->second->toString() < bField->second->toString();
        }
        return false;
    });

    // Print the sorted records
    for (size_t i : indices) {
        outputFile << originalLines[i] << endl;
    }
}

// Function to log records
void logRecord(ofstream& outputFile, const vector<string>& fields) {
    for (size_t i = 0; i < fields.size(); ++i) {
        if (i > 0) {
            outputFile << "|";
        }
        outputFile << fields[i];
    }
    outputFile << endl;
}

// Function to check if a field name is valid
bool isFieldNameValid(const string& fieldName, const vector<string>& headers) {
    for (const auto& header : headers) {
        vector<string> parts;
        split(header, ':', parts);
        if (parts[0] == fieldName) {
            return true;
        }
    }
    return false;
}

int main() {
    ifstream file("data.txt");
    ofstream outputFile("output.txt");
    if (!file.is_open()) {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    string line;

    // Read and parse the header line
    if (!getline(file, line)) {
        cerr << "Failed to read header line" << endl;
        return 1;
    }
    vector<string> headers;
    split(line, '|', headers);
    for (size_t i = 0; i < headers.size(); ++i) {
        vector<string> parts;
        split(headers[i], ':', parts);
        if (i > 0) {
            outputFile << "|";
        }
        outputFile << parts[0];
    }
    outputFile << endl;

    // Vector of maps to store the records
    vector<map<string, Field*>> records;

    // Vector to store the original lines
    vector<string> originalLines;

    // Set to keep track of unique first fields for duplicate detection
    set<string> uniqueFirstFields;

    // Read and parse each data line
    while (getline(file, line)) {
        vector<string> fields;
        split(line, '|', fields);

        if (fields.size() != headers.size()) {
            logException(outputFile, "missing field");
            logRecord(outputFile, fields);
            continue; // Skip invalid lines
        }

        string firstField = fields[0];
        if (uniqueFirstFields.find(firstField) != uniqueFirstFields.end()) {
            logException(outputFile, "duplicate entry");
            logRecord(outputFile, fields);
            continue; // Skip duplicate entries
        } else {
            uniqueFirstFields.insert(firstField);
        }

        map<string, Field*> record;
        // Parse each field and store it in the record map
        for (size_t i = 0; i < headers.size(); ++i) {
            string header = headers[i];
            string field = fields[i];
            vector<string> headerParts;
            split(header, ':', headerParts);

            string fieldName = headerParts[0];
            string fieldType = headerParts[1];
            string fieldFormat = headerParts[2];

            try {
                if (fieldType == "string") {
                    if (fieldFormat == "multi") {
                        vector<string> values;
                        split(field, ':', values);
                        record[fieldName] = new MultiStringField(values);
                    } else {
                        record[fieldName] = new StringField(field);
                    }
                } else if (fieldType == "integer") {
                    if (fieldFormat == "multi") {
                        vector<string> values;
                        split(field, ':', values);
                        vector<int> intValues;
                        for (const auto& val : values) {
                            intValues.push_back(stoi(val));
                        }
                        record[fieldName] = new MultiIntegerField(intValues);
                    } else {
                        record[fieldName] = new IntegerField(stoi(field));
                    }
                } else if (fieldType == "double") {
                    if (fieldFormat == "multi") {
                        vector<string> values;
                        split(field, ':', values);
                        vector<double> doubleValues;
                        for (const auto& val : values) {
                            doubleValues.push_back(stod(val));
                        }
                        record[fieldName] = new MultiDoubleField(doubleValues);
                    } else {
                        record[fieldName] = new DoubleField(stod(field));
                    }
                } else if (fieldType == "char") {
                    if (fieldFormat == "multi") {
                        vector<char> charValues;
                        for (const auto& val : field) {
                            if (val != ':') {
                                charValues.push_back(val);
                            }
                        }
                        record[fieldName] = new MultiCharField(charValues);
                    } else {
                        record[fieldName] = new CharField(field[0]);
                    }
                }
            } catch (const invalid_argument& e) {
                logException(outputFile, "missing field");
                logRecord(outputFile, fields);
                continue;
            }
        }
        records.push_back(record);
        originalLines.push_back(line);
    }

    // Log the number of unique entries
    outputFile << uniqueFirstFields.size() << " unique entries" << endl;

    // Read commands from commands.txt
    ifstream commandFile("commands.txt");
    if (!commandFile.is_open()) {
        cerr << "Unable to open command file" << endl;
        return 1;
    }

    // Process each command
    while (getline(commandFile, line)) {
        stringstream ss(line);
        string command;
        ss >> command;
        if (command == "search") {
            string value = parseQuotedString(ss);
            string in;
            ss >> in;
            string fieldName = parseQuotedString(ss);
            if (isFieldNameValid(fieldName, headers)) {
                processSearchCommand(originalLines, records, value, fieldName, outputFile);
            } else {
                logException(outputFile, "command is wrong", line);
            }
        } else if (command == "sort") {
            string fieldName = parseQuotedString(ss);
            if (isFieldNameValid(fieldName, headers)) {
                processSortCommand(originalLines, records, fieldName, outputFile);
            } else {
                logException(outputFile, "command is wrong", line);
            }
        } else {
            logException(outputFile, "command is wrong", line);
        }
    }

    // Cleanup dynamically allocated memory
    for (auto& record : records) {
        for (auto& entry : record) {
            delete entry.second;
        }
    }

    return 0;
}
