ic = document.getElementById('imgctn');
ic.addEventListener('wheel', (event) => {
    event.preventDefault();
    ic.scrollLeft += event.deltaY * 8;
})

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

})

document.onkeyup = function (e) {
    if (e.ctrlKey && e.which == 67)
        alert("There was a bit difference between running code on the web and on DevC++, please download instead of copying");
};

function RandomColor() {
    return Math.ceil(Math.random() * 100 + Math.random() * 100 + Math.random() * 10 + Math.random() * 10)
}
color = RandomColor()+','+RandomColor()+','+RandomColor();
tablerow = document.getElementsByTagName('tr');
for (i = 0; i < tablerow.length; i++) tablerow[i].style.backgroundColor = 'rgba('+color+',0.'+(i/2+1)+')'