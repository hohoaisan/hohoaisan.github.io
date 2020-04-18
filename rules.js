let anchor = Date.now();
document.addEventListener('click', (event) => {
    if (event.srcElement.tagName == 'LI') {
        if (Date.now() - anchor >= 1000) {
            event.srcElement.classList.add('complete');
            event.srcElement.classList.remove('warning');
        } else {
            if (!event.srcElement.classList.contains('complete')) {
                event.srcElement.classList.add('warning');
            }
        }
        anchor = Date.now();
        if (document.querySelectorAll('.complete').length == 17) {
            setTimeout(()=>{
                if (prompt(
                    "Cảm ơn bạn đã đọc hết nội quy của group, sau đây là mã số để trả lời cho câu hỏi thứ nhất, mong bạn sẽ là một thành viên tích cực của group trong tương lai",
                    5211) == 5211) {
                console.log('OK');
                window.close();
            }
            },2000);
        }
    }
})