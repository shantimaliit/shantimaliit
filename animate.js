let isHidden = false;

function toggleAll() {
    const images = document.querySelectorAll('.image-container img');
    
    images.forEach(image => {
        image.style.display = isHidden ? 'block' : 'none';
    });
    
    isHidden = !isHidden;
}

function toggleImage(imageId) {
    const image = document.getElementById(imageId);
    
    if (image.style.display === 'none') {
        image.style.display = 'block';
    } else {
        image.style.display = 'none';
    }
}


