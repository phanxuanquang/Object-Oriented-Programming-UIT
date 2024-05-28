# Lập trình hướng đối tượng UIT - Tất cả bài thực hành
Tất cả bài thực hành môn lập trình hướng đối tượng - Trường Đại học Công nghệ Thông tin
____________________________
Bài làm chỉ mang tính chất tham khảo cho các bạn sinh viên khác. Ngoài ra, đây là môn học tiên quyết cho sự nghiệp phát triển phần mềm, do đó bắt buộc phải hiểu thật sâu và chắc hầu hết các tính chất lẫn khái niệm xuất hiện trong quá trình học môn này.
____________________________
Để học tốt môn này, tác giả khuyên các bạn cần chuẩn bị trước:
- Hiểu rõ cách triển khai một chương trình tổng quát đầy đủ các thành phần bằng ngôn ngữ C++.
- Nắm vững kiến thức về những kiểu dữ liệu cơ sở, mảng một chiều và kiến thức căn bản về con trỏ.
- Có thể định nghĩa kiểu dữ liệu mới bằng kiểu cấu trúc (struct).
____________________________
## Một số lưu ý về việc đặt tên cần nhớ:

- Hạn chế đặt tên theo ngôn ngữ sở tại (chẳng hạn như tiếng Việt), nên sử dụng tiếng Anh để tránh người khác đọc hiểu sai nghĩa. Ngoài ra, hãy đặt tên có nghĩa, không nên quá dài và tránh sử dụng những từ dễ bị nhầm lẫn hoặc đồng âm. Lưu ý rằng, viết tắt tên chính là một nghệ thuật và phải thực hiện đúng cách để tối ưu cho việc đọc hiểu.
Ví dụ: 
```console
string phoneNumber;
string phoneNum;
int naturalNumber;
```

- Tên biến và tên hàm nên viết theo dạng lạc đà (CamelCase) hoặc dạng rắn (snake_case). Ở đây, tác giả sử dụng dạng lạc đà. Ví dụ:
```console
string phoneNumber; 
string phoneNum;
int arraySize;
```
- Tên mảng được đặt theo tên phần tử của mảng ở dạng số nhiều. Quy tắt này được áp dụng trong lập trình hướng đối tượng hoặc với kiểu lập trình sử dụng struct.
Ví dụ: 
```js
Student students[100];
Dog asianDogs[100];
```

- Viết hoa chữ cái đầu mỗi từ trong tên class và struct.
Ví dụ:
```js
class Student {};
struct Dog {};
class AsianMan {};
```

- Đối với biến và hàm của kiều dữ liệu bool, hãy đặt tên để ngầm hiểu câu trả lời là Yes hoặc No.
Ví dụ:
```js
bool isVerified;
bool didHomework;
bool hasFiveDogs;
bool isValidAccount();
```

- Viết hoa tất cả các ký tự trong tên của hằng số và mỗi từ trong tên phân tách bởi dấu gạch chân.
Ví dụ: 
```js
const double PI = 3.14;
const int MAX_SIZE = 10000;
```

## Ngoài ra:
- Mỗi hàm chỉ thực hiện duy nhất một chức năng. Tuyệt đối không gộp chức năng tính toán logic và nhập/xuất vào một chung một hàm.

- Hàm main() chỉ được dùng để gọi hàm khác, khai báo những biến được nêu trong yêu cầu và gọi lệnh nhập/xuất cơ bản. Ngoài ra, tuyệt đối không thực hiện thêm chức năng nào khác.
____________________________
### Để tối ưu cho việc triển khai chương trình đa lựa chọn dạng menu, tác giả cung cấp cho các bạn một mẫu menu bên dưới.

```js
#include <iostream>
using namespace std;

class YourClass {
	int yourVariable;

public:
	void input();
};

void showMenu();
void handleChoiceFor(YourClass& yourObject);

int main() {
	YourClass yourObject;
	yourObject.input();

	handleChoiceFor(yourObject);
}

void YourClass::input() {
	cout << "Value of your variable is ";
	cin >> yourVariable;
}

void showMenu() {
	cout << "-----------------------------" << endl;
	cout << " (0) Exit." << endl;
	cout << " (1) Do something usefull." << endl;
	cout << " (2) Do something usefull." << endl;
	cout << " (3) Do something usefull." << endl;
	cout << "-----------------------------" << endl;
}
void handleChoiceFor(YourClass& yourObject) {
	showMenu();

	int choice;
	cout << "Your choice: ";
	cin >> choice;
	system("cls");

	switch (choice)
	{
	case 0:
		return;
	case 1:
		// Call the function for selection (1) only
		break;
	case 2:
		// Call the function for selection (2) only
		break;
	case 3:
		// Call the function for selection (3) only
		break;
	default:
		cout << "Invalid choice. Please try again!" << endl;
		break;
	}

	handleChoiceFor(yourObject);
}
```
