(function () {
    'use strict';

    var backgroundInput = document.getElementById('background-input');
    var overlayInput = document.getElementById('overlay-input');
    var overlayPathInput = document.getElementById('overlay-path');
    var backgroundImg = document.getElementById('background');
    var overlayImg = document.getElementById('overlay');
    var overlayXInput = document.getElementById('overlay-x');
    var overlayYInput = document.getElementById('overlay-y');
    var thumbnails = document.querySelectorAll('.thumbnail-small img');

    backgroundInput.addEventListener('change', function () {
        previewImage(this.files[0], backgroundImg);
    }, false);

    overlayInput.addEventListener('change', function () {
        previewImage(this.files[0], overlayImg);
    }, false);

    overlayXInput.addEventListener('change', function () {
        overlayImg.style.left = parseInt(this.value) + 'px';
    }, false);

    overlayYInput.addEventListener('change', function () {
        overlayImg.style.top = parseInt(this.value) + 'px';
    }, false);

    for (var i = 0; i < thumbnails.length; i++) {
        thumbnails[i].addEventListener('click', function() {
            overlayImg.src = this.src;
            overlayInput.value = '';
            overlayPathInput.value = this.src;
        });
    }

    function previewImage(file, imgTag) {
        var reader = new FileReader();
        var imageType = /image.*/;

        if (!file.type.match(imageType))
            throw new Error('File must be an image');

        reader.onload = function (e) {
            imgTag.src = e.target.result;
            overlayXInput.value = 0;
            overlayYInput.value = 0;
        };
        reader.readAsDataURL(file);
    }
})();



    
