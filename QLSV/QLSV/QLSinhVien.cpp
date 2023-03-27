#include "QLSinhVien.h"

List QLSinhVien::findStudentLessThanAVG(const List& list)
{
    if (list.head == nullptr) {
        throw "Empty list";
        return List();
    }

    double sum = 0;
    int numberOfStudent = 0;

    Node* current = list.head;
    
    while (current != nullptr) {
        sum += current->data.stdAvg();
        numberOfStudent++;
        
        current = current->next;
    }

    double classAvg = sum * 1.0f / numberOfStudent;

    // Find student who have avg less than 
    // class avg mark.
    List* result = new List();
    current = list.head;

    while (current != nullptr) {
        if (current->data.stdAvg() < classAvg) {
            Node* p = Node::makeNode(current->data);
            
            result->addTail(p);
        }

        current = current->next;
    }

    return *result;
}

void QLSinhVien::updateStudentList(const Student& target, List &list)
{
    Node* p = Node::makeNode(target);
    list.addTail(p);

    QLSinhVien::writeToFile(list);
}

vector<string> QLSinhVien::typingStudent(const List&list)
{
    vector<string> result;
    
    Node* current = list.head;
    
    while (current != nullptr) {
        result.push_back(current->data.typeOfStudent());
        current = current->next;
    }

    return result;
}

void QLSinhVien::printOutListWithRank(const List& list)
{
    vector<string> types = QLSinhVien::typingStudent(list);
    Node* current = list.head;
    int iter = 0;
    while (current != nullptr) {
        cout << current->data.toString() << " - Type: " << types[iter] << endl;
        iter++;

        current = current->next;
    }
}

List QLSinhVien::findStudentSameDOB(const List& list)
{
    char* currentDay = new char[12];
    currentDay = getCurrentDay();

    List* result = new List();
    
    Node* current = list.head;

    while (current != nullptr) {
        if (strcmp(currentDay, current->data.dob()) == 0) {
            Node* p = Node::makeNode(current->data);
            result->addTail(p);
        }

        current = current->next;
    }

    return *result;
}

void QLSinhVien::writeToFile(const List& target)
{
    ofstream ofs(fileName);
    
    Node* current = target.head;
    while (current != nullptr) {
        ofs << current->data.toString(1) << endl;
        current = current->next;
    }

    ofs.close();
}

List QLSinhVien::readFromFile(const string&)
{
    string line;
    ifstream ifs(fileName);
    
    if (!ifs.is_open()) {
        throw "Error when open file to read!";
        return List();
    }
    
    List* result = new List();

    while (getline(ifs, line)) {
        Student student = Student::parse(line);
        Node* node = Node::makeNode(student);
        
        result->addTail(node);
    }

    ifs.close();
    return *result;
}
