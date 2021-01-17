# Assignment C++
<h1>Các chức năng của bài Assignment</h1>

<ul>
    <li>Kiểm tra số nguyên</li>
    <li>Tìm ước chung lớn nhất và bội chung nhỏ nhất</li>
    <li>Tính tiền quán Karaoke đơn giản</li>
    <li>Tính tiền điện</li>
    <li>Tính lãi suất ngân hàng</li>
    <li>Quản lý sinh viên</li>
    <li>Tính phân số</li>
    <li>Đổi tiền</li>
    <li>Trò chơi xổ số Poly</li>
</ul>

<h1>Ý tưởng của từng chức năng</h1>
<h2>Kiểm tra số nguyên</h2>
<h3>Bao gồm:</h3>
<ul>
    <li>1: Kiểm tra số nhập vào có phải là số nguyên</li>
    <li>2: Kiểm tra số nguyên tố</li>
    <li>3: Kiểm tra số chính phương</li>
</ul>
<p>
    <h4><i>Ý tưởng: </i></h4>
    <strong>Chức năng 1:</strong><br/>
    <i>
    - Để kiểm tra số vừa nhập có phải là số nguyên, ta dựa vào phần thập phân của số thực. <br/>
    - Cụ thể, ta cho phép người dùng nhập vào một số thực (double hoặc float), ta tiến hành trừ số thực vừa nhập cho phần nguyên của chính nó. Ở đây mình sẽ ép kiểu để có phần nguyên của số thực đó.<br/>
    - Nếu kết quả bằng 0 thì là số nguyên.<br/>
    </i>
    <strong>Chức năng 2:</strong><br/>
    <i>
    - Để kiểm tra số nguyên tố, ta xét [2, căn bậc 2 của số đó] <br/>
    - Nếu có bất kỳ số nào là ước của số đã nhập thì không phải số nguyên tố <br/>
    </i>
    <strong>Chức năng 3:</strong><br/>
    <i>
    - Số chính phương là bình phương của 1 số tự nhiên. <br/>
    - Để xác định, ta sẽ nhân phần nguyên của căn bậc 2 số đó, nếu kết quả bằng số ban đầu thì là số chính phương. <br/>
    - Cụ thể ta ép kiểu (int)sqrt(number) * (int)sqrt(number).
    </i>
</p>

 
