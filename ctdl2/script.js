
(function rolerowRandomColor() {
    function RandomColor() {
        return Math.ceil(Math.random() * 100 + Math.random() * 100 + Math.random() * 10 + Math.random() * 10)
    }
    color = RandomColor() + ',' + RandomColor() + ',' + RandomColor();
    rolerow = document.getElementsByClassName('role-row');
    for (i = 0; i < rolerow.length; i++) rolerow[i].style.backgroundColor = 'rgba(' + color + ',0.' + (i / 2 + 1) + ')'
})();

document.addEventListener('click', (event) => {
    if (event.srcElement.classList == 'imgbox') {
        pr = document.createElement('div');
        pr.setAttribute('id', 'imgview');
        ct = document.createElement('div');
        ct.setAttribute('id', 'imgview-ctn');
        a = document.createElement('a');
        a.innerText = 'X';
        a.setAttribute('id', 'imgview-a');
        i = document.createElement('img');
        i.setAttribute('src', event.srcElement.src);
        i.setAttribute('id', 'imgview-img');
        if (event.srcElement.parentNode.classList == 'preview-box') {
            i.setAttribute('class', 'scroll-able');
            ct.setAttribute('class', 'scroll-able');
        }
        pr.appendChild(a);
        ct.appendChild(i);
        pr.appendChild(ct);
        document.getElementsByTagName('body')[0].appendChild(pr);
        document.getElementsByTagName('body')[0].style.overflow = 'hidden';
    }
    if (event.srcElement.id == 'imgview-a' || event.srcElement.id == 'imgview-ctn') {
        event.srcElement.parentNode.parentNode.removeChild(event.srcElement.parentNode);
        document.getElementsByTagName('body')[0].style.overflow = 'auto';
    }

    if (event.srcElement.classList == 'sort') {
        event.preventDefault();
        ic = document.createElement('div');
        ic.setAttribute('id','iframe-test');
        i = document.createElement('iframe');
        i.setAttribute('src', event.srcElement.href);
        i.setAttribute('width','100%');
        i.setAttribute('id','ifm');
        ic.appendChild(i);
        document.getElementsByTagName('body')[0].appendChild(ic);
        document.getElementsByTagName('body')[0].style.overflow = 'hidden';
    }
    if (event.srcElement.id == 'iframe-test') {
        event.srcElement.parentNode.removeChild(event.srcElement);
        document.getElementsByTagName('body')[0].style.overflow = 'auto';
    }

});

// document.onkeyup = function (e) {
//     if (e.ctrlKey && e.which == 67)
//         alert("There was a bit difference between running code on the web and on DevC++, please download instead of copying");
// };


