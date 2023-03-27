#include "Student.h"
#include "Node.h"
#include "List.h"
#include "QLSinhVien.h"

int main() {
	
	List studentList = QLSinhVien::readFromFile("QLSV.txt");
	
	cout << studentList.toString() << endl;

	cout << "Cac sinh vien ngu la: " << endl;
	List sinhVienNgu = QLSinhVien::findStudentLessThanAVG(studentList);
	cout << sinhVienNgu.toString() << endl;


	Student newStudent = Student::parse("Cu to vl,007,13/12/2003,10,1,2");

	QLSinhVien::updateStudentList(newStudent, studentList);

	cout << "Sau khi cap nhat thang cu to vl:" << endl;
	List another = QLSinhVien::readFromFile("QLSV.txt");
	cout << another.toString() << endl;

	QLSinhVien::printOutListWithRank(another);
}