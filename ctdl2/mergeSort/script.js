
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

});