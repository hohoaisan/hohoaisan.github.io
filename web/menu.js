    //Điều khiển nút Menu, khi cửa sổ thay đổi thì nếu dropdown-content đang được xổ xuống thì phải tắt nó đi
    //Khi cửa sổ nhỏ hơn giới hạn wmaxsize thì lập tức xoá class container của div#navmenu để nút div#menu và div.right-menu nằm dàn ra sát màn hình
    var wmaxsize = 800;
    var menu = document.getElementById("menu")
    var x = document.getElementById("dropdown-content")
    if (window.innerWidth <= wmaxsize) {
        document.getElementById("navmenu").classList.remove("container");
        x.style.display = "none"
    }
    window.onresize = function dropdown_hide_onresize() {
        var w = window.innerWidth;
        if (w <= wmaxsize) {
            x.style.display = "none";
            document.getElementById("navmenu").classList.remove("container")
        } else {
            x.style.display = "block";
            document.getElementById("navmenu").classList.add("container")
        }
    };
    //Khi click vào một phần tử bất kì trong web, nếu phần tử đó có id là #menu hoặc class là menu-img thì dropdown-content sẽ được xổ xuống, nếu click lại chính nó hoặc click ra bên ngoài thì dropdown-content tắt đi
    document.onclick = function toggle_dropdown() {
        var w = window.innerWidth;
        a = window.event.srcElement.id;
        b = window.event.srcElement.className;
        if (w <= wmaxsize) {
            if (a === "menu" || b === "menu-img") {
                if (x.style.display === "none") {
                    x.style.display = "block";
                } else {
                    x.style.display = "none";
                }
            }
            else {
                x.style.display = "none";
            }
        }
    };