1. Làm lại bài số phức với một phương thức thiết lập duy nhất cho phép quan điểm một số thực như một số phức đặc biệt (phần ảo bằng 0). Định nghĩa các phép toán +, -, *, /, = =, !=, >, >=, <, <= trên số phức. Định nghĩa phép toán << và >> để xuất và nhập dữ liệu vào số phức.

2. Làm lại bài phân số với các phương thức thiết lập cho phép sử dụng một số nguyên như một phân số đặc biệt (mẫu số bằng 1). Định nghĩa các phép toán +, -, *, /, = =, != , >, >=, <, <= trên phân số. Định nghĩa phép toán << và >> để xuất và nhập dữ liệu vào phân số.

3. Định nghĩa lớp dữ liệu CTimeSpan để biểu diễn khái niệm khoảng thời gian, các hàm thành phần và các phép toán cần thiết (+, -, ==, !=, >, >=, <, <=). 

4. Định nghĩa lớp CTime biểu diễn khái niệm thời điểm có các thành phần giờ phút giây. Định nghĩa các phép toán +, - (cộng, trừ thêm một số nguyên giây), - (phép trừ hai CTime để được một CTimSpan), ++, -- (thêm bớt một giây). Phép toán <<, >> để xuất, nhập dữ liệu loại CTime. 

5. Định nghĩa lớp CDate biểu diễn khái niệm ngày, tháng, năm với các phép toán +, - (cộng, trừ thêm một số ngày), ++, -- (thêm bớt một ngày), - (khoảng cách giữa hai CDate tính bằng ngày). Phép toán <<, >> để xuất, nhập dữ liệu loại CDate. 

6. Hãy định nghĩa lớp CString biểu diễn khái niệm chuỗi ký tự với các phương thức thiết lập, huỷ bỏ, các hàm thành phần và các phép toán cần thiết (+, gán, so sánh hai chuỗi).

7. Định nghĩa lớp biểu diễn khái niệm đa thức có bậc bất kỳ với các hàm thành phần và phép toán cần thiết.

8. Định nghĩa lớp CVector biểu diễn khái niệm vector trong không gian có số chiều bất kỳ với các hàm thành phần và các phép toán cần thiết.
Định nghĩa lớp CMatrix biểu diễn khái niệm ma trận có kích thước bất kỳ với các hàm thành phần và các phép toán cần thiết.
Viết hàm tính tích của một ma trận và một vector. Tích của hai ma trận.

9. Hãy định nghĩa lớp INTEGER có thể hoạt động như để mỗi INTEGER giống hệt như một 'int' của ngôn ngữ C/C++.

10. Hãy định nghĩa lớp MYINT có hoạt động như kiểu dữ liệu 'int' nhưng phép cộng hai MYINT hoạt động như phép trừ hai int và ngược lại.

11. Cho đoạn chương trình sau:
	#include <iostream.h>
	main(){	cout << "Hello, world.\n"; }
Hãy sửa lại chương trình trên, nhưng không sửa chữa gì hàm main, để chương trình có thể tạo ra kết xuất:
	Entering the Hello program saying...
	Hello, world.
	Then exiting...

