# Hướng dẫn đóng góp

Cảm ơn bạn đã muốn đóng góp! Mọi thay đổi đều đi qua Pull Request vào nhánh `main`. Sau khi được merge, website tự động cập nhật trong khoảng 1 phút.

## Quy trình

1. Fork repo và clone về máy.
2. Tạo nhánh mới, ví dụ `git checkout -b fix-bth6-bai-3`.
3. Sửa file (xem bảng bên dưới).
4. Xem thử website trên máy bằng VS Code và extension [Live Server](https://marketplace.visualstudio.com/items?itemName=ritwickdey.LiveServer): mở **thư mục gốc của repo** (`File → Open Folder…`), chuột phải vào [`src/index.html`](src/index.html) rồi chọn **Open with Live Server**. Trang tự tải lại mỗi khi bạn lưu file.

   Lưu ý: luôn mở thư mục gốc, không mở riêng [`src/`](src/). Trang đọc đề bài và lời giải từ `../materials/`, nên nếu chỉ mở `src/` thì mọi bài sẽ báo "Không tải được nội dung".

5. Chạy [script kiểm tra](.github/check-labs.sh) ([GitHub Actions](.github/workflows/pages.yml) cũng chạy lại bước này trên Pull Request):

   ```bash
   bash .github/check-labs.sh
   ```

6. Commit, push và tạo Pull Request vào `main`.

## Sửa gì, ở đâu

| Muốn làm | Sửa file |
|---|---|
| Sửa đề bài | [`materials/<BTH>/README.md`](materials/) |
| Sửa lời giải | [`materials/<BTH>/0N.cpp`](materials/) |
| Sửa hướng dẫn học (trang chủ) | [`materials/GUIDE.md`](materials/GUIDE.md) |
| Thêm lời giải còn thiếu | Thêm [`materials/<BTH>/0N.cpp`](materials/), rồi thêm tên file vào `data-files` của thẻ `<li>` tương ứng trong [`src/index.html`](src/index.html) |
| Thêm bài thực hành mới | Xem mục [Thêm bài thực hành mới](#thêm-bài-thực-hành-mới) |
| Sửa giao diện | [`src/index.html`](src/index.html), [`src/assets/style.css`](src/assets/style.css), [`src/assets/app.js`](src/assets/app.js) |

## Thêm bài thực hành mới

Ví dụ thêm `BTH5`:

1. Tạo thư mục `BTH5/` trong [`materials/`](materials/) gồm `README.md` (đề bài) và các file lời giải `01.cpp`, `02.cpp`, …
2. Thêm một thẻ vào danh sách `#labs` trong [`src/index.html`](src/index.html), đúng thứ tự:

   ```html
   <li data-dir="BTH5" data-files="01.cpp 02.cpp">
   <a class="lab-card" href="?lab=bth5">
      <span class="eyebrow">Chủ đề</span>
      <h3>Bài thực hành 5</h3>
      <p>Mô tả ngắn.</p>
      <span class="meta">
         <span class="d-inline-flex align-items-center gap-1" data-bs-title="2 lời giải">
         <span class="material-symbols-rounded" aria-hidden="true">code</span>
         <span class="visually-hidden">Số lời giải:</span> 2 </span>
         <span class="material-symbols-rounded ms-auto" aria-hidden="true">arrow_forward</span>
      </span>
   </a>
   </li>
   ```

3. Thêm `<url><loc>https://phanxuanquang.github.io/Object-Oriented-Programming-UIT/?lab=bth5</loc></url>` vào [`src/sitemap.xml`](src/sitemap.xml).

`data-files` liệt kê **mọi** file trong thư mục của bài (trừ `README.md` gốc), kể cả file trong thư mục con như [`06/06.cpp`](materials/BTH7/06/06.cpp) hay [`06/Cow.wav`](materials/BTH7/06/Cow.wav). [Script kiểm tra](.github/check-labs.sh) sẽ báo lỗi nếu thiếu hoặc thừa.

## Quy ước viết đề bài

Website tự ghép đề bài thứ N với file `0N.cpp`, nên `README.md` của mỗi bài thực hành cần:

- Chỉ gồm **một danh sách đánh số** `1.`, `2.`, … Không có tiêu đề hay đoạn văn nằm ngoài danh sách.
- Nội dung phụ của một đề (ví dụ, danh sách con, code mẫu) phải **thụt lề vào trong** mục của đề đó (3 khoảng trắng với `1.`–`9.`, 4 khoảng trắng từ `10.`).
- Tên lớp, toán tử, công thức đặt trong `inline code`; code mẫu đặt trong khối ` ```cpp `.

Nếu không theo được quy ước trên (ví dụ đề có phần giới thiệu chung), website sẽ hiển thị dạng "Đề bài" và "Lời giải" như [`BTH7`](materials/BTH7/README.md).

## Quy ước viết code

Xem phần **Quy ước đặt tên** và **Tổ chức hàm** trong [`materials/GUIDE.md`](materials/GUIDE.md). Lưu file ở dạng UTF-8.
