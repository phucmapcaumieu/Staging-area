#pragma once
#include "List.h"

class QLSinhVien
{
	inline static const string fileName = "QLSV.txt";
public:
	List list;

public:
	/// <summary>
	/// Hàm tìm các sinh viên có điểm trung bình nhỏ hơn điểm trung bình của
	/// lớp, ghi danh sách các sinh viên này vào tập tin.
	/// </summary>
	/// <returns></returns>
	static List findStudentLessThanAVG(const List&);
	
	/// <summary>
	/// Hàm thêm một sinh viên mới vào danh sách và cập nhật lại vào tập tin
	/// danh sách sinh viên.
	/// </summary>
	/// <param name=""></param>
	static void updateStudentList(const Student&, List&);
	
	/// <summary>
	/// Hàm xếp loại sinh viên có thứ tự
	/// </summary>
	/// <returns>Thứ tự loại các sinh viên</returns>
	static vector<string> typingStudent(const List&);


	/// <summary>
	/// Hàm xuất danh sách sinh viên có thông tin xếp loại.
	/// </summary>
	static void printOutListWithRank(const List&);

	/// <summary>
	/// Hàm tìm tất cả các sinh viên có cùng ngày sinh nhật trong ngày hiện tại.
	/// </summary>
	/// <returns></returns>
	static List findStudentSameDOB(const List&);

public:
	/// <summary>
	/// Hàm ghi danh sách sinh viên lên tập tin.
	/// </summary>
	/// <param name=""></param>
	/// <param name=""></param>
	static void writeToFile(const List&);

	/// <summary>
	/// Hàm đọc danh sách sinh viên từ tập tin.
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	static List readFromFile(const string&);

};

