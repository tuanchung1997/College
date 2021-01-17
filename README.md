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
<div>
    <h2>Kiểm tra số nguyên</h2>
    <h3>Bao gồm:</h3>
    <ul>
        <li>1: Kiểm tra số nhập vào có phải là số nguyên</li>
        <li>2: Kiểm tra số nguyên tố</li>
        <li>3: Kiểm tra số chính phương</li>
    </ul>
    <h3>Ý tưởng:</h3>
    <p>    
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
</div>

<div>
    <h2>Tìm ước chung lớn nhất và bội chung nhỏ nhất</h2>
    <h3>Ý tưởng:</h3>
    <p>
        <strong>Ước chung lớn nhất (GCD)</strong><br/>
        <i>
            - Giải thuật: Euclid <br/>
            - Ta có 2 số: Number1 và Number2 <br/>
            - Trả về Number2 nếu r (phần dư của Number1 và Number2) bằng 0 <br/>
            - Gọi đệ quy: GCD(Number2, Number1 % Number2) <br/>
        </i>
        <strong>Bội chung nhỏ nhất (LCM)</strong><br/>
        <i>
            - Khi đã có ước chung lớn nhất <br/>
            - Ta áp dụng công thức: (Number1 * Number2)/GCD(Number1, Number2) <br/>
        </i>
    </p>
</div>

 
