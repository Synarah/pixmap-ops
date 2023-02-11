# pixmap-ops

Image manipulation demos based on the PPM image format.

TODO: Add a representative image for your project here
![earth-art](https://user-images.githubusercontent.com/112510953/218228412-fb075c8b-dc8a-4bb5-833a-d7018f5e72cf.png)

## How to build

*Windows*

Open git bash to the directory containing this repository.

```
pixmap-ops $ mkdir build
pixmap-ops $ cd build
pixmap-ops/build $ cmake -G "Visual Studio 17 2022" ..
pixmap-ops/build $ start pixmap-ops.sln
```

Your solution file should contain two projects: `pixmap_art` and `pixmap_test`.
To run from the git bash command shell, 

```
pixmap-ops/build $ ../bin/Debug/pixmap_test
pixmap-ops/build $ ../bin/Debug/pixmap_art
```

*macOS*

Open terminal to the directory containing this repository.

```
pixmap-ops $ mkdir build
pixmap-ops $ cd build
pixmap-ops/build $ cmake ..
pixmap-ops/build $ make
```

To run each program from build, you would type

```
pixmap-ops/build $ ../bin/pixmap_test
pixmap-ops/build $ ../bin/pixmap_art
```

## Image operators

TODO: Document the features of your PPM image class here. Include example images.
Flip Horizontal 
![earth-flip2](https://user-images.githubusercontent.com/112510953/218228515-324771c7-d1f9-4e27-863c-d43825a6b195.png)

Rotate 90
![earth-rot](https://user-images.githubusercontent.com/112510953/218228531-c3633519-4294-42d6-8e5d-515e800e14c4.png)

Blur
![earth-blu](https://user-images.githubusercontent.com/112510953/218228556-0976b2ad-70cf-436b-ae3a-e668d25e7f15.png)

Boarder
![earth-bord](https://user-images.githubusercontent.com/112510953/218228571-d3b1f809-053e-44be-a40d-fa42cfcd3520.png)

Invert
![earth-inv](https://user-images.githubusercontent.com/112510953/218228584-2f75eefa-2ece-4a3c-bd24-098e0dd9d29b.png)

Extract
![earth-ex](https://user-images.githubusercontent.com/112510953/218228594-86c7e0b0-7e25-4710-99c8-704e59d72db6.png)

Jitter
![earth-jit](https://user-images.githubusercontent.com/112510953/218228614-71d6b099-f6cd-48d2-9a58-ccde5f606b7f.png)

Swirl
![earth-sw](https://user-images.githubusercontent.com/112510953/218228624-34ebc775-63a8-4ca9-a173-7e00daad21e4.png)

## Results

TODO: Show artworks using your class
![earth-art](https://user-images.githubusercontent.com/112510953/218228637-a9804b30-549d-4285-ae02-64cdf7576a25.png)

