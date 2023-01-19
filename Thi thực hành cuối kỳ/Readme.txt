Xây dựng 2 lớp CCVinHome và CCBcon được kế thừa từ lớp ChungCu.
Biết rằng ChungCu bao gồm các thuộc tính như sau:
Tên chung cư (ten), 
Số tầng (soTang), 
Diện tích chung cư (dienTich), 
Tên người quản lý (tenQL), 
Tên đại diện sở hữu (soHuu)
Lớp CCVinHome thì tên đại diện người sở hữu sẽ là “Vinhomes”. Lớp CCBcon thì tên đại diện người sở hữu sẽ là “Bcons”. Vào cuối tuần tất cả các quản lý tòa nhà đề phải gửi phiếu thông báo về tình trạng tòa nhà cho ban quản lý chung cư khu vực (guiThongBao), tiêu đề của thông báo là: “Tên người quản lý – Tên chung cư – Tên đại diện sở hữu”. Ví dụ: “Nguyễn Văn A – Chung cư UITer – Vinhomes”.
	Áp dụng kế thừa, đa hình xây dựng chương trình với các lớp phù hợp. Cho phép ban
quản lý chung cư khu vực nhập vào số lượng chung cư Vinhomes và Bcons.
	Ban quản lý chung cư khu vực Làng Đại Học (khu vực chỉ có chung cư Vinhomes và Bcons) vào cuối tuần sẽ nhận được thông báo về tình trạng của các chung cư. Danh sách các tiêu đề mà ban quản lý chung cư cuối tuần nhận được sẽ là?
Ví dụ: Có 2 chung cư: 1 chung cư Vinhomes và 1 chung cư Bcons.
“Nguyễn Văn A – Chung cư UITer – Vinhomes
Nguyễn Văn B – Chung cư USSHer – Bcons”
	Tất cả các chung cư trong Làng Đại Học đều là chung cư cho thuê (sẽ phải trả tiền phòng mỗi tháng). Mỗi tầng của một chung cư đều có 6 phòng diện tích bằng nhau. Tiền thuê phòng mỗi tháng của các phòng được tính dựa theo diện tích của chung cư và đại diện sở hữu chung cư. Vậy số tiền mỗi tháng ban quản lý chung cư Làng Đại Học thu về sẽ là bao nhiêu? Biết rằng:
	Vinhomes:
	Diện tích > 600 m^2 : 10 – 15 triệu / phòng
	Diện tích <= 600 m^2: 6 – 10 triệu / phòng
	Bcons: 
	Diện tích > 600 m^2 : 8 – 12 triệu / phòng
	Diện tích <= 600 m^2: 5 – 8 triệu / phòng
Lưu ý: Tiền thuê phòng của các phòng thuộc một chung cư sẽ là như nhau. Ví dụ: Chung cư Vinhomes có 12 tầng, diện tích 700 m^2 thì số tiền thuê phòng của chung cư đó sẽ là: tienPhong(): 
random(10 → 15) * 12 *6
