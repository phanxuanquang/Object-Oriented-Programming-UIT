1. Đặt tệp `Cow.wav`, `Goat.wav` và `Sheep.wav` vào cùng thư mục với tệp mã nguồn.
2. Trong Visual Studio, nhấp chuột phải vào project đang mở và chọn **Properties**.
3. Đi theo đường dẫn **Configuration Properties** → **Linker** → **Input**.
4. Bên phải mục **Additional Dependencies**, nhấp vào **&lt;Edit...&gt;** và điền `winmm.lib` vào.
5. Chọn **OK** và đợi 15 giây.
