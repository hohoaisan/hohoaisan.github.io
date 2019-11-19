ic = document.getElementById('imgctn');
ic.addEventListener('wheel', (event)=> {
    event.preventDefault();
    console.log(event.deltaY);
    ic.scrollLeft+=event.deltaY*8;
})

document.addEventListener('click', (event)=> {
    if (event.srcElement.classList == 'imgbox')
    {
        pr = document.createElement('div');
        pr.setAttribute('id', 'imgview');
        a = document.createElement('a');
        a.innerText = 'X';
        a.setAttribute('id', 'imgview-a');
        i = document.createElement('img');
        i.setAttribute('src', event.srcElement.src);
        i.setAttribute('id', 'imgview-img');
        pr.appendChild(a);
        pr.appendChild(i);
        document.getElementsByTagName('body')[0].appendChild(pr);
    }
    if (event.srcElement.id == 'imgview-a')
    {
        event.srcElement.parentNode.parentNode.removeChild(event.srcElement.parentNode);
    }
})